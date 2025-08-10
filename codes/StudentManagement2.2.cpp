#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks1, marks2, marks3;

public:
    Student() {
        roll = 0;
        name = "Default";
        marks1 = marks2 = marks3 = 0;
    }

    Student(int r, string n, float m1, float m2, float m3) {
        roll = r;
        name = n;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }

    float getAverage() {
        return (marks1 + marks2 + marks3) / 3;
    }

    void display() {
        cout << "Roll No: " << roll << ", Name: " << name << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
        cout << "Average: " << getAverage() << endl;
        cout << "---------------------------" << endl;
    }
};

int main() {
    Student s1;
    Student s2(101, "Riya", 85, 90, 88);
    Student s3(102, "Aarav", 75, 80, 70);
    Student s4(103, "Meera", 95, 92, 96);

    s1.display();
    s2.display();
    s3.display();
    s4.display();

    return 0;
}
