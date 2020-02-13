// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <sstream> 
#include <iomanip>
// #include<limits>
#include<regex>

using namespace std; // allows omitting  in front of cin

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
    
	// Student ID
	// Non-negative number
	/*
	do{
		cout << "Please enter the student's id number: ";
		cin >> student.id;
		if(student.id < 0) {
			cout << "Sorry, I cannot understand your answer" << endl;
		}
	}while(student.id < 0);
	*/
	double id = 0;
	getUserInput("Please enter the student's id number: ", 0, &id);
	student.id = id;
    
	// First name
    student.f_name = new char[10];
	cout << "Please enter the student's first name: ";
	cin >> student.f_name;
	if(regex_search(student.f_name, regex("\\n+"))){
		cout << endl << "newline" << endl;
	}
	
	// Last name
    student.l_name = new char[10];
	cout << "Please enter the student's last name: ";
	cin >> student.l_name;
    
	// Number of assignments, n >= 1
	/*
	student.n_assignments = 0;
	while(student.n_assignments < 1) {
		cout << "Please enter how many assignments were graded: ";
		cin >> student.n_assignments; // 'A6' error
		if(student.n_assignments < 1) {
			cout << "Sorry, I cannot understand your answer" << endl;
		}
	}
	*/
	double n_assignments = 0;
	getUserInput("Please enter how many assignments were graded: ", 1, &n_assignments);
	student.n_assignments = n_assignments;
	
	cout << endl; // keep this
    
	// Grades of assignments
	// Non-negative number
	student.grades = new double[student.n_assignments];
	for(int i = 0; i < student.n_assignments; i++) {
		// student.grades[i] = -1;
		string msg = "Please enter grade for assignment " + to_string(i) + ": ";
		getUserInput(msg, 0, &student.grades[i]);
		/*
		while(student.grades[i] < 0) {
			/*
			cout << "Please enter grade for assignment " << i << ": ";
			cin >> student.grades[i];
			if(student.grades[i] < 0) {
				cout << "Sorry, I cannot understand your answer" << endl;
			}
			
			//getUserInput("Please enter grade for assignment i: ", 0, &student.grades[i]);
		}
		*/
	}
	
	double avg = 0.0;
	// send pointer student and avg
	calculateStudentAverage(&student, &avg);
	// avg should now contain the average of the grades
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


void getUserInput(string msg, int min, double *var){
	string s = "";	
	do{
		cout << msg;
		cin >> s;
		if(regex_search(s, regex("[^\\d.]+"))){
			cout << "Sorry, I cannot understand your answer" << endl;
		} else {
			stringstream stream(s);
			stream >> *var;
			break;
		}
	}while(true);
	/*
	do{
		cout << msg;
		cin >> *var;
		if(cin.fail() || *var < min) {
			cout << "Sorry, I cannot understand your answer" << endl;
			cin.clear(); // clears the error on cin
			//cin.ignore(100,'\n'); // ignores all characters inputted into the input stream, numeric_limits<streamsize>::max()
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			*var = -1;
		}
	}while(*var < min);
	*/
}

