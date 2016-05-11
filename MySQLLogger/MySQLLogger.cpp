/*
* File: MySQLLogger/MySQLLogger.cpp
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
*
* This class will be the implementation of the 
* MySQL based logger to log particular actions from the simulation.
*/

#include <sstream>
#include "MySQLLogger.h"

using namespace std;
using namespace McOfee;

MySQLLogger::MySQLLogger()
{
	cout << "Buiding logger..." << endl;
    
    /* Initialize driver */
    driver = sql::mysql::get_mysql_driver_instance();
    /* Connect to localhost */
    con = driver->connect("tcp://127.0.0.1:3306", "root", "password"); // Never do that in a prod environment :)
    /* Ready to query */
    stmt = con->createStatement();
    /* Choose database to query from */
    stmt->execute("USE McOfee");
}

MySQLLogger::~MySQLLogger()
{
	cout << "Destroying logger..." << endl;

    con->close();
    delete stmt;
    delete con;
    //delete driver; From the MySQL documentation, this doesn't have to be destroyed.
}

void MySQLLogger::addLog(int threatId, string action)
{
    ostringstream s;
    s << threatId;
    string i_as_string(s.str());
    
    string query = "INSERT INTO Logger(logAction, threatId) VALUES \
                        ('" + action + "', " + i_as_string + ")"; 
    stmt->execute(query.c_str());
}

void MySQLLogger::flushLogs()
{
    stmt->execute("TRUNCATE TABLE Logger");
}
