#ifndef STUDENT_H
#define STUDENT_H

#pragma once
#include <string>
#include "degree.h"
//-----------------
#include <iostream>
//-----------------
using namespace std;

class Student {
public:
	Student();

	//Class Mutators 
	void setID(string id);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmail(string studentEmail);
	void setAge(int studentAge);
	void setDays(int firstCourse, int secondCourse, int thirdCourse);
	void setDegree(degreeType deg);

	//Class Accessors
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int getDaysOne();
	int getDaysTwo();
	int getDaysThree();
	degreeType getDegreeType();

	//Print Member Variables
	void printID();
	void printFirstName();
	void printLastName();
	void printEmail();
	void printAge();
	void printDays();
	void printDegree();
	void printStudentData();


//Rubric D1
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[3];
	degreeType degree;




};









#endif