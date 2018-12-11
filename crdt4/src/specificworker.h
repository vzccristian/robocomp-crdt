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

#define MAX_NODES 100
#define MAX_REPS 100
#include <unistd.h>


#include <genericworker.h>
#include <innermodel/innermodel.h>
#include "delta-crdts.cc"
#include "Graph.h"
#include <unistd.h>
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

    void newRandomValue(string uid);
    std::vector<DS> getNodesArray();

	bool sendSync(const string &name,const Delta &d);
    void getData(Delta &d, DSContext &dscontext);
	void sendData(const Delta &d);
	void sendPortDSRD4(const string &port);
//    void draw(const DS &ds);


public slots:
	void compute();
    void initialize(int period);
    void draw(const DS &ds);

signals:
    void valueChanged(const DS &ds);

private:
	InnerModel *innerModel;


	// Data
    int i, reps;
    bool synchronized, start;
    string endpoint, proxy, id;
    ormap<string,aworset<DS>> nodes;
	ofstream myfile;
    std::vector<string> nodes_uid;

    // Graph
	QGraphicsScene scene;
	QGraphicsView view;
	QGraphicsEllipseItem *node;
	QFont font;
	Graph graph;
};

#endif
