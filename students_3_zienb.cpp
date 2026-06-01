#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
};

int main() {

    int choice;

    while (true) {

        cout << "\n1 Display All\n";
        cout << "2 Search\n";
        cout << "3 Update\n";
        cout << "4 Delete\n";
        cout << "5 Exit\n";
        cin >> choice;

        if (choice == 5) break;

        int roll;
        cout << "Enter Roll Number: ";
        cin >> roll;

        ifstream file("students.txt");
        ofstream temp("temp.txt");

        Student s;
        bool found = false;

        while (file >> s.roll >> s.name >> s.age) {

            if (s.roll == roll) {
                found = true;

                if (choice == 2) {
                    cout << s.roll << " " << s.name << " " << s.age << endl;
                    temp << s.roll << " " << s.name << " " << s.age << endl;
                }

                else if (choice == 3) {
                    cout << "Enter new name: ";
                    cin >> s.name;
                    cout << "Enter new age: ";
                    cin >> s.age;

                    temp << s.roll << " " << s.name << " " << s.age << endl;
                }

                else if (choice == 4) {
                    cout << "Record deleted\n";
                }
            }
            else {
                temp << s.roll << " " << s.name << " " << s.age << endl;
            }
        }

        file.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (!found)
            cout << "Student not found\n";
    }

    return 0;
}