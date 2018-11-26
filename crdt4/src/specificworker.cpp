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
#include "DSRD4.h"
#include <Ice/Proxy.h>


/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx &mprx) : GenericWorker(mprx) {
    std::cout << "---> Init SpecificWorker" << std::endl;
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker() {
    std::cout << "---> Destroying SpecificWorker" << std::endl;
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params) {
//     cout << "Params" << endl;
//     for (auto const& x : params)
//         cout << x.first << ':' << x.second.value << endl;

    endpoint = params["DSRD4sync.Endpoints"].value.substr(params["DSRD4sync.Endpoints"].value.size() - 5);
    proxy = params["DSRD4syncProxy"].value;
    id = params["id"].value;
    synchronized = false;

    srand(time(NULL));

    i = 0;
    max_nodes = rand() % MAX_RANDOM + MIN_RANDOM;

    nodes = aworset<DS>("nodes");
    nodes_uid.resize(max_nodes);
    cout << "[ID:" << id << "]-> inicio:" << i << " maximo: " << max_nodes << endl;


    return true;
}

/*
 * Init for QT5
 */
void SpecificWorker::initialize(int period)
{
    std::cout << "---> Initialize worker" << std::endl;
    this->Period = period;
    timer.start(Period);

    scene.setSceneRect(0, 0, 5200, 5200);
    view.setScene(&scene);
    //view.scale(1, -1);
    view.setParent(scrollArea);
    view.setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    view.fitInView(scene.sceneRect(), Qt::KeepAspectRatio );
    font.setPixelSize(200);
    font.setBold(false);
    font.setFamily("Calibri");

    qDebug() << __FILE__ << __FUNCTION__ << __cplusplus;

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

}

/*
 * COMPUTE
 *
 */
void SpecificWorker::compute() {
    QMutexLocker locker(mutex);
    // Sync inicial
    if (!synchronized) {
        dsrd4_proxy->sendPortDSRD4(endpoint); // Publish my port for a sync
        while (!synchronized and i < 3) {
            cout << "." << endl;
            i++;
            if (!synchronized)
                sleep(1);
        }
        synchronized = true;
    }

    // Simulation
    if (i < MAX_RANDOM) {
        newRandomValue("uid-" + to_string(i * stoi(id)));
        i++;
    } else if (i == MAX_RANDOM) {
        cout << "END->NODES: \n" << nodes << endl;
        try {
            dsrd4recv_proxy->finish(id);
            i++;
        } catch (const std::exception& ex){
            cout << ".."<<endl;
            sleep(3);
        }
        cout << "END " << i << " " << endl;
    } else {
        myfile.open("nodes-" + id + ".txt", std::ofstream::out | std::ofstream::trunc);
        myfile << nodes;
        myfile.close();
    }
}

/*
 * Inserción de datos
 */
void SpecificWorker::newRandomValue(string uid) {
    aworset<DS> aux0(uid); // Creacion de aux
    std::vector<DS> dArray; // Array para enviar deltas
    aworset<DS> delta;
    RoboCompDSRD4::DS ds;
    ds.neighbors = vector<RoboCompDSRD4::NeighborsAttribs>(); // Para nodos vecinos
    NeighborsAttribs na;

    RoboCompDSRD4::Pair p;

    p.key = "hola";
    p.value = "adios";

    for (int j = 0; j < 5; j++) { // Ejemplo vecinos
        na.uid = "uid-" + to_string(j);
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


    try {
        delta = aux0.add(ds);
        pair<DS, pair<int, int>> n = nodes.getNodes(uid); // For context
        if(n.second.first>0 || n.second.second > 0)
        {
            aux0.context().setContext(uid, n.second.first, n.second.second);
            delta = aux0.add(ds);
        }
        cout << "New value: " << aux0 << endl;

        nodes.join(delta); // Insertar el dato
    } catch (exception e) {
        cout << "Error" << endl;
    }

    draw(ds);
    // Preparar para enviar
    list<pair<int, int>> indContext = nodes.context().get(uid);
    ds.crdt_data.cc = indContext.back().first; // Asignacion de concepto antes de enviar
    ds.crdt_data.dc = indContext.back().second;
    dArray.push_back(ds);
    dsrd4_proxy->sendData(dArray); // Publicacion de datos

}


void SpecificWorker::draw(const DS &ds) {
    // Atributos
    string uid = ds.crdt_data.uid;
    uid = uid.erase(0,4);
    Graph::Attribs atts;
    int posx = (std::stoi(uid)*700 % 4000) + 100;
    int posy = (std::stoi(uid)*700 / 4000) * 400 + 100;
    atts.insert(std::pair("posx",(double) posx));
    atts.insert(std::pair("posy",(double) posy));
    cout <<graph.size()<<" x->" <<posx<<" y->" <<posy<< endl;

    // Insertar
    atts.insert(std::pair("color", "red"));
    graph.addNodeAttribs(graph.size(), atts);

    // Pintar
    QPainterPath path;
    path.addText(posx+100, posy+300, font,  QString::fromStdString( ds.crdt_data.uid));
    scene.addEllipse(posx,posy, 700, 400, QPen(Qt::magenta), QBrush(Qt::magenta));
    scene.addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
    view.show();
}


/*
 * Obtener nodos en formato array
 */
std::vector<DS> SpecificWorker::getNodesArray() {
    std::vector<DS> aux;
    list<pair<int, int>> indContext;
    for (auto x : nodes.readAsList()) {
        indContext = nodes.context().get(x.second.crdt_data.uid);
        x.second.crdt_data.cc = x.first;
        x.second.crdt_data.dc = indContext.back().second; //TODO. Check
        aux.push_back(x.second);
    }
    return aux;
}

/*
 * Callback para sincronización inicial
 */
bool SpecificWorker::sendSync(const string &name, const Delta &d) {
    if (!synchronized) {
        cout << "<-------------- Somebody is writting initial sync... (" << name << ")" << endl;
        aworset<DS> delta;
        for (auto const &x : d) {
            if (x.id != id) { // Omito mis propios datos
                aworset<DS> aworsetAux(x.crdt_data.uid); //Create node
                RoboCompDSRD4::DS aux = (RoboCompDSRD4::DS) x; //Delta to RoboCompDSRD3
                delta = aworsetAux.add(aux);
                if (x.crdt_data.cc-1 > 0)
                {
                    aworsetAux.context().setContext(x.crdt_data.uid, x.crdt_data.cc-1, x.crdt_data.dc-1);
                    delta = aworsetAux.add(aux);
                }
//                cout <<" --> Anado a aworset:"<< aworsetAux << endl;
                nodes.join(delta);
            }
        }
//        cout << nodes << endl;
        cout << "<-------------- Sync nodes completed " << endl;
        synchronized = true;
    }
    return synchronized;
}


/*
 * Topic para deltas
 */
void SpecificWorker::sendData(const Delta &d) {
    for (auto &x : d) {
        if (x.id != id) {
            aworset<DS> aworsetAux(x.crdt_data.uid); //Create node
            aworset<DS> delta;
            RoboCompDSRD4::DS aux = (RoboCompDSRD4::DS) x; //Delta to RoboCompDSRD3

            delta = aworsetAux.add(aux);
            if (aux.crdt_data.cc-1 > 0)
            {
                aworsetAux.context().setContext(x.crdt_data.uid, x.crdt_data.cc-1, x.crdt_data.dc-1);
                delta = aworsetAux.add(aux);
            }
//            cout <<" --> Anado a aworset:"<< aworsetAux << endl;
            nodes.join(delta);
        }
    }
}

/*
 *  Interfaz para indicar el puerto donde se implementa el callback
 */
void SpecificWorker::sendPortDSRD4(const string &port) {
    if (endpoint != port) {
        cout << "--------------> Somebody (" << port << ") needs initial sync.(" << proxy << ")" << endl;
        string aux = proxy.replace(proxy.end() - 5, proxy.end(), port);
        cout << aux << endl;
        DSRD4syncPrx p = DSRD4syncPrx::uncheckedCast(Ice::Application::communicator()->stringToProxy(aux)); // Hot proxy
        cout << "-----------------> proxy created to: " << aux << endl;
//        cout << nodes << endl;
        std::vector<DS> array = getNodesArray();
        p->sendSync("comp" + id + "-" + port, array);
//        cout << "Sync sent > "<<array.size()<<"> "<<array<<endl;
    }
}


void SpecificWorker::getData(Delta &d, DSContext &dscontext) {
    d = getNodesArray();
    vector<RoboCompDSRD4::CRDTData> crdtData = vector<RoboCompDSRD4::CRDTData>();
    pair<map<string,int>, set<pair<string,int>>> contexto = nodes.context().getCcDc();
    for (const auto & cc : contexto.first)
    {

        RoboCompDSRD4::CRDTData auxCrdtData;
        auxCrdtData.uid = cc.first;
        auxCrdtData.cc = cc.second;
        for (const auto & dc : contexto.second)
            if (dc.first == cc.first)
            {
                auxCrdtData.dc = dc.second;
                break;
            }
        crdtData.push_back(auxCrdtData);
    }
    dscontext = crdtData;
}