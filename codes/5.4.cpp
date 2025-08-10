#include <iostream>

class Fahrenheit;

class Celsius {
private:
    double temperature;
public:
    Celsius(double temp) : temperature(temp) {}
    double toFahrenheit() {
        return (temperature * 9/5) + 32;
    }
    double getTemperature() {
        return temperature;
    }
    void display() {
        std::cout << "Celsius Temperature: " << temperature << "\n";
    }
};

class Fahrenheit {
private:
    double temperature;
public:
    Fahrenheit(double temp) : temperature(temp) {}
    double toCelsius() {
        return (temperature - 32) * 5/9;
    }
    double getTemperature() {
        return temperature;
    }
    void display() {
        std::cout << "Fahrenheit Temperature: " << temperature << "\n";
    }
};

int main() {
    Celsius c(25);
    Fahrenheit f(c.toFahrenheit());

    c.display();
    std::cout << "Converted to Fahrenheit: " << f.getTemperature() << "\n";

    f.display();
    std::cout << "Converted to Celsius: " << c.getTemperature() << "\n";

    if (c.getTemperature() == f.toCelsius()) {
        std::cout << "Temperatures are equal.\n";
    } else {
        std::cout << "Temperatures are not equal.\n";
    }

    Celsius c1(30);
    Fahrenheit f1(c1.toFahrenheit());

    c1.display();
    std::cout << "Converted to Fahrenheit: " << f1.getTemperature() << "\n";

    f1.display();
    std::cout << "Converted to Celsius: " << c1.getTemperature() << "\n";

    if (c1.getTemperature() == f1.toCelsius()) {
        std::cout << "Temperatures are equal.\n";
    } else {
        std::cout << "Temperatures are not equal.\n";
    }

    return 0;
}
