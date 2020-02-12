// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv) {
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    
	// Student ID
	// Non-negative number
	student.id = -1;
	while(student.id < 0) {
		std::cout << "Please enter the student's id number: ";
		std::cin >> student.id;
		if(student.id < 0) {
			std::cout << "Sorry, I cannot understand your answer" << std::endl;
		}
	}
    
	// First name
    student.f_name = new char[20];
	std::cout << "Please enter the student's first name: ";
	std::cin >> student.f_name;
	
	// Last name
    student.l_name = new char[20];
	std::cout << "Please enter the student's last name: ";
	std::cin >> student.l_name;
    
	// Number of assignments, n >= 1	
	student.n_assignments = 0;
	while(student.n_assignments < 1) {
		std::cout << "Please enter how many assignments were graded: ";
		std::cin >> student.n_assignments; // 'A6' fucks it
		if(student.n_assignments < 1) {
			std::cout << "Sorry, I cannot understand your answer" << std::endl;
		}
	}
    
	// Grades of assignments
	// Non-negative number
	student.grades = new double[student.n_assignments];
	for(int i = 0; i < student.n_assignments; i++) {
		student.grades[i] = -1;
		while(student.grades[i] < 0) {
			std::cout << "Please enter grade for assignment " << i << ": ";
			std::cin >> student.grades[i];
			if(student.grades[i] < 0) {
				std::cout << "Sorry, I cannot understand your answer" << std::endl;
			}
		}
	
	}
	
	double avg = 0.0;
	// send pointer student and avg
	calculateStudentAverage(&student, &avg);
	// avg should now contain the average of the grades
	std::cout << std::endl;
    std::cout << "Student: " << student.f_name << " " << student.l_name << "[" << student.id << "]";
	std::cout << std::endl;
	std::cout << "  Average grade: " << std::fixed << std::setprecision(1) << avg;
	std::cout << std::endl;
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

