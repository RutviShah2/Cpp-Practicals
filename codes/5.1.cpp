#include <iostream>

class Calculator {
    double results[10];
    int count;

public:
    Calculator() : count(0) {}

    void add(int a, int b) {
        results[count++] = a + b;
    }

    void add(float a, float b) {
        results[count++] = a + b;
    }

    void add(int a, float b) {
        results[count++] = a + b;
    }

    void add(float a, int b) {
        results[count++] = a + b;
    }

    void displayResults() {
        for (int i = 0; i < count; ++i) {
            std::cout << "Result " << i + 1 << ": " << results[i] << "\n";
        }
    }
};

int main() {
    Calculator calc;
    calc.add(5, 3);
    calc.add(4.5f, 2.5f);
    calc.add(7, 3.2f);
    calc.add(2.8f, 6);

    calc.displayResults();

    return 0;
}
