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
    
    student.id = 123456;
    
    student.f_name = new char[20];
    student.l_name = new char[20];
    strcpy(student.f_name, "Jane");
    strcpy(student.l_name, "Doe");
    
    student.n_assignments = 4;
    
    student.grades = new double[student.n_assignments];
    student.grades[0] = 98.02;
    student.grades[1] = 59.98;
    student.grades[2] = 76.28;
    student.grades[3] = 85.99;

    printf("id: %d, first: %s, last: %s \n", student.id, student.f_name, student.l_name);
    printf("assingments: %d \n", student.n_assignments);
    printf("grades: \n");
    for(int i = 0; i < student.n_assignments; i++){
    	printf("  %.2f \n", student.grades[i]);
    }

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`

    return 0;
}

void calculateStudentAverage(void *object, double *avg) {
    // Code to calculate and store average grade
}
