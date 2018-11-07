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

/**
       \brief
       @author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#define NUM_THREADS 100
#define MAX_IDS 500
#define MAX_RANDOM 2000
#define MIN_RANDOM 0


#include <genericworker.h>
#include <innermodel/innermodel.h>
#include "delta-crdts.cc"
#include <ctime>
#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// ICE includes
#include <Ice/Ice.h>
#include <IceStorm/IceStorm.h>
#include <Ice/Application.h>
#include <Ice/Communicator.h>


class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
	SpecificWorker(MapPrx& mprx);
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);

    
    void initValues();
    void newRandomValue(string uid);
    std::vector<DS> getNodesArray();
	bool sendSync(const string &name,const Delta &d);
	void sendData(const Delta &d);
	void sendPortDSRD4(const string &port);

public slots:
	void compute();

private:
	InnerModel *innerModel;
    int i, max_nodes;
    bool synchronized;
    string endpoint, proxy, id;
    aworset<DS> nodes;
    std::vector<string> nodes_uid;

};

#endif
