/*
* File: Simulation.h
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the header of the Simulation class,
* which controls the whole simulation of a computer being
* infected.
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <list>
#include "Computer.h"
#include "MySQLLogger/MySQLLogger.h"
#include "Python.h"
#include "ThreatGenerator/ThreatGenerator.h"

namespace McOfee {

	class Simulation {
        
        private:

           	// The computer being infected
			Computer* computer;
           
           	// The generator sending Threats
			ThreatGenerator* tg;
            
            // The MySQLLogger for actions performed on Threats
            MySQLLogger* logger;
            
        public:
           	// Default constructor 
			Simulation();

	   		// Copy constructor
			Simulation(const Simulation& sourceSim);

	   		// Assignment overloading
			Simulation& operator=(const Simulation& sourceSim);
          
           	// Destructor
			virtual ~Simulation();
           
           	// Starts the Simulation
			void start();

			// Stop the simulation
			void stop();
            
           	// Returns the Threats currently active
			PyObject* getThreatsList();
            
           	// Removes a Threat (and its file) from the computer
			void deleteThreat(int i);
            
           	// Puts a Threat file in quarantine and deletes from the list
			void quarantineThreat(int i);
            
           	// Renames a Threat file and deletes from the list
			void renameThreat(int i, std::string newName);
            
           	// Clears all the data stored in the MySQL database
           	void flushLogs();
	};
    
}

#endif // SIMULATION_H
