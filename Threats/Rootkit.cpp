/*
* File: Rootkit.cpp
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the implementation of the Rootkit class,
* which inherits from the Threat abstract class.
*/

#include "Rootkit.h"

using namespace std;
using namespace McOfee;

Rootkit::Rootkit()
{
	// cout << "Rootkit's default constructor." << endl;
	folderToDestroy = "/system32";
}

Rootkit::Rootkit(int id, string type) : Threat(id, type)
{
	// cout << "Rootkit's constructor." << endl;
	// folderToDestroy = folder;
}

Rootkit::~Rootkit()
{
	cout << "Rootkit's destructor." << endl;
}

string Rootkit::getFolderToDestroy()
{
	return folderToDestroy;
}

void Rootkit::setFolderToDestroy(string folder)
{
	folderToDestroy = folder;
}

string Rootkit::printThreatAction()
{
	return "I am a Rootkit, I hide !";
}

int Rootkit::printThreatLevel() 
{
	return 3;
}

int Rootkit::getThreatId() 
{
    return threatId;
}
			
string Rootkit::getThreatName() 
{
    return threatName;
}
			
string Rootkit::getThreatType() 
{
    return threatType;
}
