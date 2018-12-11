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
    synchronized = start = false;

    srand(time(NULL));

    i = reps = 0;

    nodes = ormap<string, aworset<DS>>("node");

    nodes_uid.resize(MAX_NODES); // Simulation
    cout << "[ID:" << id << "]-> inicio:" << i << " maximo: " << MAX_NODES << endl;


    return true;
}

/*
 * Init for QT5
 */
void SpecificWorker::initialize(int period) {
    std::cout << "---> Initialize worker" << std::endl;
//    connect(&timer, SIGNAL(valueChanged()), this, SLOT(draw()));
//    connect(this,SIGNAL(valueChanged(DS)), this,SLOT(draw(DS)));
    this->Period = period;
    timer.start(Period);

    scene.setSceneRect(0, 0, 5200, 5200);
    view.setScene(&scene);
    view.setParent(scrollArea);
    view.setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    view.fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    font.setPixelSize(200);
    font.setBold(false);
    font.setFamily("Calibri");

    qDebug() << __FILE__ << __FUNCTION__ << __cplusplus;

    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());
}

/*
 * COMPUTE
 *
 */
void SpecificWorker::compute() {
    QMutexLocker locker(mutex);

    // Sync inicial.
    if (!synchronized) {
        dsrd4_proxy->sendPortDSRD4(endpoint); // Publicar puerto para hacer sync. (Callback)
        while (!start and i < 5) {
            cout << "." << endl;
            i++;
            if (!start) sleep(1);
        }
        if (!start) cout << "I'm first." << endl;
        i = 0;
        synchronized = start = true;
    }

    // Simulacion.
    if (start) {
        if (i < MAX_NODES) {
            newRandomValue("uid-" + to_string(i)); // Modificaciones sobre el conjunto de datos.
            i++;
        } else if (i == MAX_NODES) {
            cout << "\nEnd lap: \n";
            i++;
            cout << "-----------> Nodos [i]:" << i << ". Vueltas [reps]:" << reps << endl;
        } else {
            if (reps < MAX_REPS) { // Nueva vuelta.
                reps++;
                i = 0;
            } else { // Componente ha finalizado.
                cout << "\n\n\n\nFile[" << id << "]... " << endl;
                cout << nodes << endl;

                // Checker
                try {
                    dsrd4recv_proxy->finish(id);
                } catch (const std::exception &ex) {
                    cout << "." << endl;
                }

                // Enviar a archivo.

//              myfile.open("nodes-" + id + ".txt", std::ofstream::out | std::ofstream::trunc);
//              myfile << nodes  << endl;
//              myfile.close();

                sleep(5);
            }
        };
    }
}

/*
 * Inserción de datos
 */
void SpecificWorker::newRandomValue(string uid) {
    std::vector<DS> dArray; // Array para enviar deltas

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

    ds.rcvalue.value = rand() % 1200 + 300;  // "Valor" real
    ds.id = id; //Owner

    ds.crdt_data.uid = uid;
    ds.crdt_data.cc = 0;
    ds.crdt_data.dc = 0;  //CRDT Data OK. Solo para enviar.

    // Introducir para cambiar contexto random. TODO: PRODUCE ERRORES DE SEGMENTACION
    //     int veces = rand() % 10;
    //     cout << "NEW RANDOM VALUE: "<<ds<<endl;
    //     for (int u=0; u<veces; u++)
    //         nodes.join(aux0.add(ds));


    auto contx = nodes.context().get(uid);
    if (!contx.empty()) {
        ds.crdt_data.cc = contx.back().first;
        ds.crdt_data.dc = contx.back().second;
    }

//    cout << ", Estoy creando " << ds << " con cc: " << contx.back().first;

    // No inserto de forma local. Solo modifico a través del topic de publicación.
    dArray.push_back(ds);
    dsrd4_proxy->sendData(dArray); // Publicacion de datos
    usleep(std::stoi(id) * 20); // Latencia en función del ID.
}


