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
    actualJobs = 0;
    timer.start(Period);
    same = true;
    return true;
}

void SpecificWorker::compute() {
    QMutexLocker locker(mutex);

    if (actualJobs == MAX_JOBS) { // Time to check
        cout << "Checking..."<<endl;
        std::vector<DS> dArray1, dArray2, dArray3, dArray4;
        dsrd4send1_proxy->getData(dArray1);
        dsrd4send2_proxy->getData(dArray2);
        dsrd4send3_proxy->getData(dArray3);
        dsrd4send4_proxy->getData(dArray4);
        cout << dArray1 << endl;
//        for(std::vector<int>::size_type i = 0; i != dArray1.size(); i++) {
//            if(dArray1[i] == dArray2[i])
//                cout<<"ok ";
//        }


        sleep(10);
    } else
        sleep(5);

}


void SpecificWorker::finish(const string &name) {
    cout << name << " finished. " << endl;
    jobs[actualJobs] = name;
    actualJobs++;
}


