#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : public Person {
private:
    string subject;

public:
    void setTeacher(string n, int a, string s) {
        setPerson(n, a);
        subject = s;
    }

    void displayTeacher() {
        displayPerson();
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    Teacher t;
    t.setTeacher("Rutvii", 18, "C++ Programming");
    t.displayTeacher();

    return 0;
}