// TODO: Draw data.
void SpecificWorker::draw(const DS &ds) {
    // Atributos
    string uid = ds.crdt_data.uid;
    uid = uid.erase(0, 4);
    Graph::Attribs atts;
    int posx = (std::stoi(uid) * 700 % 4000) + 100;
    int posy = (std::stoi(uid) * 700 / 4000) * 400 + 100;
    atts.insert(std::pair("posx", (double) posx));
    atts.insert(std::pair("posy", (double) posy));
    cout << graph.size() << " x->" << posx << " y->" << posy << endl;

    // Insertar
    atts.insert(std::pair("color", "red"));
    graph.addNodeAttribs(graph.size(), atts);

    // Pintar
    QPainterPath path;
    path.addText(posx + 100, posy + 300, font, QString::fromStdString(ds.crdt_data.uid));
    scene.addEllipse(posx, posy, 650, 400, QPen(Qt::magenta), QBrush(Qt::magenta));
    scene.addPath(path, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
    view.show();
}


/*
 * Obtener nodos en formato array
 */
std::vector<DS> SpecificWorker::getNodesArray() {
    std::vector<DS> aux;
    auto map = nodes.getFullOrMap();
    auto context = map.second.second;
    for (auto x : map.second.first) {
        for (auto y : x.second.readAsList()) {
            auto listContext = context.get();
            y.second.crdt_data.cc = listContext.first.front().second;
            y.second.crdt_data.dc = listContext.second.front().second;
            y.second.crdt_data.dc = 0;
            aux.push_back(y.second);
        }
    }
    return aux;
}


/*
 * Callback para sincronización inicial
 */
bool SpecificWorker::sendSync(const string &name, const Delta &d) {
    cout << "<-- sendSync (trying sync)" << name << endl;
    if (!synchronized) {
        synchronized = true;
        cout << "<-------------- Somebody is writting initial sync... (" << name << ")" << endl;
        aworset<DS> delta;
        for (auto const &x : d) {
            auto contx = nodes.context().get(x.crdt_data.uid);
            if (!contx.empty()) {
                if (contx.back().first <= x.crdt_data.cc) {
                    nodes[x.crdt_data.uid].add(x, x.crdt_data.uid);
//                cout << "---------------------> LLEGA BIEN. [CC:"<<x.crdt_data.cc<<"]. CC_actual: "<<contx.back().first<<" valido. "<< x << endl;
                } else
                    cout << "---------------------> LLEGA TARDE. [CC:" << x.crdt_data.cc << "]. CC_actual: "
                         << contx.back().first << ". " << x << endl;
            } else
                nodes[x.crdt_data.uid].add(x, x.crdt_data.uid);
        }
        cout << nodes << endl;
        cout << "<-------------- Sync nodes completed " << endl;
        start = true; // Ahora puede empezar.
    }
    return synchronized;
}


/*
 * Topic para deltas
 */
void SpecificWorker::sendData(const Delta &d) {


    //TODO: Mejorar.

    if (!start) { // Si me publican antes de comenzar, debo de esperar por la sync.
        usleep(500);
        cout << "sendData esperando..." << endl;
    } else {
        for (auto &x : d) {
            auto contx = nodes.context().get(x.crdt_data.uid);
            cout << "Recv: " << x << endl;
            if (!contx.empty()) {
                if (contx.back().first <= x.crdt_data.cc) {
                    nodes[x.crdt_data.uid].add(x, x.crdt_data.uid);
//                cout << "---------------------> LLEGA BIEN. [CC:"<<x.crdt_data.cc<<"]. CC_actual: "<<contx.back().first<<" valido. "<< x << endl;
                } else
                    cout << "---------------------> LLEGA TARDE. [CC:" << x.crdt_data.cc << "]. CC_actual: "
                         << contx.back().first << ". " << x << endl;
            } else
                nodes[x.crdt_data.uid].add(x, x.crdt_data.uid);

// TODO:
////            emit draw(aux);


        }
    }
}

/*
 *  Interfaz para indicar el puerto donde se implementa el callback
 */
void SpecificWorker::sendPortDSRD4(const string &port) {
    if (endpoint != port) {
        start = false;
        cout << "--------------> Somebody (" << port << ") needs initial sync." << endl;
        string aux = proxy.replace(proxy.end() - 5, proxy.end(), port);
        DSRD4syncPrx p = DSRD4syncPrx::uncheckedCast(Ice::Application::communicator()->stringToProxy(aux)); // Hot proxy
        cout << "-----------------> proxy created to: " << aux << endl;
        p->sendSync("comp" + id + "-" + port, getNodesArray());
        sleep(3);
        start = true;
    }
}

//TODO:
void SpecificWorker::getData(Delta &d, DSContext &dscontext) {
    d = getNodesArray();
    vector<RoboCompDSRD4::CRDTData> crdtData = vector<RoboCompDSRD4::CRDTData>();
    pair<map<string, int>, set<pair<string, int>>> contexto = nodes.context().getCcDc();
    for (const auto &cc : contexto.first) {
        RoboCompDSRD4::CRDTData auxCrdtData;
        auxCrdtData.uid = cc.first;
        auxCrdtData.cc = cc.second;
        for (const auto &dc : contexto.second)
            if (dc.first == cc.first) {
                auxCrdtData.dc = dc.second;
            }
        crdtData.push_back(auxCrdtData);
    }
    dscontext = crdtData;
}