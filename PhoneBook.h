#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
/* uncomment for applications that use vectors */
#include <vector>

#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "PhoneEntry.h"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define HOST "localhost"
#define USER "skon"
#define DB "PhoneAppDB"
#define PASS "PhilanderChase"

using namespace std;

class PhoneBook {
public:
    PhoneBook();
    vector<PhoneEntry> findByFirst(string first);
    vector<PhoneEntry> findByLast(string last);
    vector<PhoneEntry> findByType(string type);
    void addEntry(string first,string last,string phone,string type);
    void editEntry(string idnum,string first,string last,string phone,string type);
    void deleteEntry(string idnum);
private:
    const string url=HOST;
    const string user=USER;
    const string database=DB;
    const string pass=PASS;
    
};

#endif /* PHONEBOOK_H */

