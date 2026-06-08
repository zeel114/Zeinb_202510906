#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class User {
private:
    string name;
    string email;
    string phoneNumber;

public:
    User() {
        name = "zainb elgizoli";
        email = "zeel09228@gmail.com";
        phoneNumber = "0796509980";
    }
    
    User(string n, string e, string phone) {
        name = n;
        email = e;
        phoneNumber = phone;
    }

    string getName() { return name; }
    void setName(string n) { name = n; }

    string getEmail() { return email; }
    void setEmail(string e) { email = e; }

    string getPhoneNumber() { return phoneNumber; }
    void setPhoneNumber(string phone) { phoneNumber = phone; }
};

class VehicleOwner : public User {
public:
    VehicleOwner() : User() {}
    VehicleOwner(string n, string e, string phone) : User(n, e, phone) {}
};

class Vehicle {
private:
    string plateNumber;
    string vehicleType;
    long long universityID;
    VehicleOwner owner;

public:
    Vehicle() {
        plateNumber = "";
        vehicleType = "";
        universityID = 202510906;
    }

    Vehicle(string plate, string type, long long id, VehicleOwner o) {
        plateNumber = plate;
        vehicleType = type;
        universityID = id;
        owner = o;
    }

    string getPlateNumber() { return plateNumber; }
    void setPlateNumber(string plate) { plateNumber = plate; }

    string getVehicleType() { return vehicleType; }
    void setVehicleType(string type) { vehicleType = type; }

    long long getUniversityID() { return universityID; }
    void setUniversityID(long long id) { universityID = id; }

    VehicleOwner getOwner() { return owner; }
    void setOwner(VehicleOwner o) { owner = o; }
};

bool checkEmail(string email) {
    bool hasAt = false;
    bool hasDot = false;

    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') hasAt = true;
        if (email[i] == '.') hasDot = true;
    }

    if (hasAt && hasDot && email.length() > 4) {
        return true;
    }
    return false;
}

bool checkPhone(string phone) {
    if (phone.length() != 13) return false;
    if (phone[0] != '+' || phone[1] != '2' || phone[2] != '5' || phone[3] != '0') return false;

    for (int i = 4; i < 13; i++) {
        if (phone[i] < '0' || phone[i] > '9') return false;
    }
    return true;
}

bool checkPlate(string plate) {
    if (plate.length() != 7) return false;

    for (int i = 0; i < 3; i++) {
        if (!((plate[i] >= 'A' && plate[i] <= 'Z') || (plate[i] >= 'a' && plate[i] <= 'z'))) return false;
    }
    for (int i = 3; i < 6; i++) {
        if (plate[i] < '0' || plate[i] > '9') return false;
    }
    if (!((plate[6] >= 'A' && plate[6] <= 'Z') || (plate[6] >= 'a' && plate[6] <= 'z'))) return false;

    return true;
}

void addRecord() {
    string plate, type, name, email, phone;
    long long id;

    cout << "\n--- Add New Record ---\n";

    while (true) {
        cout << "Enter Plate Number (e.g., RAA123A): ";
        cin >> plate;
        if (checkPlate(plate)) break;
        cout << "Invalid format! Try again.\n";
    }

    cout << "Enter Vehicle Type: ";
    cin >> type;

    cout << "Enter University ID (9 digits): ";
    cin >> id;

    cout << "Enter Owner Name: ";
    cin.ignore();
    getline(cin, name);

    while (true) {
        cout << "Enter Email Address: ";
        cin >> email;
        if (checkEmail(email)) break;
        cout << "Invalid email! Must contain '@' and '.'.\n";
    }

    while (true) {
        cout << "Enter Phone Number (starts with +250, 13 digits total): ";
        cin >> phone;
        if (checkPhone(phone)) break;
        cout << "Invalid phone number! Try again.\n";
    }

    VehicleOwner owner(name, email, phone);
    Vehicle vehicle(plate, type, id, owner);

    ofstream myfile;
    myfile.open("records.txt", ios::app);
    if (myfile.is_open()) {
        myfile << plate << "," << type << "," << id << "," << name << "," << email << "," << phone << "\n";
        myfile.close();
        cout << "Record saved successfully!\n";
    } else {
        cout << "Failed to open file!\n";
    }
}

void displayAll() {
    ifstream myfile("records.txt");
    if (!myfile.is_open()) {
        cout << "No records found or file does not exist.\n";
        return;
    }

    string line;
    cout << "\n---------------------------------------------------------------------------------\n";
    cout << "Plate\t| Type\t| Student ID\t| Owner Name\t| Email Address\t\t| Phone\n";
    cout << "---------------------------------------------------------------------------------\n";

    while (getline(myfile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string plate, type, idStr, name, email, phone;

        getline(ss, plate, ',');
        getline(ss, type, ',');
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');

        long long id;
        stringstream convert(idStr);
        convert >> id;

        cout << plate << "\t| " << type << "\t| " << id << "\t| " << name << "\t| " << email << "\t| " << phone << "\n";
    }
    cout << "---------------------------------------------------------------------------------\n";
    myfile.close();
}

void searchRecord() {
    string searchPlate;
    cout << "\nEnter Plate Number to search: ";
    cin >> searchPlate;

    ifstream myfile("records.txt");
    string line;
    bool found = false;

    while (getline(myfile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string plate, type, idStr, name, email, phone;

        getline(ss, plate, ',');
        getline(ss, type, ',');
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');

        if (plate == searchPlate) {
            found = true;
            cout << "\n=== Record Found ===\n";
            cout << "Plate Number : " << plate << "\n";
            cout << "Vehicle Type : " << type << "\n";
            cout << "Student ID   : " << idStr << "\n";
            cout << "Owner Name   : " << name << "\n";
            cout << "Email Address: " << email << "\n";
            cout << "Phone Number : " << phone << "\n";
            cout << "====================\n";
            break;
        }
    }

    if (!found) {
        cout << "\nRecord not found in the system.\n";
    }
    myfile.close();
}

int main() {
    int choice;

    do {
        cout << "\n--- Vehicle Management System ---\n";
        cout << "1. Add New Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}