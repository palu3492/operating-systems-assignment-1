// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <sstream> 
#include <iomanip>
// #include<limits>
#include<regex>

using namespace std; // allows omitting std::

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);
void getUserInput(string msg, int min, double *var);

int main(int argc, char **argv) {
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    
	// Student ID (non-negative)
	double id = -1;
	getUserInput("Please enter the student's id number: ", 0, &id);
	student.id = id;
    
	// First name
    student.f_name = new char[128];
	cout << "Please enter the student's first name: ";
	cin >> student.f_name;
	
	// Last name
    student.l_name = new char[128];
	cout << "Please enter the student's last name: ";
	cin >> student.l_name;
    
	// Number of assignments (positive)
	double n_assignments = -1;
	getUserInput("Please enter how many assignments were graded: ", 1, &n_assignments);
	student.n_assignments = n_assignments;
	
	cout << endl; // keep this
    
	// Grades of assignments (non-negative)
	student.grades = new double[student.n_assignments];
	for(int i = 0; i < student.n_assignments; i++) {
		student.grades[i] = -1;
		string msg = "Please enter grade for assignment " + to_string(i) + ": ";
		getUserInput(msg, 0, &student.grades[i]);
	}
	
	// Average of assignments
	double avg = 0.0;
	// send pointer to <Student>student and <double>avg
	calculateStudentAverage(&student, &avg);
	// avg should now contain the average of the grades
	
	// Print everything
	cout << endl;
    cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]";
	cout << endl;
	cout << "  Average grade: " << fixed << setprecision(1) << avg;
	cout << endl;
    return 0;
}

// Function to calculate and store average grade
// Takes in pointer to <Student>student and <double>avg
void calculateStudentAverage(void *object, double *avg) {
	double total = 0.0;
	double size = ((Student*) object)->n_assignments;
	for(int i = 0; i < size; i++){
    	total += ((Student*) object)->grades[i];
    }
	*avg = total/size;
}

// Function to take user input and error check
void getUserInput(string msg, int min, double *var){
	string input = "";	
	do{
		cout << msg;
		cin >> input;
		if(regex_search(input, regex("[^\\d.]+"))){
			cout << "Sorry, I cannot understand your answer" << endl;
		} else {
			stringstream stream(input);
			stream >> *var;
			if(*var < min){
				cout << "Sorry, I cannot understand your answer" << endl;
			}
		}
	}while(*var < min);
}

