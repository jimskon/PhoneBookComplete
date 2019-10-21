
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "PhoneBook.h"
#include "PhoneEntry.h"


using namespace std;

int main(){
    PhoneBook pb;
    vector<PhoneEntry> pbResults;

    cout << "Phone Book test program" << endl;

    /*    cout << "Enter first name to find:";
    string firstMatch;
    cin >> firstMatch;
    
    pbResults = pb.findByFirst(firstMatch);
    
    for (int i = 0; i<pbResults.size(); i++) {
	cout << pbResults.at(i).first << " "
	     << pbResults.at(i).last << " "
	     << pbResults.at(i).phone << " "
	     << pbResults.at(i).type
	     << endl;
    }

    cout << "Enter last name to find:";
    string lastMatch;
    cin >> lastMatch;

    pbResults = pb.findByLast(lastMatch);

    for (int i = 0; i<pbResults.size(); i++) {
      cout << pbResults.at(i).first << " "
	   << pbResults.at(i).last << " "
	   << pbResults.at(i).phone << " "
	   << pbResults.at(i).type
	   << endl;
    }

 

    cout << "Enter type to find:";
    string typeMatch;
    cin >> typeMatch;
    pbResults = pb.findByType(typeMatch);

    for (int i = 0; i<pbResults.size(); i++) {
      cout << pbResults.at(i).first << " "
	   << pbResults.at(i).last << " "
	   << pbResults.at(i).phone << " "
	   << pbResults.at(i).type
	   << endl;
    }
    cout <<"Enter a first name to add";
    string first,last,phone,type;
    cin >> first;
    cout << "Enter a last name to add";
    cin >>last;
    cout << "Enter a phone number";
    cin >> phone;
    cout << "lastly, end a type";
    cin >> type;
    
    pb.addEntry(first,last,phone,type);
    cout << "Entry added";
    
    
    string first,last,phone,type, IDnum;
    cout << "Enter an ID number to edit";
    cin >> IDnum;
    cout << "Enter a new first name";
    cin >> first;
    cout << "Enter a new last name";
    cin >> last;
    cout << "Enter a new phone number";
    cin >> phone;
    cout << "Enter a new type";
    cin >> type;
    pb.editEntry(IDnum,first,last,phone,type);
    cout << "Attempted to edit";
    */

    string IDnum;
    cout << "Enter an ID number to delete";
    cin >> IDnum;
    pb.deleteEntry(IDnum);
    cout << "Attempted delete";
    
return 0;}

