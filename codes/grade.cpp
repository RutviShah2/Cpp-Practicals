#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    void input() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Student: " << name << endl;
        cout << "Marks: " << marks << endl;

        if (marks >= 90) cout << "Grade: A+";
        else if (marks >= 75) cout << "Grade: A";
        else if (marks >= 60) cout << "Grade: B";
        else cout << "Grade: C";
    }
};

int main() {
    Student s1;
    s1.input();
    s1.display();
    return 0;
}
