/*
* File: ThreatGenerator.cpp
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the implementation of the ThreatGenerator
* class, which generates Threats to be sent to the Computer.
*/

#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <future>
#include <sstream>
#include <string>
#include <unistd.h>
#include "ThreatGenerator.h"
#include "../Threats/Rootkit.h"
#include "../Threats/TrojanHorse.h"
#include "../Threats/Virus.h"

using namespace std;
using namespace McOfee;

int ThreatGenerator::generationNumber = 1;
bool ThreatGenerator::running = false;

ThreatGenerator::ThreatGenerator(Computer& c)
{
	cout << "Building ThreatGenerator..." << endl;
	computer = &c;
}

ThreatGenerator::~ThreatGenerator()
{
	cout << "Destroying ThreatGenerator..." << endl;
	// This one will be destroyed by Simulation::~Simulation()
	//delete computer;
}

void ThreatGenerator::generateThreatAsFile(string threatType, int threatNumber)
{
	ostringstream s;
	s << threatNumber;
	string i_as_string(s.str());
	string filename = "Default_Computer_Folder/" + threatType + "_" + i_as_string + ".txt";
	fstream file;
	file.open(filename, fstream::out);
	file.close();
}

void ThreatGenerator::runThread(ThreatGenerator* t)
{
	while(true && running)
	{
		sleep(1);
		
		// Check that we haven't reached the maximum amount of threats.
		if(generationNumber <= Computer::ACTIVE_LIST_MAX_SIZE)
		{
			// Randomly select Threat type - NOT REAL RANDOM?
			int threatType = rand() % 3 + 1;
			switch(threatType)
			{
				case 1 :
					t->sendThreat(new Virus(generationNumber, "Virus"));
					t->generateThreatAsFile("Virus", generationNumber);
					break;
				case 2 :
					t->sendThreat(new TrojanHorse(generationNumber, "TrojanHorse"));
					t->generateThreatAsFile("TrojanHorse", generationNumber);
					break;
				case 3:
					t->sendThreat(new Rootkit(generationNumber, "Rootkit"));
					t->generateThreatAsFile("Rootkit", generationNumber);
					break;
				default:
					t->sendThreat(new Virus(generationNumber, "Virus"));
					break;
			}
			generationNumber++;
		}
	}
}
	
void ThreatGenerator::simulateInfection()
{
	running = true;
	try
	{
    	currentThread = boost::thread(runThread, this);
	}
	catch(int e)
	{
		cout << "Error creating thread, stop program... Exception code: " << e << endl;
		exit(-1);
	}
      
}

void ThreatGenerator::stopInfection()
{
	running = false;
	// Stop the thread and wait for it to finish
	currentThread.interrupt();
	currentThread.join();
}
