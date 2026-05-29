#ifndef ASSIGNMENT_5_STUDENT_H
#define ASSIGNMENT_5_STUDENT_H

#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    int id;
    string name;
    int age;
    string course;

public:
  
    Student(int i, string n, int a, string c);

    int getID();
    string getName();
    int getAge();
    string getCourse();


    void setName(string n);
    void setAge(int a);
    void setCourse(string c);
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif // ASSIGNMENT_5_STUDENT_H