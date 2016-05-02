/*
* File: Simulation.cpp
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the implementation of the Simulation class,
* which controls the whole simulation of a computer being
* infected.
* 
* g++ -g3 -std=c++11 -I/usr/include/python2.7 -Wall Computer.cpp MySQLLogger/MySQLLogger.cpp ThreatGenerator/ThreatGenerator.cpp Threats/Virus.cpp Threats/TrojanHorse.cpp Threats/Rootkit.cpp Simulation.cpp testDemo.cpp -o Simulation -lpython2.7 -pthread -lboost_thread -lboost_system -lboost_filesystem -lboost_regex -lmysqlcppconn
*
* swig -c++ -python mcofee.i
*
* python setup.py build_ext --inplace
*/

#include <string>
#include "MySQLLogger/MySQLLogger.h"
#include "Simulation.h"
#include "Threats/Virus.h"
#include "Threats/TrojanHorse.h"
#include "Threats/Rootkit.h"

using namespace std;
using namespace McOfee;

Simulation::Simulation()
{
	cout << "Building Simulations... " << endl;

	computer = new Computer();
	tg = new ThreatGenerator(*computer);
        logger = new MySQLLogger();
}

Simulation::Simulation(const Simulation& sourceSim)
{	
	cout << "Overloaded copy constructor" << endl;

	// Check pointers are not null
	if(sourceSim.computer)
		computer = new Computer();
	if(sourceSim.tg)
		tg = new ThreatGenerator(*computer);
	if(sourceSim.logger)
		logger = new MySQLLogger();	
}

Simulation& Simulation::operator=(const Simulation& sourceSim)
{
	cout << "Assignment called" << endl;
	// Self assignment
	if(&sourceSim == this)
		return *this;

	computer = new Computer();
	return *this;
}

Simulation::~Simulation()
{
    // Clean heap allocated objects
    delete logger;
    delete tg;
    delete computer;
	cout << "Destroying simulation... " << endl;
}

void Simulation::start()
{
	cout << "Starting simulation..." << endl;
	if(tg)
		tg->simulateInfection();
}

void Simulation::stop()
{
	cout << "Stopping simulation..." << endl;
	if(tg)
		tg->stopInfection();
}

PyObject* Simulation::getThreatsList()
{
    // Python List
    PyObject *PList = PyList_New(0);

    if(computer)
    {
	    list<Threat*> list = computer->getThreatsList();
	    cout << "Size of list: " << list.size() << endl;
	    
	    // Fill the Python list
	    for(typename list<Threat*>::iterator it = list.begin(); it != list.end(); it++)
	    {	
	        PyList_Append(PList, Py_BuildValue("i:s", (*it)->getThreatId(),
	                        (*it)->printThreatAction().c_str()));	
	    }
	}
    
    // Returns Python list
    return PList;
}

void Simulation::deleteThreat(int i)
{
	cout << "ready to delete: " << i << endl;
	if(logger)
    	logger->addLog(i, "deleted");
	if(computer)
		computer->deleteThreat(i);
}

void Simulation::quarantineThreat(int i)
{
	cout << "ready to quarantine: " << i << endl;
	if(logger)
		logger->addLog(i, "quarantined");
    if(computer)
    	computer->quarantineThreat(i);
}

void Simulation::renameThreat(int i, string newName)
{
	if(logger)
		logger->addLog(i, "renamed by " + newName);
    if(computer)
    	computer->renameThreat(i, newName);
}

void Simulation::flushLogs()
{
    if(logger)
    {
    	logger->flushLogs();
    	cout << "Table has been cleared." << endl;
    }
}
