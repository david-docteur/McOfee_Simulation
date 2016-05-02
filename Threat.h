/*
* File: Threat.h
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the header of the Threat class,
* which is an abstract class for any Threat object.
*/

#ifndef THREAT_H
#define THREAT_H

#include <iostream>
#include <string>

namespace McOfee {

	class Threat {
			
		protected:
			// Just a Threat static counter
			static int threatsCounter;
			
			// ID of a threat
			int threatId;
			
			// Name of a Threat
			std::string threatName;
			
			// Type of a Threat
			std::string threatType;
			
		public:
			// Default constructor
			Threat()
			{
				// std::cout << "Threat's default constructor called." << std::endl;
				threatName = "Default threat";
				threatType = "Virus";
			}
			
			// Constructor
			Threat(int id, std::string type)
			{
				// std::cout << "Threat's constructor called." << std::endl;
				threatId = id;
				threatType = type;
			}

			/* No need to overload copy constructor and assignment operator
			 as a shallow copy will be enough. */
			
			// Destructor
			virtual ~Threat()
			{
				std::cout << "Threat's destructor called." << std::endl;
			}
			
			//PURE VIRTUAL FUNCTIONS
			// Prints what a Threat should do
			virtual std::string printThreatAction()=0;
			
			// Prints a Threat level
			virtual int printThreatLevel()=0;
			
           	// Returns the id
			virtual int getThreatId()=0;
			
           	// Returns a Threat's name
			virtual std::string getThreatName()=0;
			
           	// Returns a Threat's type
			virtual std::string getThreatType()=0;
		
	};
	
}

#endif // THREAT_H
