#include "ASSIGNMENT_5_student.h"

vector<Student> students;

Student::Student(int i, string n, int a, string c)
{
    id = i;
    name = n;
    age = a;
    course = c;
}

int Student::getID()
{
    return id;
}

string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

string Student::getCourse()
{
    return course;
}

void Student::setName(string n)
{
    name = n;
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setCourse(string c)
{
    course = c;
}

void addStudent()
{
    int id, age;
    string name, course;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Course: ";
    cin >> course;

    Student s(id, name, age, course);
    students.push_back(s);

    cout << "Student Added Successfully\n";
}

void displayStudents()
{
    if (students.empty())
    {
        cout << "No Students Found\n";
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        cout << "\nID: " << students[i].getID();
        cout << "\nName: " << students[i].getName();
        cout << "\nAge: " << students[i].getAge();
        cout << "\nCourse: " << students[i].getCourse();
        cout << "\n------------------\n";
    }
}

void searchStudent()
{
    int id;
    cout << "Enter ID to Search: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == id)
        {
            cout << "Student Found\n";
            cout << "Name: " << students[i].getName() << endl;
            cout << "Age: " << students[i].getAge() << endl;
            cout << "Course: " << students[i].getCourse() << endl;
            return;
        }
    }

    cout << "Student Not Found\n";
}

void updateStudent()
{
    int id;
    cout << "Enter ID to Update: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == id)
        {
            string name, course;
            int age;

            cout << "Enter New Name: ";
            cin >> name;

            cout << "Enter New Age: ";
            cin >> age;

            cout << "Enter New Course: ";
            cin >> course;

            students[i].setName(name);
            students[i].setAge(age);
            students[i].setCourse(course);

            cout << "Updated Successfully\n";
            return;
        }
    }

    cout << "Student Not Found\n";
}

void deleteStudent()
{
    int id;
    cout << "Enter ID to Delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == id)
        {
            students.erase(students.begin() + i);
            cout << "Deleted Successfully\n";
            return;
        }
    }

    cout << "Student Not Found\n";
}