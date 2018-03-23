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

void ReadFile(Comp151Stu*, ifstream  &);
void showStudentData(Comp151Stu*, ostream &);

int main() {

	const int MAXSTUDENTS = 50;
	ifstream stufile("comp151Roster.txt");

	// Read the file data and store in my program
	Comp151Stu aStudent[MAXSTUDENTS];

	// Read student data
	ReadFile(aStudent, stufile);

	// Show student data
	showStudentData(aStudent, cout);

	stufile.close();
}

void ReadFile(Comp151Stu *student, ifstream &stream) {

	int i = 0;
	stream >> student[i].FirstName;

	while (student[i].FirstName != "LAST") {
		stream >> student[i].LastName >> student[i].degreeType >> student[i].degreeMajor >> student[i].GPA;
		i++;
		stream >> student[i].FirstName;
	}

}

void showStudentData(Comp151Stu *student, ostream &f) {

	f << "Here is the file data:" << endl << endl;

	int i = 0;
	while (student[i].FirstName != "LAST") {
		f << "First Name           : " << student[i].FirstName << endl;
		f << "Lat Name             : " << student[i].LastName << endl;
		f << "Degree Type          : " << student[i].degreeType << endl;
		f << "Degree Major         : " << student[i].degreeMajor << endl;
		f << "GPA                  : " << student[i].GPA << endl;
		f << endl;
		i++;
	}
}