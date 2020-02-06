// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cstring>

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
    //student.id = 123456;
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
	
    // strcpy(student.f_name, "Jane");
    // strcpy(student.l_name, "Doe");
    
    // student.n_assignments = 4;
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
    /*
    student.grades[0] = 98.02;
    student.grades[1] = 59.98;
    student.grades[2] = 76.28;
    student.grades[3] = 85.99;
	*/
	/*
    printf("id: %d, first: %s, last: %s \n", student.id, student.f_name, student.l_name);
    printf("assingments: %d \n", student.n_assignments);
    printf("grades: \n");
    for(int i = 0; i < student.n_assignments; i++){
    	printf("  %.2f \n", student.grades[i]);
    }
	*/
	
	double avg = 0.0;
	// send pointer to avg
	calculateStudentAverage(student.grades, &avg);
	// avg should now contain the average of the grades
	std::cout << std::endl;
    std::cout << "Student: " << student.f_name << " " << student.l_name << "[" << student.id << "]";
	std::cout << std::endl;
	std::cout << "  Average grade: " << avg;
    return 0;
}

// Function to calculate and store average grade
// takes in pointer to avg (double)

void calculateStudentAverage(void *object, double *avg) {
	double total = 0.0;
	for(int i = 0; i < object->size(); i++){
    	total += object[i];
    }
	*avg = total/(object->size());
}

