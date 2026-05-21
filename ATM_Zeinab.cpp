#include <iostream>
#include <string>
using namespace std;

int bal = 0;
string logs[40];
int logCount = 0;

void seeBalance() {
    cout << "Your balance: " << bal << endl;
}

void addMoney() {
    int a;
    cout << "Amount: ";
    cin >> a;
    bal += a;
    logs[logCount] = "Added " + to_string(a);
    logCount++;
    cout << "Balance: " << bal << endl;
}

void takeMoney() {
    int b;
    cout << "Withdraw: ";
    cin >> b;
    if (b > bal) {
        cout << "No money enough\n";
    } else {
        bal -= b;
        logs[logCount] = "Taken " + to_string(b);
        logCount++;
        cout << "Balance: " << bal << endl;
    }
}

void showLogs() {
    if (logCount == 0) {
        cout << "Empty\n";
    } else {
        for (int i = 0; i < logCount; i++) {
            cout << i+1 << ". " << logs[i] << endl;
        }
    }
}

int main() {
    int pin, left = 3;
    int def = 2222;
    while (left > 0) {
        cout << "Enter pin: ";
        cin >> pin;
        if (pin == def) {
            int op;
            do {
                cout << "\nMenu\n1.Balance\n2.Deposit\n3.Withdraw\n4.Logs\n5.Exit\n";
                cin >> op;
                if (op == 1) seeBalance();
                else if (op == 2) addMoney();
                else if (op == 3) takeMoney();
                else if (op == 4) showLogs();
                else if (op == 5) cout << "Exit\n";
                else cout << "Wrong\n";
            } while (op != 5);
            break;
        } else {
            left--;
            cout << "Wrong pin, left: " << left << endl;
        }
    }
    if (left == 0) cout << "ATM blocked\n";
    return 0;
}