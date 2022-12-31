#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//Roster class constructor 
Roster::Roster(int size) {
	this->rosterSize = size;
	this->index = 0;
	for (int i = 0; i < size; ++i) {
		this->classRosterArray[i] = new Student;
	}
	return;
}

//Add student objects to array
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeType degreeProgram) {
	classRosterArray[index]->setID(studentID);
	classRosterArray[index]->setFirstName(firstName);
	classRosterArray[index]->setLastName(lastName);
	classRosterArray[index]->setEmail(emailAddress);
	classRosterArray[index]->setAge(age);
	classRosterArray[index]->setDays(daysInCourse1, daysInCourse2, daysInCourse3);
	classRosterArray[index]->setDegree(degreeProgram);
	return;
}


//Parse data provided in studentData table
void Roster::parse(string row) {
	string studentID, firstName, lastName, email;
	int age, daysInCourse1, daysInCourse2, daysInCourse3, x, y;
	degreeType degree;
	if (index < rosterSize) {
		classRosterArray[index] = new Student;

		//Find student ID
		x = row.find(",");
		studentID = row.substr(0, x);
		y = x + 1;

		//Find first name
		x = row.find(",", y);
		firstName = row.substr(y, x - y);
		y = x + 1;

		//Find last name
		x = row.find(",", y);
		lastName = row.substr(y, x - y);
		y = x + 1;

		//Find email
		x = row.find(",", y);
		email = row.substr(y, x - y);
		y = x + 1;

		//Find age, convert string to int
		x = row.find(",", y);
		age = stoi(row.substr(y, x - y));
		y = x + 1;

		//Find days in course 1, convert string to int
		x = row.find(",", y);
		daysInCourse1 = stoi(row.substr(y, x - y));
		y = x + 1;

		//Find days in course 2, convert string to int
		x = row.find(",", y);
		daysInCourse2 = stoi(row.substr(y, x - y));
		y = x + 1;

		//Find days in course 3, convert string to int
		x = row.find(",", y);
		daysInCourse3 = stoi(row.substr(y, x - y));
		y = x + 1;

		//Check for degree string and convert to enumerated data type, degreeType
		x = row.find(",", y);
		string type = row.substr(y, x - y);
		if (type == "SOFTWARE") {
			degree = SOFTWARE;
		}
		else if (type == "SECURITY") {
			degree = SECURITY;
		}
		else if (type == "NETWORK") {
			degree = NETWORK;
		}
		else {
			cout << "Unknown degree." << endl;
		}

		//adds each student to classRosterArray
		this->add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
		++index;
	}
	return;
}

//Roster Remove Function
void Roster::remove(string studentID) {
	bool findID = false;

	//Check for student ID in array
	for (int i = 0; i < rosterSize; ++i) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (studentID == classRosterArray[i]->getID()) {
			classRosterArray[i] = nullptr;
			findID = true;
			break;
		}
	}

	//success/fail output message
	if (findID == false) {
		cout << "Error: Student " << studentID << " not found." << endl;
	}
	else if (findID == true) {
		cout << "Student " << studentID << " removed." << endl;
	}
	cout << endl;
	return;
}

//Roster Print All Function
void Roster::printAll() {
	cout << "Displaying all students:" << endl;
	for (int i = 0; i < rosterSize; ++i) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else {
			classRosterArray[i]->printStudentData();
		}
	}
	cout << endl;
	return;
}

//Roster Print Avg Days Function
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < rosterSize; ++i) {
		if (studentID == classRosterArray[i]->getID()) {
			int x = classRosterArray[i]->getDaysOne();
			int y = classRosterArray[i]->getDaysTwo();
			int z = classRosterArray[i]->getDaysThree();

			//convert int to double for appropriate division 
			double avgDays = (static_cast<double>(x) + static_cast<double>(y) + static_cast<double>(z)) / 3.0;
			cout << "Student ID: " << studentID << ", average days in course is: " << avgDays;
		}
	}
	cout << endl;
	return;
}


//Roster Print Invalid Emails Function
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl;
	for (int i = 0; i < rosterSize; ++i) {
		string studentEmail = classRosterArray[i]->getEmail();
		if ((studentEmail.find("@") == string::npos) || (studentEmail.find(".") == string::npos) || (studentEmail.find(" ") != string::npos)) {
			cout << studentEmail << " is invalid" << endl;
		}
	}
	cout << endl;
	return;
}

//Roster Print Student By Degree Type
void Roster::printByDegree(degreeType degPrg) {
	string degreeString;
	if (degPrg == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else if (degPrg == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degPrg == NETWORK) {
		degreeString = "NETWORK";
	}
	else {
		degreeString = "Error: Degree not found";
	}
	cout << "Showing students in degree program: " << degreeString << endl;
	int numStudents = 0;
	for (int i = 0; i < rosterSize; ++i) {
		if (classRosterArray[i]->getDegreeType() == degPrg) {
			classRosterArray[i]->printStudentData();
			++numStudents;
		}
	}
	if (numStudents == 0) {
		cout << "No students found with this degree" << endl;
	}
	cout << endl;
	return;
}



//Roster Delete
Roster::~Roster() {
	for (int i = 0; i < rosterSize; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	return;
}