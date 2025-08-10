#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string empName, double salary, double extraBonus = 1000) {
        name = empName;
        basicSalary = salary;
        bonus = extraBonus;
    }

    inline double totalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Salary: $" << totalSalary() << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    int num;
    cout << "Enter number of employees: ";
    cin >> num;

    Employee* employees[num];

    for (int i = 0; i < num; i++) {
        string name;
        double salary, bonus;
        char hasBonus;

        cout << "Enter name of employee " << i + 1 << ": ";
        cin >> name;

        cout << "Enter basic salary: ";
        cin >> salary;

        cout << "Custom bonus? (y/n): ";
        cin >> hasBonus;

        if (hasBonus == 'y' || hasBonus == 'Y') {
            cout << "Enter bonus: ";
            cin >> bonus;
            employees[i] = new Employee(name, salary, bonus);
        } else {
            employees[i] = new Employee(name, salary);
        }
    }

    cout << "\n--- Employee Payroll Details ---\n";
    for (int i = 0; i < num; i++) {
        employees[i]->display();
        delete employees[i];
    }

    return 0;
}
