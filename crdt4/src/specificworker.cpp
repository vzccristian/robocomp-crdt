/*
 *    Copyright (C)2018 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"
#include <Ice/Proxy.h>



/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx& mprx) : GenericWorker(mprx)
{

}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{

}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{
//     cout << "Params" << endl;
//     for (auto const& x : params)
//         cout << x.first << ':' << x.second.value << endl;

    endpoint = params["DSRD4sync.Endpoints"].value.substr(params["DSRD4sync.Endpoints"].value.size() - 5);
    proxy = params["DSRD4syncProxy"].value;
    id = params["id"].value;
    synchronized = false;

    srand (time(NULL));

    i = 0;
    max_nodes = rand() % MAX_RANDOM + MIN_RANDOM;
    nodes = aworset<DS>();
    nodes_uid.resize(max_nodes);
    cout <<"[ID:"<<id<<"]-> inicio:"<<i<<" maximo: "<<max_nodes<<endl;

    timer.start(Period);
    return true;
}

/*
 * Valores de inicio aleatorios.
 *
 */

void SpecificWorker::initValues()
{
    int j = 0;
    while (j < 5) {
        aworset<DS> aux0("uid-"+to_string(j));

        RoboCompDSRD4::DS ds;
        ds.id = id;
        ds.neighbors = vector<RoboCompDSRD4::NeighborsAttribs>();
        ds.rcvalue.value = rand() % 25000 + 10000;
        ds.crdt_data.uid = "uid-"+to_string(j);
        ds.crdt_data.cc = 0;
        ds.crdt_data.dc = 0;

        // Introducir para cambiar contexto random
        int veces = rand() % 5 + 1;
        for (int u=0; u<veces; u++)
            nodes.join(aux0.add(ds));
        j++;

        if (j == 5) {
            cout << "Nodes inicio: \n" << nodes << endl;
            cout << "------------------------" << endl;
        }
    }
}


/*
 * Inserción de datos
 *
 */
void SpecificWorker::newRandomValue(string uid) {
    aworset<DS> aux0(uid); // Creacion de aux
    std::vector<DS> dArray; // Array para enviar deltas

    RoboCompDSRD4::DS ds;
    ds.neighbors = vector<RoboCompDSRD4::NeighborsAttribs>(); // Para nodos vecinos
    NeighborsAttribs na;

    RoboCompDSRD4::Pair p;

    p.key="hola";
    p.value="adios";

    for(int j=0; j<5; j++) { // Ejemplo vecinos
        na.uid = "uid-"+to_string(j);
        na.neighbors_attribs.push_back(p);
        ds.neighbors.push_back(na); // Vecinos OK
    }

    ds.rcvalue.value = rand() % 25000 + 10000;  // "Valor" real
    ds.id = id;

    ds.crdt_data.uid = uid;
    ds.crdt_data.cc = 0;
    ds.crdt_data.dc = 0;  //CRDT Data OK. Solo para enviar.

    // Introducir para cambiar contexto random. TODO: PRODUCE ERRORES DE SEGMENTACION
    //     int veces = rand() % 10;
    //     cout << "NEW RANDOM VALUE: "<<ds<<endl;
    //     for (int u=0; u<veces; u++)
    //         nodes.join(aux0.add(ds));

    cout << "New value: " << ds << endl;
    nodes.join(aux0.add(ds)); // Insertar el dato

    // Preparar para enviar
    pair<int, int> indContext  = nodes.context().get(uid);
    ds.crdt_data.cc = indContext.first; // Asignacion de concepto antes de enviar
    ds.crdt_data.dc = indContext.second;

    dArray.push_back(ds);
    dsrd4_proxy->sendData(dArray); // Publicacion de datos

}



