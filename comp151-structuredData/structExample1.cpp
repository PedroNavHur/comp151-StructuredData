// Struct Example 1

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Comp151Stu {
		string FirstName, LastName;
		string degreeType, degreeMajor;
		double GPA;
	};


void getStudentData (Comp151Stu &student, ifstream &stream){
	stream >> student.FirstName >> student.LastName;
};

void main() {
	
	

	ifstream stufile("comp151Roster.txt");

	// Read the file data and store in my program
	Comp151Stu aStudent;
	
	stufile >> aStudent.FirstName >> aStudent.LastName >> aStudent.degreeType >> aStudent.degreeMajor >> aStudent.GPA;

	cout << "Here is the file data:" << endl << endl;
	cout << "First Name: ";
	cout << "Lat Name: ";
	cout << "Degree Type: ";
	cout << "Degree Major: ";
	cout << "GPA: ";

	stufile.close();
}