#include <iostream>
using namespace std;

class Employee {
private:
    int empID;
    string name;
    double salary;

public:
    // Constructor
    Employee(int id, string n, double s) {
        empID = id;
        name = n;
        salary = s;
    }

    void display() {
        cout << "\nEmployee ID: " << empID;
        cout << "\nName: " << name;
        cout << "\nSalary: ₹" << salary << endl;
    }
};

int main() {
    Employee e1(101, "Rutvii", 55000.50);
    Employee e2(102, "Swayam", 60000.75);

    cout << "Employee Details:\n";
    e1.display();
    e2.display();

    return 0;
}
