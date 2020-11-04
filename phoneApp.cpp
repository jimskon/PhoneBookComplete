#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Stuff for AJAX
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "PhoneBook.h"
#include "PhoneEntry.h"

#define XML_USE_STL

using namespace std;
using namespace cgicc; // Needed for AJAX functions.

ofstream logfile; 

int main() {
  Cgicc cgi;    // Ajax object
  char *cstr;

  PhoneBook pb; // Phone Book SQL Interface Object
  vector<PhoneEntry> pbResults;
  
  // Create AJAX objects to recieve information from web page.
  form_iterator op = cgi.getElement("operation");
  string operation = **op;
  logfile.open("/home/fifo/skonphone.log",ios::out | ios::app);
  logfile << "Op:" << operation << endl;
  logfile.close();
  string output = "Error = "+operation+ " - Operation not support yet!";
  if (operation == "Find Last") {
    form_iterator searchString = cgi.getElement("find");
    string search = **searchString;
    
    pbResults = pb.findByLast(search);
    if (pbResults.size() > 0) {
      output = "success";
      for (int i = 0; i<pbResults.size(); i++) {
	output += "," + pbResults.at(i).first + ","
	  + pbResults.at(i).last + ","
	  + pbResults.at(i).phone + ","
	  + pbResults.at(i).type + ","
	  + pbResults.at(i).ID;
      }
    } else {
      output = "No Match Found";
    }
  }

  if (operation == "Find First") {
    form_iterator searchString = cgi.getElement("find");
    string search = **searchString;
    
    pbResults = pb.findByFirst(search);
    if (pbResults.size() > 0) {
      output = "success";
      for (int i = 0; i<pbResults.size(); i++) {
	output += "," + pbResults.at(i).first + ","
	  + pbResults.at(i).last + ","
	  + pbResults.at(i).phone + ","
	  + pbResults.at(i).type + ","
	  + pbResults.at(i).ID;
      }
    } else {
      output = "No Match Found";
    }
  }
  if (operation == "Find Type") {
    form_iterator searchString = cgi.getElement("find");
    string search = **searchString;
    
    pbResults = pb.findByType(search);
    if (pbResults.size() > 0) {
      output = "success";
      for (int i = 0; i<pbResults.size(); i++) {
	output += "," + pbResults.at(i).first + ","
	  + pbResults.at(i).last + ","
	  + pbResults.at(i).phone + ","
	  + pbResults.at(i).type + ","
	  + pbResults.at(i).ID;
      }
    } else {
      output = "No Match Found";
    }
  }

  if(operation=="Add Entry"){
    form_iterator afnameString = cgi.getElement("afname");
    form_iterator alnameString = cgi.getElement("alname");
    form_iterator addphoneString = cgi.getElement("aphone");
    form_iterator addtypeString = cgi.getElement("atype");

    string addfname=**afnameString;
    string addlname=**alnameString;
    string addphone=**addphoneString;
    string addtype=**addtypeString;

    pb.addEntry(addfname,addlname,addphone,addtype);
    output="success";
  }
  
  if(operation=="delete"){
    form_iterator idtodeleteString = cgi.getElement("deleteid");
    string iddelete=**idtodeleteString;

    pb.deleteEntry(iddelete);
    output="success";
  }
  if(operation=="edit"){
    form_iterator idtoeditString = cgi.getElement("editid");
    string idedit=**idtoeditString;

    form_iterator editfnameString = cgi.getElement("editfname");
    form_iterator editlnameString = cgi.getElement("editlname");
    form_iterator editphoneString = cgi.getElement("editphone");
    form_iterator edittypeString = cgi.getElement("edittype");

    string editfname=**editfnameString;
    string editlname=**editlnameString;
    string editphone=**editphoneString;
    string edittype=**edittypeString;


    pb.editEntry(idedit,editfname,editlname,editphone,edittype);
    output="success";
  }
  
  /* send back the results */
  cout << "Content-Type: text/plain\n\n";

  cout << output << endl;
  
  
  return 0;
}

