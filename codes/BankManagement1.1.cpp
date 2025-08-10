#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    void setDetails(string accName, int accNum, double initialBalance) {
        name = accName;
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void showBalance() {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount customer;

    customer.setDetails("Rutvi Shah", 1001, 5000.0);
    customer.deposit(1200.0);
    customer.withdraw(2000.0);
    customer.withdraw(5000.0);
    customer.showBalance();

    return 0;
}
