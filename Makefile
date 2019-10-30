#MakeFile to build and deploy the Sample US CENSUS Name Data using ajax
# For CSC3004 Software Development

# Put your user name below:
USER= skon

CC= g++

#For Optimization
#CFLAGS= -O2
#For debugging
CFLAGS= -std=c++14  -Wno-deprecated-declarations

RM= /bin/rm -f

all: TestPhoneBook phoneApp PutHTML PutCGI

PhoneEntry.o: PhoneEntry.cpp PhoneEntry.h
	$(CC) -c $(CFLAGS) PhoneEntry.cpp

PhoneBook.o: PhoneBook.cpp PhoneBook.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn PhoneBook.cpp

TestPhoneBook.o: TestPhoneBook.cpp PhoneEntry.h	PhoneBook.h
	$(CC) -c $(CFLAGS) TestPhoneBook.cpp

TestPhoneBook: TestPhoneBook.o PhoneBook.o PhoneEntry.o
	$(CC) TestPhoneBook.o PhoneBook.o PhoneEntry.o -L/usr/lib -o TestPhoneBook -L/usr/local/lib -lcgicc -lmysqlcppconn

phoneApp.o: phoneApp.cpp 
	$(CC) -c $(CFLAGS) phoneApp.cpp

phoneApp: phoneApp.o PhoneBook.o PhoneEntry.o
	$(CC) phoneApp.o PhoneBook.o PhoneEntry.o -o phoneApp -L/usr/local/lib -lcgicc -lmysqlcppconn

PutCGI: phoneApp
	chmod 757 phoneApp
	cp phoneApp /usr/lib/cgi-bin/$(USER)_phoneAppComplete.cgi 

	echo "Current contents of your cgi-bin directory: "
	ls -l /usr/lib/cgi-bin/

PutHTML:
	cp phoneApp.html /var/www/html/class/softdev/$(USER)/PhoneAppComplete
	cp phoneApp.js /var/www/html/class/softdev/$(USER)/PhoneAppComplete
	cp phoneApp.css /var/www/html/class/softdev/$(USER)/PhoneAppComplete


	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/class/ssd/$(USER)/PhoneAppComplete

clean:
	rm -f *.o  phoneApp TestPhoneBook
