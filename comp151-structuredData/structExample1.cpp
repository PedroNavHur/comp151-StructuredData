// Struct Example 1

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Comp151Stu {
	string FirstName, LastName;
	string degreeType, degreeMajor;
	double GPA;
};

void ReadFile(Comp151Stu*, ifstream  &);
void showStudentData(Comp151Stu*, ostream &);
double GetClassGPA(Comp151Stu*);
string GetHighestGPA(Comp151Stu*);

int main() {

	const int MAXSTUDENTS = 50;
	ifstream stufile("comp151Roster.txt");

	// Read the file data and store in my program
	Comp151Stu Student[MAXSTUDENTS];

	// Read student data
	ReadFile(Student, stufile);

	//Calculate Class GPA
	cout << fixed << setprecision(2);
	cout << GetClassGPA(Student) << endl;

	cout << GetHighestGPA(Student) << endl;



	// Show student data
	//showStudentData(Student, cout);

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
		f << "First Name  : " << student[i].FirstName << endl;
		f << "Lat Name    : " << student[i].LastName << endl;
		f << "Degree Typ  : " << student[i].degreeType << endl;
		f << "Degree Major: " << student[i].degreeMajor << endl;
		f << "GPA         : " << student[i].GPA << endl;
		f << endl;
		i++;
	}
}

double GetClassGPA(Comp151Stu *student) {
	double sum = 0, gpa;
	int i = 0;
	while (student[i].FirstName != "LAST") {
		sum += student[i].GPA;
		i++;
	}

	gpa = sum / i;
	return gpa;
}

string GetHighestGPA(Comp151Stu *student) {
	double highGPA = 0;
	int i = 0, index = 0;
	string studentA;

	while (student[i].FirstName != "LAST") {
		if (student[i].GPA > highGPA) {
			highGPA = student[i].GPA;
			index = i;
		}
		i++;
	}

	studentA = student[index].FirstName + " " + student[index].LastName;

	return studentA;
}