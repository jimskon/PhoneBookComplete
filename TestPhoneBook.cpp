
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
    char o;

    cout << "Phone Book test program" << endl;

    cout << "Select an option (1-serach first, 2-search last, 3-search type, 4-add, 5-edit, 6-delete, 7-end): ";
    cin >> o;

    while (o!='7') {
      if (o=='1') {
        cout << "Enter first name to find:";
        string firstMatch;
        cin >> firstMatch;

        pbResults = pb.findByFirst(firstMatch);

        for (int i = 0; i<pbResults.size(); i++) {
        	cout << pbResults.at(i).ID << ". "
               << pbResults.at(i).first << " "
        	     << pbResults.at(i).last << " "
        	     << pbResults.at(i).phone << " "
        	     << pbResults.at(i).type
        	     << endl;
        }
      } else if (o=='2') {

        cout << "Enter last name to find:";
        string lastMatch;
        cin >> lastMatch;

        pbResults = pb.findByLast(lastMatch);

        for (int i = 0; i<pbResults.size(); i++) {
          cout << pbResults.at(i).ID << ". "
             << pbResults.at(i).first << " "
        	   << pbResults.at(i).last << " "
        	   << pbResults.at(i).phone << " "
        	   << pbResults.at(i).type
        	   << endl;
        }
      } else if (o=='3') {
        cout << "Enter type to find:";
        string typeMatch;
        cin >> typeMatch;
        pbResults = pb.findByType(typeMatch);

        for (int i = 0; i<pbResults.size(); i++) {
          cout << pbResults.at(i).ID << ". "
          << pbResults.at(i).first << " "
    	    << pbResults.at(i).last << " "
    	    << pbResults.at(i).phone << " "
    	    << pbResults.at(i).type
    	    << endl;
        }
      } else if (o=='4') {

        cout <<"Enter a first name to add: ";
        string first,last,phone,type;
        cin >> first;
        cout << "Enter a last name to add: ";
        cin >>last;
        cout << "Enter a phone number: ";
        cin >> phone;
        cout << "lastly, end a type: ";
        cin >> type;

        pb.addEntry(first,last,phone,type);
        cout << "Entry added";

      } else if (o=='5') {
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
      } else if (o=='6') {

        string IDnum;
        cout << "Enter an ID number to delete";
        cin >> IDnum;
        pb.deleteEntry(IDnum);
        cout << "Attempted delete";
      }
      cout << "Seect an option (1-serach first, 2-search last, 3-search type, 4-add, 5-edit, 6-delete, 7-end): ";
      cin >> o;
    }
return 0;
}
