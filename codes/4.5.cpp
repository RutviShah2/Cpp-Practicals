#include <iostream>
#include <string>

class Student {
protected:
    std::string name;
    int marks;

public:
    Student(std::string n, int m) : name(n), marks(m) {}
    virtual ~Student() {}
    virtual char computeGrade() = 0;

    void display() {
        std::cout << "Name: " << name << ", Marks: " << marks << ", Grade: " << computeGrade() << "\n";
    }
};

class Undergraduate : public Student {
public:
    Undergraduate(std::string n, int m) : Student(n, m) {}

    char computeGrade() override {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }
};

class Postgraduate : public Student {
public:
    Postgraduate(std::string n, int m) : Student(n, m) {}

    char computeGrade() override {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else return 'F';
    }
};

int main() {
    const int n = 4;
    Student* students[n] = {
        new Undergraduate("Alice", 78),
        new Undergraduate("Bob", 88),
        new Postgraduate("Clara", 76),
        new Postgraduate("David", 59)
    };

    for (int i = 0; i < n; ++i) {
        students[i]->display();
    }

    for (int i = 0; i < n; ++i) {
        delete students[i];
    }

    return 0;
}
