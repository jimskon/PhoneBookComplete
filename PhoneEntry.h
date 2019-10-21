#include <string>
using namespace std;

#ifndef PHONEENTRY_H
#define PHONEENTRY_H

class PhoneEntry {
public:
     PhoneEntry();
     PhoneEntry(string f, string l, string p, string t,string I);
     string first;
     string last;
     string phone;
     string type;
     string ID;

private:

};

#endif /* PHONEENTRY_H */

