/*
 *    Copyright (C) 2018 by YOUR NAME HERE
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


/** \mainpage RoboComp::crdt4
 *
 * \section intro_sec Introduction
 *
 * The crdt4 component...
 *
 * \section interface_sec Interface
 *
 * interface...
 *
 * \section install_sec Installation
 *
 * \subsection install1_ssec Software depencences
 * ...
 *
 * \subsection install2_ssec Compile and install
 * cd crdt4
 * <br>
 * cmake . && make
 * <br>
 * To install:
 * <br>
 * sudo make install
 *
 * \section guide_sec User guide
 *
 * \subsection config_ssec Configuration file
 *
 * <p>
 * The configuration file etc/config...
 * </p>
 *
 * \subsection execution_ssec Execution
 *
 * Just: "${PATH_TO_BINARY}/crdt4 --Ice.Config=${PATH_TO_CONFIG_FILE}"
 *
 * \subsection running_ssec Once running
 *
 * ...
 *
 */
#include <signal.h>

// QT includes
#include <QtCore>
#include <QtGui>

// ICE includes
#include <Ice/Ice.h>
#include <IceStorm/IceStorm.h>
#include <Ice/Application.h>

#include <rapplication/rapplication.h>
#include <sigwatch/sigwatch.h>
#include <qlog/qlog.h>

#include "config.h"
#include "genericmonitor.h"
#include "genericworker.h"
#include "specificworker.h"
#include "specificmonitor.h"
#include "commonbehaviorI.h"

#include <dsrd4syncI.h>
#include <dsrd4sendI.h>
#include <dsrd4I.h>

#include <DSRD4.h>


// User includes here

// Namespaces
using namespace std;
using namespace RoboCompCommonBehavior;

class crdt4 : public RoboComp::Application
{
public:
	crdt4 (QString prfx) { prefix = prfx.toStdString(); }
private:
	void initialize();
	std::string prefix;
	MapPrx mprx;

public:
	virtual int run(int, char*[]);
};

void ::crdt4::initialize()
{
	// Config file properties read example
	// configGetString( PROPERTY_NAME_1, property1_holder, PROPERTY_1_DEFAULT_VALUE );
	// configGetInt( PROPERTY_NAME_2, property1_holder, PROPERTY_2_DEFAULT_VALUE );
}

