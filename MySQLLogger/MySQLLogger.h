/*
* File: MySQLLogger/MySQLLogger.h
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the MySQL based logger
* to log particular actions from the simulation.
*/

#ifndef MYSQL_LOGGER_H
#define MYSQL_LOGGER_H

#include <iostream>
#include <mysql_driver.h>
#include "cppconn/statement.h"

namespace McOfee
{
	
    class MySQLLogger
    {
        
       private:
          // The MySQL C++ driver: mysql -u root -p
          sql::mysql::MySQL_Driver *driver;
           
          // Connection to the database
          sql::Connection *con;
           
          // Statement for queries
          sql::Statement *stmt;

       public:
			    // Default constructor
          MySQLLogger();
            
          // Destructor
			    ~MySQLLogger();
		     
          // Adds data to the DB
			    void addLog(int, std::string);
            
          // Removes all of the data
			    void flushLogs();
	};
}

#endif // MYSQL_LOGGER_H
