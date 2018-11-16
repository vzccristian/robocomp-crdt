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

    if (DEBUGGER) {

        std::vector<DS> dArray1, dArray2, dArray3, dArray4;
        try
        {
            dsrd4send1_proxy->getData(dArray1);
            dsrd4send2_proxy->getData(dArray2);
            dsrd4send3_proxy->getData(dArray3);
            dsrd4send4_proxy->getData(dArray4);

            cout << "Checking..." <<dArray1.size()<<" items."<<endl;

            if (dArray1.size() != dArray2.size() || dArray1.size() != dArray3.size()
            || dArray1.size()!= dArray4.size()) {
                cout<<"No. Size error."<<endl;
                exit(1);
            }
            for(std::vector<int>::size_type i = 0; i != dArray1.size(); i++) {
                cout << dArray1[i] <<" "<<dArray2[i]<<" "<<dArray3[i]<<" "<<dArray4[i]<<endl;
                if (!
                    (dArray1[i] == dArray2[i]) &&
                    (dArray1[i] == dArray3[i]) &&
                    (dArray1[i] == dArray4[i]))
                    {
                        cout<<"No "<<i<<endl;
                        cout << dArray1[i] << endl;
                        cout << dArray2[i] << endl;
                        cout << dArray3[i] << endl;
                        cout << dArray4[i] << endl;
                        exit(1);
                    }
            }

            cout <<"Todo correcto.\n"<< endl;
            sleep(1);
            exit(0);

        }
        catch (const std::exception& ex){
            cout << ".."<<endl;
            sleep(3);
        }

    }
    else {
    //    if (actualJobs == MAX_JOBS) { // Time to check
    //        cout << "Checking..."<<endl;
    //        std::vector<DS> dArray1, dArray2, dArray3, dArray4;
    //        dsrd4send1_proxy->getData(dArray1);
    //        dsrd4send2_proxy->getData(dArray2);
    //        dsrd4send3_proxy->getData(dArray3);
    //        dsrd4send4_proxy->getData(dArray4);
    //
    //        for(std::vector<int>::size_type i = 0; i != dArray1.size(); i++) {
    //            if(dArray1[i] == dArray2[i])
    //                cout<<"ok ";
    //        }
    //        exit(0);
    //    } else
    //
    }

}


void SpecificWorker::finish(const string &name) {
    cout << name << " finished. " << endl;
    jobs[actualJobs] = name;
    actualJobs++;
}


