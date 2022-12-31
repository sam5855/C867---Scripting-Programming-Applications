#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include <array>
#include "student.h"

using namespace std;

//Roster class declaration
//Rubric 
class Roster {
public:
	Roster(int size);
	~Roster();
	int rosterSize;
	int index;
	Student* classRosterArray[5];

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeType degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void parse(string row);
	void printByDegree(degreeType degPrg);

private:

};



#endif
