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

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx &mprx) : GenericWorker(mprx) {

}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker() {

}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params) {
    timer.start(Period);
    return true;
}

void SpecificWorker::initialize(int period)
{
    std::cout << "Initialize worker" << std::endl;
    this->Period = period;
    timer.start(Period);
}

void SpecificWorker::check() {
    cout << "Getting data" <<endl;
    std::vector<DS> dArray1, dArray2, dArray3, dArray4;
    std::vector<CRDTData> context1, context2, context3, context4;
    try {
        dsrd4send1_proxy->getData(dArray1, context1);
        cout << "Componente 1"<<endl;
        dsrd4send2_proxy->getData(dArray2, context2);
        cout << "Componente 2"<<endl;
        dsrd4send3_proxy->getData(dArray3, context3);
        cout << "Componente 3"<<endl;
        dsrd4send4_proxy->getData(dArray4, context4);
        cout << "Componente 4"<<endl;

        cout << "\nChecking data..." << dArray1.size() << " " << dArray2.size() << " " << dArray3.size() << " "
             << dArray4.size() << " items." << endl;
        cout << "Checking context..." << context1.size() << " " << context2.size() << " " << context3.size() << " "
             << context4.size() << " items." << endl;

        if (dArray1.size() != dArray2.size() || dArray1.size() != dArray3.size()
            || dArray1.size() != dArray4.size()) {
            cout << "Size error." << endl;
            exit(1);
        } else
            cout << "Size OK." << endl;

        for (std::vector<int>::size_type i = 0; i != dArray1.size(); i++) {
            if (!(dArray1[i] == dArray2[i]) &&
                (dArray1[i] == dArray3[i]) &&
                (dArray1[i] == dArray4[i])) {
                cout << "Data doesn't match." << i << endl;
                cout << dArray1[i] << endl;
                cout << dArray2[i] << endl;
                cout << dArray3[i] << endl;
                cout << dArray4[i] << endl;
                exit(1);
            }
        }
        cout << "All right.\n" << endl;
        sleep(1);
        exit(0);

    }
    catch (const std::exception &ex) {
        cout << ".."<<ex.what() << endl;
        sleep(3);
    }
}

void SpecificWorker::compute() {
    QMutexLocker locker(mutex);
    check();
}
