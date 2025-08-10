#include <iostream>
using namespace std;

// Custom exception class
class InsufficientFundsException {
public:
    const char* what() const {
        return "Error: Withdrawal amount exceeds current balance.";
    }
};

class BankAccount {
private:
    double balance;
    string transactionLog[100];
    int logCount;

public:
    BankAccount() {
        balance = 0;
        logCount = 0;
    }

    void logTransaction(const string& log) {
        if (logCount < 100) {
            transactionLog[logCount++] = log;
        }
    }

    void deposit(double amount) {
        cout << "Entering deposit()\n";
        balance += amount;

        string log = "Deposited: " + to_string(amount);
        logTransaction(log);

        cout << "Deposit successful. New balance: " << balance << endl;
        cout << "Exiting deposit()\n";
    }

    void withdraw(double amount) {
        cout << "Entering withdraw()\n";

        if (amount > balance) {
            throw InsufficientFundsException();
        }

        balance -= amount;
        string log = "Withdrew: " + to_string(amount);
        logTransaction(log);

        cout << "Withdrawal successful. New balance: " << balance << endl;
        cout << "Exiting withdraw()\n";
    }

    void showLogs() {
        cout << "\nTransaction Logs:\n";
        for (int i = 0; i < logCount; ++i) {
            cout << i + 1 << ". " << transactionLog[i] << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

// Function to simulate stack unwinding
void performWithdrawal(BankAccount& account, double amount) {
    cout << "Entering performWithdrawal()\n";
    account.withdraw(amount);
    cout << "Exiting performWithdrawal()\n";
}

void startBanking() {
    cout << "Entering startBanking()\n";
    BankAccount myAccount;
    myAccount.deposit(500);  // Initial deposit

    try {
        performWithdrawal(myAccount, 300);  // Valid
        performWithdrawal(myAccount, 300);  // Will trigger exception
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    }

    myAccount.showLogs();
    cout << "Exiting startBanking()\n";
}

int main() {
    startBanking();
    return 0;
}
