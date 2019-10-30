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
    stmt->execute("SELECT * FROM Phonebook WHERE Last like '%"+last+"%'");
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
  stmt->execute("SELECT * FROM Phonebook WHERE First like '%"+first+"%'");
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
  stmt->execute("SELECT * FROM Phonebook WHERE Type like '%"+type+"%'");
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
  stmt->execute("INSERT INTO Phonebook(First,Last,Phone,Type) VALUES ('"+first+"','"+last+"','"+phone+"','"+type+"')");
}


void PhoneBook::editEntry(string idnum,string first,string last,string phone, string type){
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());
  if(type != "Friend" && type != "Family" && type!="Business"){
    type="Other";
  }
  stmt->execute("UPDATE Phonebook SET First = '"+first+"', Last ='"+last+"', Phone ='"+phone+"', Type ='"+type+"' WHERE ID='"+idnum+"'");
}


void PhoneBook::deleteEntry(string idnum){
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);
  std::auto_ptr<sql::Statement> stmt(con->createStatement());

  stmt->execute("DELETE FROM Phonebook WHERE ID='"+idnum+"'");
}
