#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;
    static int totalAccounts;

public:
    Account(int number, string name, double bal) {
        accountNumber = number;
        holderName = name;
        balance = bal;
        totalAccounts++;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: $" << balance << endl;
        cout << "--------------------------" << endl;
    }

    bool transferTo(Account &receiver, double amount) {
        if (balance >= amount) {
            balance -= amount;
            receiver.balance += amount;
            return true;
        } else {
            return false;
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

int Account::totalAccounts = 0;

int main() {
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    Account* accounts[n];

    for (int i = 0; i < n; i++) {
        int accNo;
        string name;
        double balance;

        cout << "Enter details for account " << i + 1 << endl;
        cout << "Account Number: ";
        cin >> accNo;
        cout << "Holder Name: ";
        cin >> name;
        cout << "Initial Balance: ";
        cin >> balance;

        accounts[i] = new Account(accNo, name, balance);
    }

    cout << "\nAll Account Details:\n";
    for (int i = 0; i < n; i++) {
        accounts[i]->display();
    }

    int senderNo, receiverNo;
    double amount;

    cout << "\nEnter sender account number: ";
    cin >> senderNo;
    cout << "Enter receiver account number: ";
    cin >> receiverNo;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    Account *sender = nullptr, *receiver = nullptr;

    for (int i = 0; i < n; i++) {
        if (accounts[i]->getAccountNumber() == senderNo)
            sender = accounts[i];
        if (accounts[i]->getAccountNumber() == receiverNo)
            receiver = accounts[i];
    }

    if (sender && receiver) {
        if (sender->transferTo(*receiver, amount)) {
            cout << "Transfer successful.\n";
        } else {
            cout << "Insufficient balance. Transfer failed.\n";
        }
    } else {
        cout << "Invalid account numbers entered.\n";
    }

    cout << "\nUpdated Account Details:\n";
    for (int i = 0; i < n; i++) {
        accounts[i]->display();
        delete accounts[i];
    }

    cout << "Total Accounts Created: " << Account::getTotalAccounts() << endl;

    return 0;
}
