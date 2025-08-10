#include <iostream>
#include <string>

class FuelType {
protected:
    std::string fuel;

public:
    FuelType(std::string f) : fuel(f) {}
    void displayFuel() {
        std::cout << "Fuel Type: " << fuel << "\n";
    }
};

class Brand {
protected:
    std::string brandName;

public:
    Brand(std::string b) : brandName(b) {}
    void displayBrand() {
        std::cout << "Brand: " << brandName << "\n";
    }
};

class Car : public FuelType, public Brand {
public:
    Car(std::string f, std::string b) : FuelType(f), Brand(b) {}
    void displayCar() {
        displayBrand();
        displayFuel();
    }
};

void processCarQueue() {
    const int n = 3;
    Car cars[n] = {
        Car("Petrol", "Toyota"),
        Car("Diesel", "Ford"),
        Car("Electric", "Tesla")
    };

    for (int i = 0; i < n; ++i) {
        std::cout << "Car " << i + 1 << " Details:\n";
        cars[i].displayCar();
        std::cout << "\n";
    }
}

int main() {
    processCarQueue();
    return 0;
}
