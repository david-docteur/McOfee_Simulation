/*
* File: Threats/TrojanHorse.cpp
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the implementation of the Trojan Horse class,
* which inherits from the Threat abstract class.
*/

#include "TrojanHorse.h"

using namespace std;
using namespace McOfee;

TrojanHorse::TrojanHorse() 
{
	// cout << "TrojanHorse's default constructor." << endl;
	folderToDestroy = "/system32";
}

TrojanHorse::TrojanHorse(int id, string type) : Threat(id, type) 
{
	// cout << "TrojanHorse's constructor." << endl;
}

TrojanHorse::~TrojanHorse() 
{
	cout << "TrojanHorse's destructor." << endl;
}

string TrojanHorse::getFolderToDestroy() 
{
	return folderToDestroy;
}

void TrojanHorse::setFolderToDestroy(string folder) 
{
	folderToDestroy = folder;
}

string TrojanHorse::printThreatAction() 
{
	return "I am a TrojanHorse, I control !";
}

int TrojanHorse::printThreatLevel() 
{
	return 3;
}

int TrojanHorse::getThreatId() 
{
    return threatId;
}
			
std::string TrojanHorse::getThreatName() 
{
    return threatName;
}
			
std::string TrojanHorse::getThreatType() 
{
    return threatType;
}