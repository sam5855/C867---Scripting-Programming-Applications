#include <iostream>
#include <cstring>
#include "roster.h"

using namespace std;

int main() {

	//Rubric F1
	cout << "C867-Scripting & Programming: Applications" << endl << "Language: C++" << endl << "Student ID: 009990088" << endl << "Name: Samuel McMasters" << endl << endl;

	//studentData table
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Samuel,McMasters,smcma60@wgu.edu,25,20,31,15,SOFTWARE"
	};


	//Create class roster. 
	Roster* classRoster = new Roster(5);


	//Parse and add each string from studentData[] 
	for (int i = 0; i < 5; ++i) {
		classRoster->parse(studentData[i]);
	};


	//Demonstrating functionality
	classRoster->printAll();
	classRoster->printInvalidEmails();

	//Print avg days in course
	cout << "Displaying average days in course:" << endl;
	for (int i = 0; i < classRoster->rosterSize; ++i) {
		string studentID = classRoster->classRosterArray[i]->getID();
		classRoster->printAverageDaysInCourse(studentID);
	}
	cout << endl;


	classRoster->printByDegree(SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	cout << "Removing A3 again" << endl;
	classRoster->remove("A3");

	//Class destructor releases memory
	classRoster->~Roster();
	
	
	

}