int ::crdt4::run(int argc, char* argv[])
{
#ifdef USE_QTGUI
	QApplication a(argc, argv);  // GUI application
#else
	QCoreApplication a(argc, argv);  // NON-GUI application
#endif


	sigset_t sigs;
	sigemptyset(&sigs);
	sigaddset(&sigs, SIGHUP);
	sigaddset(&sigs, SIGINT);
	sigaddset(&sigs, SIGTERM);
	sigprocmask(SIG_UNBLOCK, &sigs, 0);

	UnixSignalWatcher sigwatch;
	sigwatch.watchForSignal(SIGINT);
	sigwatch.watchForSignal(SIGTERM);
	QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &a, SLOT(quit()));

	int status=EXIT_SUCCESS;

	DSRD4recvPrx dsrd4recv_proxy;
	DSRD4syncPrx dsrd4sync_proxy;
	DSRD4Prx dsrd4_proxy;

	string proxy, tmp;
	initialize();


	try
	{
		if (not GenericMonitor::configGetString(communicator(), prefix, "DSRD4recvProxy", proxy, ""))
		{
			cout << "[" << PROGRAM_NAME << "]: Can't read configuration for proxy DSRD4recvProxy\n";
		}
		dsrd4recv_proxy = DSRD4recvPrx::uncheckedCast( communicator()->stringToProxy( proxy ) );
	}
	catch(const Ice::Exception& ex)
	{
		cout << "[" << PROGRAM_NAME << "]: Exception creating proxy DSRD4recv: " << ex;
		return EXIT_FAILURE;
	}
	rInfo("DSRD4recvProxy initialized Ok!");

	mprx["DSRD4recvProxy"] = (::IceProxy::Ice::Object*)(&dsrd4recv_proxy);//Remote server proxy creation example

	try
	{
		if (not GenericMonitor::configGetString(communicator(), prefix, "DSRD4syncProxy", proxy, ""))
		{
			cout << "[" << PROGRAM_NAME << "]: Can't read configuration for proxy DSRD4syncProxy\n";
		}
		dsrd4sync_proxy = DSRD4syncPrx::uncheckedCast( communicator()->stringToProxy( proxy ) );
	}
	catch(const Ice::Exception& ex)
	{
		cout << "[" << PROGRAM_NAME << "]: Exception creating proxy DSRD4sync: " << ex;
		return EXIT_FAILURE;
	}
	rInfo("DSRD4syncProxy initialized Ok!");

	mprx["DSRD4syncProxy"] = (::IceProxy::Ice::Object*)(&dsrd4sync_proxy);//Remote server proxy creation example
	IceStorm::TopicManagerPrx topicManager;
	try
	{
		topicManager = IceStorm::TopicManagerPrx::checkedCast(communicator()->propertyToProxy("TopicManager.Proxy"));
	}
	catch (const Ice::Exception &ex)
	{
		cout << "[" << PROGRAM_NAME << "]: Exception: STORM not running: " << ex << endl;
		return EXIT_FAILURE;
	}

	IceStorm::TopicPrx dsrd4_topic;
	while (!dsrd4_topic)
	{
		try
		{
			dsrd4_topic = topicManager->retrieve("DSRD4");
            cout << "[" << PROGRAM_NAME << "]: topic DRSD4 created" << endl;
		}
		catch (const IceStorm::NoSuchTopic&)
		{
			cout << "[" << PROGRAM_NAME << "]: ERROR retrieving DSRD4 topic. \n";
			try
			{
				dsrd4_topic = topicManager->create("DSRD4");
			}
			catch (const IceStorm::TopicExists&){
				// Another client created the topic.
				cout << "[" << PROGRAM_NAME << "]: ERROR publishing the DSRD4 topic. It's possible that other component have created\n";
			}
		}
	}
	Ice::ObjectPrx dsrd4_pub = dsrd4_topic->getPublisher()->ice_oneway();
	DSRD4Prx dsrd4 = DSRD4Prx::uncheckedCast(dsrd4_pub);
	mprx["DSRD4Pub"] = (::IceProxy::Ice::Object*)(&dsrd4);


	SpecificWorker *worker = new SpecificWorker(mprx);
	//Monitor thread
	SpecificMonitor *monitor = new SpecificMonitor(worker,communicator());
	QObject::connect(monitor, SIGNAL(kill()), &a, SLOT(quit()));
	QObject::connect(worker, SIGNAL(kill()), &a, SLOT(quit()));
	monitor->start();

	if ( !monitor->isRunning() )
		return status;

	while (!monitor->ready)
	{
		usleep(10000);
	}

	try
	{
		try {
			// Server adapter creation and publication
			if (not GenericMonitor::configGetString(communicator(), prefix, "CommonBehavior.Endpoints", tmp, "")) {
				cout << "[" << PROGRAM_NAME << "]: Can't read configuration for proxy CommonBehavior\n";
			}
			Ice::ObjectAdapterPtr adapterCommonBehavior = communicator()->createObjectAdapterWithEndpoints("commonbehavior", tmp);
			CommonBehaviorI *commonbehaviorI = new CommonBehaviorI(monitor);
			adapterCommonBehavior->add(commonbehaviorI, Ice::stringToIdentity("commonbehavior"));
			adapterCommonBehavior->activate();
		}
		catch(const Ice::Exception& ex)
		{
			status = EXIT_FAILURE;

			cout << "[" << PROGRAM_NAME << "]: Exception raised while creating CommonBehavior adapter: " << endl;
			cout << ex;

		}



		try
		{
			// Server adapter creation and publication
			if (not GenericMonitor::configGetString(communicator(), prefix, "DSRD4sync.Endpoints", tmp, ""))
			{
				cout << "[" << PROGRAM_NAME << "]: Can't read configuration for proxy DSRD4sync";
			}
			Ice::ObjectAdapterPtr adapterDSRD4sync = communicator()->createObjectAdapterWithEndpoints("DSRD4sync", tmp);
			DSRD4syncI *dsrd4sync = new DSRD4syncI(worker);
			adapterDSRD4sync->add(dsrd4sync, Ice::stringToIdentity("dsrd4sync"));
			adapterDSRD4sync->activate();
			cout << "[" << PROGRAM_NAME << "]: DSRD4sync adapter created in port " << tmp << endl;
			}
			catch (const IceStorm::TopicExists&){
				cout << "[" << PROGRAM_NAME << "]: ERROR creating or activating adapter for DSRD4sync\n";
			}


		try
		{
			// Server adapter creation and publication
			if (not GenericMonitor::configGetString(communicator(), prefix, "DSRD4send.Endpoints", tmp, ""))
			{
				cout << "[" << PROGRAM_NAME << "]: Can't read configuration for proxy DSRD4send";
			}
			Ice::ObjectAdapterPtr adapterDSRD4send = communicator()->createObjectAdapterWithEndpoints("DSRD4send", tmp);
			DSRD4sendI *dsrd4send = new DSRD4sendI(worker);
			adapterDSRD4send->add(dsrd4send, Ice::stringToIdentity("dsrd4send"));
			adapterDSRD4send->activate();
			cout << "[" << PROGRAM_NAME << "]: DSRD4send adapter created in port " << tmp << endl;
			}
			catch (const IceStorm::TopicExists&){
				cout << "[" << PROGRAM_NAME << "]: ERROR creating or activating adapter for DSRD4send\n";
			}



		// Server adapter creation and publication
		IceStorm::TopicPrx dsrd4_topic;
		Ice::ObjectPrx dsrd4;
		try
		{
			if (not GenericMonitor::configGetString(communicator(), prefix, "DSRD4Topic.Endpoints", tmp, ""))
			{
				cout << "[" << PROGRAM_NAME << "]: Can't read configuration for proxy DSRD4Proxy";
			}
			Ice::ObjectAdapterPtr DSRD4_adapter = communicator()->createObjectAdapterWithEndpoints("dsrd4", tmp);
			DSRD4Ptr dsrd4I_ = new DSRD4I(worker);
			Ice::ObjectPrx dsrd4 = DSRD4_adapter->addWithUUID(dsrd4I_)->ice_oneway();
			if(!dsrd4_topic)
			{
				try {
					dsrd4_topic = topicManager->create("DSRD4");
                    cout << "[" << PROGRAM_NAME << "]: topic DRSD4 created" << endl;
				}
				catch (const IceStorm::TopicExists&) {
					//Another client created the topic
					try{
						cout << "[" << PROGRAM_NAME << "]: Probably other client already opened the topic. Trying to connect.\n";
						dsrd4_topic = topicManager->retrieve("DSRD4");
					}
					catch(const IceStorm::NoSuchTopic&)
					{
						cout << "[" << PROGRAM_NAME << "]: Topic doesn't exists and couldn't be created.\n";
						//Error. Topic does not exist
					}
				}
				IceStorm::QoS qos;
				dsrd4_topic->subscribeAndGetPublisher(qos, dsrd4);
			}
			DSRD4_adapter->activate();
		}
		catch(const IceStorm::NoSuchTopic&)
		{
			cout << "[" << PROGRAM_NAME << "]: Error creating DSRD4 topic.\n";
			//Error. Topic does not exist
		}

		// Server adapter creation and publication
		cout << SERVER_FULL_NAME " started" << endl;

		// User defined QtGui elements ( main window, dialogs, etc )

		#ifdef USE_QTGUI
			//ignoreInterrupt(); // Uncomment if you want the component to ignore console SIGINT signal (ctrl+c).
			a.setQuitOnLastWindowClosed( true );
		#endif
		// Run QT Application Event Loop
		a.exec();

		try
		{
			std::cout << "Unsubscribing topic: dsrd4 " <<std::endl;
			dsrd4_topic->unsubscribe( dsrd4 );
		}
		catch(const Ice::Exception& ex)
		{
			std::cout << "ERROR Unsubscribing topic: dsrd4 " <<std::endl;
		}

		status = EXIT_SUCCESS;
	}
	catch(const Ice::Exception& ex)
	{
		status = EXIT_FAILURE;

		cout << "[" << PROGRAM_NAME << "]: Exception raised on main thread: " << endl;
		cout << ex;

	}
	#ifdef USE_QTGUI
		a.quit();
	#endif

	status = EXIT_SUCCESS;
	monitor->terminate();
	monitor->wait();
	delete worker;
	delete monitor;
	return status;
}

int main(int argc, char* argv[])
{
	string arg;

	// Set config file
	std::string configFile = "config";
	if (argc > 1)
	{
		std::string initIC("--Ice.Config=");
		size_t pos = std::string(argv[1]).find(initIC);
		if (pos == 0)
		{
			configFile = std::string(argv[1]+initIC.size());
		}
		else
		{
			configFile = std::string(argv[1]);
		}
	}

	// Search in argument list for --prefix= argument (if exist)
	QString prefix("");
	QString prfx = QString("--prefix=");
	for (int i = 2; i < argc; ++i)
	{
		arg = argv[i];
		if (arg.find(prfx.toStdString(), 0) == 0)
		{
			prefix = QString::fromStdString(arg).remove(0, prfx.size());
			if (prefix.size()>0)
				prefix += QString(".");
			printf("Configuration prefix: <%s>\n", prefix.toStdString().c_str());
		}
	}
	::crdt4 app(prefix);

	return app.main(argc, argv, configFile.c_str());
}
