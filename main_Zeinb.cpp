#include <iostream>
#include "student_Zeinb.h"

using namespace std;

int main() {
    Student students[100];
    int count = 0;
    int choice;
    do {
        cout << "\n0 Swap demo\n1 Add\n2 Display\n3 Search\n4 Update\n5 Delete\n6 Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 0: {
                int a, b;
                cout << "a: "; cin >> a;
                cout << "b: "; cin >> b;
                cout << "before " << a << " " << b << '\n';
                int *pa = &a, *pb = &b;
                int t = *pa; *pa = *pb; *pb = t;
                cout << "after " << a << " " << b << '\n';
                break;
            }
            case 1: addStudent(students, count); break;
            case 2: displayStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: updateStudent(students, count); break;
            case 5: deleteStudent(students, count); break;
            case 6: cout << "Exit\n"; break;
            default: cout << "Invalid\n";
        }
    } while (choice != 6);
    return 0;
}