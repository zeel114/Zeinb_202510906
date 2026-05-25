#ifndef STUDENT_ZEINB_H
#define STUDENT_ZEINB_H

#include <string>

struct Student {
    int id;
    std::string name;
    int age;
    std::string course;
};

void addStudent(Student students[], int &count);
void displayStudents(const Student students[], int count);
void searchStudent(const Student students[], int count);
void updateStudent(Student students[], int count);
void deleteStudent(Student students[], int &count);

#endif
