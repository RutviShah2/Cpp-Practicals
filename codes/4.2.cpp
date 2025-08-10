#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}
    void displayPerson() {
        std::cout << "Name: " << name << ", Age: " << age << "\n";
    }
};

class Employee : public Person {
protected:
    int empID;

public:
    Employee(std::string n, int a, int id) : Person(n, a), empID(id) {}
    void displayEmployee() {
        displayPerson();
        std::cout << "Employee ID: " << empID << "\n";
    }

    int getID() {
        return empID;
    }
};

class Manager : public Employee {
    std::string department;

public:
    Manager(std::string n, int a, int id, std::string dept) : Employee(n, a, id), department(dept) {}
    void displayManager() {
        displayEmployee();
        std::cout << "Department: " << department << "\n";
    }
};

void handleStaticManagers() {
    const int n = 3;
    Manager managers[n] = {
        Manager("Alice", 35, 101, "HR"),
        Manager("Bob", 42, 102, "IT"),
        Manager("Charlie", 38, 103, "Finance")
    };

    for (int i = 0; i < n; ++i) {
        managers[i].displayManager();
        std::cout << "\n";
    }
}

int main() {
    handleStaticManagers();
    return 0;
}
