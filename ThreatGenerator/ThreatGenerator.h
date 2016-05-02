/*
* File: ThreatGenerator.h
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the header of the ThreatGenerator class,
* which will be responsible for infecting the computer.
*/

#ifndef THREAT_GENERATOR_H
#define THREAT_GENERATOR_H

#include <iostream>
#include <string>
#include <boost/thread.hpp>
#include "../Threat.h"
#include "../Computer.h"

namespace McOfee 
{

	class ThreatGenerator 
	{
			
        public: 
            // Number of the next Threat to be generated
            static int generationNumber;

            // Is the thread running?
            static bool running;
            
        private:
            // The computer to be infected
            Computer *computer;

            // The current thread generating threats
            boost::thread currentThread;
			
        public:
			// Custom constructor
			ThreatGenerator(Computer&);
			
			// Destructor
			~ThreatGenerator();
			
            // Generates a file for each Threat created
			void generateThreatAsFile(std::string threatType, int threatNumber);

			//Runs the main thread to generate Threats
			static void runThread(ThreatGenerator*);

			// Starts the simulation Computer's infection
			void simulateInfection();
            
           	// Stops the infection
			void stopInfection();
			
			// Sends random Threats to computer
			template<class T>
			void sendThreat(const T threat)
			{
				computer->addThreat(threat);
			}
	};
    
}

#endif // THREAT_GENERATOR_H
