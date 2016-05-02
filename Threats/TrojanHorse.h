/*
* File: Threats/TrojanHorse.h
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the header of the Trojan Horse class,
* which inherits from the Threat abstract class.
*/

#ifndef TROJAN_HORSE_H
#define TROJAN_HORSE_H

#include "../Threat.h"

namespace McOfee
{

	class TrojanHorse : public Threat 
	{
			
			// Folder to destroy
			std::string folderToDestroy;
			
		public:
		
			// Default constructor
			TrojanHorse();
			
			// Constructor
			TrojanHorse(int it, std::string type);
			
			// Destructor
			virtual ~TrojanHorse();
			
			// Returns the folder to be destroyed
			std::string getFolderToDestroy();
			
           	// Set the folder to be destroyed
			void setFolderToDestroy(std::string folder);
			
           	// Prints what the threat does
			std::string printThreatAction();
			
           	// Prints how dangerous a Threat is
			int printThreatLevel();
        
           	// Returns the id of the Threat
           	int getThreatId();
			
           	// Returns the name of the Threat
			std::string getThreatName();
			
           	// Returns the Thread's type
			std::string getThreatType();
	};
	
}
	
#endif // TROJAN_HORSE_H