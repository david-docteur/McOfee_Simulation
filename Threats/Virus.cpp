/*
* File: Threats/Virus.cpp
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the implementation of the Virus class,
* which inherits from the Threat abstract class.
*/

#include "Virus.h"

using namespace std;
using namespace McOfee;

Virus::Virus() 
{
	// cout << "Virus's default constructor." << endl;
	folderToDestroy = "/system32";
}

Virus::Virus(int id, string type) : Threat(id, type) 
{
	// cout << "Virus's constructor." << endl;
	// folderToDestroy = folder;
}

Virus::~Virus() 
{
	 cout << "Virus's destructor." <<  endl;
}

string Virus::getFolderToDestroy() 
{
	return folderToDestroy;
}

void Virus::setFolderToDestroy(string folder) 
{
	folderToDestroy = folder;
}

string Virus::printThreatAction() 
{
	return "I am a virus, I destroy !";
}

int Virus::printThreatLevel() 
{
	return 3;
}

int Virus::getThreatId() 
{
    return threatId;
}
			
std::string Virus::getThreatName() 
{
    return threatName;
}
			
std::string Virus::getThreatType() 
{
    return threatType;
}
