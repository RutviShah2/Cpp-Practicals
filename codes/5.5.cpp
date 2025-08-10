#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double Area() = 0;
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Shape* shape1 = new Rectangle(4, 5);
    Shape* shape2 = new Circle(3);

    std::cout << "Area of Rectangle: " << shape1->Area() << std::endl;
    std::cout << "Area of Circle: " << shape2->Area() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}