void SpecificWorker::compute()
{
    QMutexLocker locker(mutex);
    // Sync inicial
    if (!synchronized) {
        dsrd4_proxy->sendPortDSRD4(endpoint); // Publish my port for a sync
        while (!synchronized and i<5) {
            cout << ".."<<endl;
            i++;
            if (!synchronized)
                sleep(0.5);
        }
        if (i==5) {
            cout << "Asumo que soy el primero." << endl;
            synchronized = true;
            initValues();
            cout << "|| ---- Compute  ---- ||" << endl;
        }
    }

    if (i<MAX_RANDOM) {
        newRandomValue("uid-"+to_string(i*stoi(id)));
        i++;
    } else {
        cout <<"NODES: \n"<< nodes << endl;
        ofstream myfile;
        myfile.open ("nodes-"+id+".txt", std::ofstream::out | std::ofstream::trunc);
        myfile << nodes;
        myfile.close();
        sleep(2);
    }
}

/*
 * Callback para sincronización inicial
 */

bool SpecificWorker::sendSync(const string &name, const Delta &d)
{
    cout << "<-------------- Somebody is writting initial sync... (" << name <<")"<< endl;
    cout << "Data: "<< d << endl;
    for (auto const& x : d) {
        if (x.id != id) { // Omito mis propios datos
            aworset<DS> aworsetAux (x.crdt_data.uid); //Create node
            RoboCompDSRD4::DS aux = (RoboCompDSRD4::DS) x; //Delta to RoboCompDSRD3
            aworsetAux.add(aux); // Insertar 1 vez. Contexto vacio.
            aworsetAux.context().setContext(aux.crdt_data.uid, aux.crdt_data.cc-1, aux.crdt_data.dc-1); // Insertar con contexto anterior
            aworsetAux.add(aux); // Volver a insertar para actualizar datos completos
//             cout << "Anado a aworset:"<< aworsetAux << endl;
            nodes.join(aworsetAux); // Join delta
        }
    }
    synchronized = true;
    cout << "Sync nodes " << nodes << endl;
    return synchronized;
}


/*
 * Topic para deltas
 *
 */

void SpecificWorker::sendData(const Delta &d)
{
    for (auto& x : d) {
        aworset<DS> aworsetAux (x.crdt_data.uid); //Create node
        RoboCompDSRD4::DS aux = (RoboCompDSRD4::DS) x; //Delta to RoboCompDSRD3

        aworsetAux.add(aux);
        aworsetAux.context().setContext(aux.crdt_data.uid, aux.crdt_data.cc-1, aux.crdt_data.dc-1);
        aworsetAux.add(aux);
       
// Iteracion        
//         auto it = std::next(aworsetAux.read().begin(), 0);
//         cout << *it << endl;
//         nodes.add(*it);
//             cout << "RECV-VALUE: "<<aux<<endl;
        
        aworsetAux.add(aux);
        nodes.join(aworsetAux);
    }
}


/*
 *  Interfaz para indicar el puerto donde se implementa el callback
 */

void SpecificWorker::sendPortDSRD4(const string &port)
{
    if (endpoint != port) {
        cout << "--------------> Somebody ("<<port<<") needs initial sync.("<<proxy<<")"<<endl;
        string aux = proxy.replace(proxy.end()-5, proxy.end(), port);
        cout << aux << endl;
        DSRD4syncPrx p = DSRD4syncPrx::uncheckedCast(Ice::Application::communicator()->stringToProxy(aux)); // Hot proxy
        cout << "-----------------> proxy created to: "<<aux<<endl;
        std::vector<DS> array = getNodesArray();
        cout << "Sync now > "<<array<<endl;
        p->sendSync("comp"+id+"-"+port, array);
        cout << "Sync sent > "<<array<<endl;
    }
}

/*
 * Obtener nodos en formato array
 */
std::vector<DS> SpecificWorker::getNodesArray() {
    std::vector<DS> aux;
    for (auto x : nodes.read())  {
        pair<int, int> indContext = nodes.context().get(x.crdt_data.uid);
        x.crdt_data.cc = indContext.first;
        x.crdt_data.dc = indContext.second;
        aux.push_back(x);
    }
    return aux;
}


