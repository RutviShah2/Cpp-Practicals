#include <iostream>
using namespace std;

class BankAccount {
private:
    string name;
    int acc_no;
    float balance;

public:
    void openAccount(string n, int acc, float bal) {
        name = n;
        acc_no = acc;
        balance = bal;
    }

    void deposit(float amt) {
        balance += amt;
        cout << "Deposited ₹" << amt << ". New Balance: ₹" << balance << endl;
    }

    void withdraw(float amt) {
        if (amt > balance)
            cout << "Insufficient Balance!" << endl;
        else {
            balance -= amt;
            cout << "Withdrawn ₹" << amt << ". New Balance: ₹" << balance << endl;
        }
    }

    void display() {
        cout << "Account Holder: " << name << endl;
        cout << "Account No: " << acc_no << endl;
        cout << "Balance: ₹" << balance << endl;
    }
};

int main() {
    BankAccount acc;
    acc.openAccount("Rutvii", 1001, 5000);
    acc.display();
    acc.deposit(1500);
    acc.withdraw(2000);
    acc.display();
    return 0;
}
