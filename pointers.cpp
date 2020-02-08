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
	std::cout << "Please enter the student's id number: ";
	std::cin >> student.id;
    
	// First name
    student.f_name = new char[20];
	std::cout << "Please enter the student's first name: ";
	std::cin >> student.f_name;
	
	// Last name
    student.l_name = new char[20];
	std::cout << "Please enter the student's last name: ";
	std::cin >> student.l_name;
    
	// Number of assignments
	std::cout << "Please enter how many assignments were graded: ";
	std::cin >> student.n_assignments;
	std::cout << std::endl;
    
	// Grades of assignments
	student.grades = new double[student.n_assignments];
	for(int i = 0; i < student.n_assignments; i++){
		std::cout << "Please enter grade for assignment " << i << ": ";
		std::cin >> student.grades[i];
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

