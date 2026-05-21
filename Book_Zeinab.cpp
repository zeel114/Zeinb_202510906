#include <iostream>
#include <fstream>
using namespace std;

void showHistory() {
    cout << "History of C++\n";
    ifstream f("cpp.txt");
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            cout << line << endl;
        }
        f.close();
    } else {
        cout << "No file\n";
    }
}

void learn() {
    cout << "Concepts: Data Types, Control Flow, Loops, Arrays, Files\n";
}

int main() {
    int x;
    do {
        cout << "\nBook Menu\n1.History\n2.Learn\n3.Exit\n";
        cin >> x;
        switch (x) {
            case 1: showHistory(); break;
            case 2: learn(); break;
            case 3: cout << "End\n"; break;
            default: cout << "Wrong\n";
        }
    } while (x != 3);
    return 0;
}