#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan {
private:
    int loanId;
    string applicantName;
    double amount;
    double annualRate;
    int months;

public:
    Loan() {
        loanId = 0;
        applicantName = "Default";
        amount = 0.0;
        annualRate = 0.0;
        months = 0;
    }

    Loan(int id, string name, double amt, double rate, int m) {
        loanId = id;
        applicantName = name;
        amount = amt;
        annualRate = rate;
        months = m;
    }

    double calculateEMI() {
        double monthlyRate = (annualRate / 12) / 100;
        return (amount * monthlyRate * pow(1 + monthlyRate, months)) / (pow(1 + monthlyRate, months) - 1);
    }

    void display() {
        cout << "Loan ID: " << loanId << endl;
        cout << "Applicant: " << applicantName << endl;
        cout << "Loan Amount: $" << amount << endl;
        cout << "Interest Rate (Annual): " << annualRate << "%" << endl;
        cout << "Tenure: " << months << " months" << endl;
        cout << "EMI: $" << calculateEMI() << endl;
        cout << "---------------------------" << endl;
    }
};

int main() {
    Loan l1;
    Loan l2(101, "Aisha Khan", 50000, 7.5, 24);
    Loan l3(102, "Rohit Mehra", 120000, 6.8, 60);

    l1.display();
    l2.display();
    l3.display();

    return 0;
}
