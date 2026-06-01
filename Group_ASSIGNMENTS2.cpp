#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
};

int main() {

    int choice;
    bool exitProgram = false;

    while (!exitProgram) {

        cout << "\n1.Search\n";
        cout << "2.Update\n";
        cout << "3.Edit\n";
        cout << "4.Delete\n";
        cout << "5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Program closed\n";
            break;
        }

        int searchRoll;
        bool found = false;

        cout << "Enter roll number: ";
        cin >> searchRoll;

        ifstream in("students.txt");
        ofstream temp("temp.txt");

        Student s;

        while (in >> s.roll >> s.name >> s.age) {

            if (s.roll == searchRoll) {

                found = true;

                if (choice == 1) {
                    cout << "Found: "
                         << s.roll << " "
                         << s.name << " "
                         << s.age << endl;

                    temp << s.roll << " "
                         << s.name << " "
                         << s.age << endl;
                }

                else if (choice == 2 || choice == 3) {

                    cout << "Enter new name: ";
                    cin >> s.name;

                    cout << "Enter new age: ";
                    cin >> s.age;

                    temp << s.roll << " "
                         << s.name << " "
                         << s.age << endl;

                    cout << "Updated\n";
                }

                else if (choice == 4) {
                    cout << "Deleted\n";
                }
            }
            else {
                temp << s.roll << " "
                     << s.name << " "
                     << s.age << endl;
            }
        }

        in.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (!found)
            cout << "Student not found\n";
    }

    return 0;
}


//Group ASSIGNMENTS2
//Mohammed=202511222
//Zienb=202510906