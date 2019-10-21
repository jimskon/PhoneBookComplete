#include <vector>
#include <iostream>
#include "PhoneBook.h"
#include "PhoneEntry.h"

PhoneBook::PhoneBook() {

}
  vector<PhoneEntry> PhoneBook::findByLast(string last) {
    sql::Driver* driver = sql::mysql::get_driver_instance();
    std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
    con->setSchema(database);
    std::auto_ptr<sql::Statement> stmt(con->createStatement());

    vector<PhoneEntry> list;
    stmt->execute("CALL find_last('%"+last+"%')");
    std::auto_ptr< sql::ResultSet > res;
    do {
      res.reset(stmt->getResultSet());
      while (res->next()) {
          PhoneEntry entry(res->getString("First"),res->getString("Last"),
			   res->getString("Phone"),res->getString("Type"),
	    res->getString("ID"));
	  
	  list.push_back(entry);

      }
    } while (stmt->getMoreResults());
    return list;
    
}

vector<PhoneEntry> PhoneBook::findByFirst(string first) {
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());

  vector<PhoneEntry> list;
  stmt->execute("CALL find_first('%"+first+"%')");
  std::auto_ptr< sql::ResultSet > res;
  do {
    res.reset(stmt->getResultSet());
    while (res->next()) {
      PhoneEntry entry(res->getString("First"),res->getString("Last"),
		       res->getString("Phone"),res->getString("Type"),
	res->getString("ID"));
        list.push_back(entry);

    }
  } while (stmt->getMoreResults());
  return list;

}
vector<PhoneEntry> PhoneBook::findByType(string type) {
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());

  vector<PhoneEntry> list;
  stmt->execute("CALL find_type('"+type+"')");
  std::auto_ptr< sql::ResultSet > res;
  do {
    res.reset(stmt->getResultSet());
    while (res->next()) {
      PhoneEntry entry(res->getString("First"),res->getString("Last"),
		       res->getString("Phone"),res->getString("Type"),
	res->getString("ID"));
      list.push_back(entry);

    }
  } while (stmt->getMoreResults());
  return list;

}

void PhoneBook::addEntry(string first,string last,string phone, string type){
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());
  if(type != "Friend" && type != "Family" && type!="Business"){
      type="Other";
  }
  stmt->execute("CALL add_entry('"+first+"','"+last+"','"+phone+"','"+type+"')");
}


void PhoneBook::editEntry(string idnum,string first,string last,string phone, string type){
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());
  if(type != "Friend" && type != "Family" && type!="Business"){
    type="Other";
  }
  stmt->execute("CALL edit_entry('"+idnum+"','"+first+"','"+last+"','"+phone+"','"+type+"')");
}


void PhoneBook::deleteEntry(string idnum){
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());

  stmt->execute("CALL delete_entry('"+idnum+"')");
}
