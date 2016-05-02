/*
* File: Computer.cpp
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the implementation of the Computer class,
* which is going to have a folder associated to it.
*/

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <sys/stat.h>
#include "Computer.h"
#include "boost/filesystem.hpp"

using namespace std;
using namespace McOfee;


Computer::Computer()
{
	cout << "Building default Computer..." << endl;
	computerName = "Default Computer";
	const boost::filesystem::path default_computer_path("Default_Computer_Folder");
	const boost::filesystem::path quarantine_path("Default_Computer_Folder/Quarantined");

	if(!exists(default_computer_path))
	{
		bool createDir = boost::filesystem::create_directory(default_computer_path);
		if(!createDir)
			cout << "Error creating directory: " << strerror(errno) << endl;
	}
	if(!exists(quarantine_path))
	{
		bool createDir = boost::filesystem::create_directory(quarantine_path);
		if(!createDir)
			cout << "Error creating directory: " << strerror(errno) << endl;
	}
}

Computer::Computer(const string name)
{
    cout << "Building custom Computer" << endl;
    computerName = name;
    const boost::filesystem::path computer_path(name + "_Computer_Folder");
	const boost::filesystem::path quarantine_path(name + "_Computer_Folder/Quarantined");

    if(!exists(computer_path))
	{
		bool createDir = boost::filesystem::create_directory(computer_path);
		if(!createDir)
			cout << "Error creating directory: " << strerror(errno) << endl;
	}
	if(!exists(quarantine_path))
	{
		bool createDir = boost::filesystem::create_directory(quarantine_path);
		if(!createDir)
			cout << "Error creating directory: " << strerror(errno) << endl;
	}
}

Computer::~Computer()
{
	const boost::filesystem::path path("Default_Computer_Folder/");
	if(exists(path))
		remove_all(path);
	// No need to call activeThreats.clear() as it is a list of pointers
	//cout << "error: " << strerror(errno) << endl;	
	cout << "Destroying Computer..." << endl;
}

void Computer::addThreat(Threat* t)
{
	if(t)
		activeThreats.push_back(t);
}

int Computer::getNumberOfThreats()
{
	return activeThreats.size();
}

void Computer::deleteThreat(int i)
{
	for(typename list<Threat*>::iterator it = activeThreats.begin(); it != activeThreats.end(); it++) {
		if((*it)->getThreatId() == i) {
			// Remove file	
			removeFileThreat(i, (*it)->getThreatType());			
			// Remove pointed value			
			delete *it;
			// Remove from list
			it = activeThreats.erase(it);
		}
	 }
}

void Computer::quarantineThreat(int i)
{
	for(typename list<Threat*>::iterator it = activeThreats.begin(); it != activeThreats.end(); it++) {
		if((*it)->getThreatId() == i) {
			// Remove file	
			quarantineFileThreat(i, (*it)->getThreatType());			
			// Remove pointed value			
			delete *it;
			// Remove from list
			it = activeThreats.erase(it);
		}
	 }
}

void Computer::renameThreat(int i, string newName)
{
	for(typename list<Threat*>::iterator it = activeThreats.begin(); it != activeThreats.end(); it++) {
		if((*it)->getThreatId() == i) {
			// Remove file
			renameFileThreat(i, (*it)->getThreatType(), newName);
			// Remove pointed value			
			delete *it;
			// Remove from list
			it = activeThreats.erase(it);
		}
	 }
}

void Computer::removeFileThreat(int threatId, string type)
{
	ostringstream s;
	s << threatId;
	string i_as_string(s.str());
	string file = "Default_Computer_Folder/" + type + "_" + i_as_string + ".txt";
	
	remove(file.c_str());
	if(errno != 0)
		cout << "Unable to remove file: " << strerror(errno) << endl;
}
			
void Computer::quarantineFileThreat(int threatId, string type)
{
	ostringstream s;
	s << threatId;
	string i_as_string(s.str());
	string file = "Default_Computer_Folder/" + type + "_" + i_as_string + ".txt";
	
	rename(file.c_str(), ("Default_Computer_Folder/Quarantined/" + type + "_" + i_as_string + ".txt").c_str());
	if(errno != 0)
		cout << "Unable to quarantine file: " << strerror(errno) << endl;
}

void Computer::renameFileThreat(int threatId, string type, string newName)
{
	ostringstream s;
	s << threatId;
	string i_as_string(s.str());
	
	string file = "Default_Computer_Folder/" + type + "_" + i_as_string + ".txt";

	rename(file.c_str(), ("Default_Computer_Folder/" + newName + ".txt").c_str());
	if(errno != 0)
		cout << "Unable to rename file: " << strerror(errno) << endl;
}
