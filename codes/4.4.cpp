#include <iostream>
#include <string>

class BankAccount {
protected:
    int accountNumber;
    double balance;
    double transactions[100];
    int transactionCount;

public:
    BankAccount(int accNo, double bal) : accountNumber(accNo), balance(bal), transactionCount(0) {}
    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        balance += amount;
        transactions[transactionCount++] = amount;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
        transactions[transactionCount++] = -amount;
    }

    void undoLastTransaction() {
        if (transactionCount > 0) {
            balance -= transactions[--transactionCount];
        }
    }

    virtual void display() {
        std::cout << "Account No: " << accountNumber << ", Balance: " << balance << "\n";
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accNo, double bal, double rate) : BankAccount(accNo, bal), interestRate(rate) {}

    void display() override {
        BankAccount::display();
        std::cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;

public:
    CurrentAccount(int accNo, double bal, double limit) : BankAccount(accNo, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            transactions[transactionCount++] = -amount;
        }
    }

    void display() override {
        BankAccount::display();
        std::cout << "Overdraft Limit: " << overdraftLimit << "\n";
    }
};

int main() {
    SavingsAccount sa(1001, 5000, 3.5);
    CurrentAccount ca(2001, 3000, 1000);

    sa.deposit(1000);
    sa.withdraw(500);
    sa.undoLastTransaction();
    sa.display();

    std::cout << "\n";

    ca.withdraw(3500);
    ca.deposit(1000);
    ca.undoLastTransaction();
    ca.display();

    return 0;
}
