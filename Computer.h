/*
* File: Computer.h
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the header of the Computer class.
* It represents the actual computer being infected.
*/

#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <list>
#include <string>
#include "Threat.h"

namespace McOfee {

	class Computer {

		public:
			// Maximum amount of Threats on a computer
			static const int ACTIVE_LIST_MAX_SIZE = 20;
			
        private:
			// Name of the current machine
			std::string computerName;
			
			// Threats currently infecting the computer
			std::list<Threat*> activeThreats;
		
		public:
			// Default constructor
			Computer();
			
			// Custom constructor
			Computer(const std::string name);
			
			// Destructor
			virtual ~Computer();
			
			// Add a Threat to the active list
			void addThreat(Threat*);
			
			// Return the current Threats
			std::list<Threat*> getThreatsList();
			
			// Return the number of current Threats
			int getNumberOfThreats();
			
            // Delete a Threat from the machine
			void deleteThreat(int);
            
            // Places a Threat in the quarantine folder
			void quarantineThreat(int);
            
            // Renames a Threat
			void renameThreat(int, std::string);
            
			// Removes the file related to its Threat
			void removeFileThreat(int threatId, std::string type);
			
			// Puts the file Threat in Quarantine
			void quarantineFileThreat(int threatId, std::string type);
			
			// Renames file Threat
			void renameFileThreat(int threatId, std::string type, std::string newName);
		
	};
    
    inline // Why not?
    std::list<Threat*> Computer::getThreatsList() {
        return activeThreats;
    }
	
}
	
#endif // COMPUTER_H
