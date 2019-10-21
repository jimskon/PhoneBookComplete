#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
/* uncomment for applications that use vectors */
/*#include <vector>*/

#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#define HOST "localhost"
#define USER "skon"
#define DB "skon"

using namespace std;
//using namespace sql::mysql;

int main()
{
  const string url(HOST);
  const string user(USER);
  const string database(DB);
  string pass;
  
  cout << "Connector/C++ Phone Book example" << endl;
  cout << "Enter password for " << user << ":";
  cin >> pass;
  cout << endl;
  cin.ignore(100,'\n');
  try {

    sql::Driver* driver = sql::mysql::get_driver_instance();
    std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
    con->setSchema(database);
    std::auto_ptr<sql::Statement> stmt(con->createStatement());

    string first, last, phone, type;
    do {
      cout << " Enter first name (nothing to end):";
      getline(cin,first);
      if (first.length()>0) {
	cout << " Enter last name:";
	getline(cin,last);
	cout << " Enter phone #:";
	getline(cin,phone);
	cout << " Enter type:";
	getline(cin,type);

	// We need not check the return value explicitly. If it indicates
	// an error, Connector/C++ generates an exception.
	stmt->execute("CALL add_phone('"+first+"', '"+last+"', '"+phone+"', '"+type+"')");
      }
    } while (first.length() > 0);
      
  } catch (sql::SQLException &e) {
	/*
	  MySQL Connector/C++ throws three different exceptions:
	  
	  - sql::MethodNotImplementedException (derived from sql::SQLException)
	  - sql::InvalidArgumentException (derived from sql::SQLException)
	  - sql::SQLException (derived from std::runtime_error)
	*/
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    /* what() (derived from std::runtime_error) fetches error message */
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    
    return EXIT_FAILURE;
  }
 
  cout << "Done." << endl;
  return EXIT_SUCCESS;
}
