#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//Parameterless Class Constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->days[0] = 0;
	this->days[1] = 0;
	this->days[2] = 0;
	this->degree = SECURITY; //Sets default value to SECURITY 

}

//Constructer using input values
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeType degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->days[0] = daysInCourse1;
	this->days[1] = daysInCourse2;
	this->days[2] = daysInCourse3;
	this->degree = degree;
}

//Class Mutators Definitions

//Set Student ID
void Student::setID(string id) {
	this->studentID = id;
	return;
}

//Set Student First Name
void Student::setFirstName(string fName) {
	this->firstName = fName;
	return;
}

//Set Student Last Name
void Student::setLastName(string lName) {
	this->lastName = lName;
	return;
}

//Set Student Email
void Student::setEmail(string studentEmail) {
	this->email = studentEmail;
	return;
}

//Set Student Age
void Student::setAge(int studentAge) {
	this->age = studentAge;
	return;
}

//Set Course Days to Complete
void Student::setDays(int firstCourse, int secondCourse, int thirdCourse) {
	this->days[0] = firstCourse;
	this->days[1] = secondCourse;
	this->days[2] = thirdCourse;
	return;
}

//Set Degree Type
void Student::setDegree(degreeType deg) {
	this->degree = deg;
	return;
}



//Class Accessors Definitions

//Get Student ID
string Student::getID() {
	return studentID;
}

//Get Student First Name
string Student::getFirstName() {
	return firstName;
}

//Get Student Last Name
string Student::getLastName() {
	return lastName;
}

//Get Student Email
string Student::getEmail() {
	return email;
}

//Get Student Age
int Student::getAge() {
	return age;
}

//Get First Course Days
int Student::getDaysOne() {
	return days[0];
}

//Get Second Course Days
int Student::getDaysTwo() {
	return days[1];
}

//Get Third Course Days
int Student::getDaysThree() {
	return days[2];
}

//Get Degree Type
degreeType Student::getDegreeType() {
	return degree;
}


//Print Function Definitions 

//Print Student ID
void Student::printID() {
	cout << studentID << endl;
	return;
}

//Print Student First Name
void Student::printFirstName() {
	cout << firstName << endl;
	return;
}

//Print Student Last Name
void Student::printLastName() {
	cout << lastName << endl;
	return;
}

//Print Student Email
void Student::printEmail() {
	cout << email << endl;
	return;
}

//Print Student Age
void Student::printAge() {
	cout << age << endl;
	return;
}

//Print Student Days Left
void Student::printDays() {
	cout << days[0] << ", " << days[1] << ", " << days[2] << endl;
	return;
}

//Print Student Degree
void Student::printDegree() {
	if (degree == SOFTWARE) {
		cout << "SOFTWARE" << endl;
	}
	else if (degree == NETWORK) {
		cout << "NETWORK" << endl;
	}
	else {
		cout << "SECURITY" << endl;
	}
	return;
}


//Print All Student Data
void Student::printStudentData() {
	string degreeStr;
	if (degree == SOFTWARE) {
		degreeStr = "SOFTWARE";
	}
	else if (degree == SECURITY) {
		degreeStr = "SECURITY";
	}
	else if (degree == NETWORK) {
		degreeStr = "NETWORK";
	}
	else {
		degreeStr = "ERROR";
	}

	cout << studentID << "	First Name: " << firstName << "	Last Name: " << lastName << "	Age: " << age << "   daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "}	Degree Program: " << degreeStr << " " << endl;

	return;
}

//Class destructor 
//Always include class destructor 
Student::~Student() {
	return;
}