#include <iostream>
#include <cmath>

class Shape {
protected:
    double radius;

public:
    Shape(double r = 0.0) : radius(r) {}
    void setRadius(double r) { radius = r; }
    double getRadius() const { return radius; }
};

class Circle : public Shape {
public:
    Circle(double r = 0.0) : Shape(r) {}
    double getArea() const { return M_PI * radius * radius; }
};

void handleDynamicCircles() {
    int n;
    std::cin >> n;
    Circle* circles = new Circle[n];
    for (int i = 0; i < n; ++i) {
        double r;
        std::cin >> r;
        circles[i].setRadius(r);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << circles[i].getArea() << "\n";
    }
    delete[] circles;
}

void handleStaticCircles() {
    const int n = 3;
    Circle circles[n] = { Circle(1.0), Circle(2.5), Circle(3.75) };
    for (int i = 0; i < n; ++i) {
        std::cout << circles[i].getArea() << "\n";
    }
}

int main() {
    handleDynamicCircles();
    handleStaticCircles();
    return 0;
}
