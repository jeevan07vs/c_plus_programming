#include <iostream>
#include <stdexcept>
#include <string>

class MathError : public std::runtime_error {
public:
    explicit MathError(const std::string& msg = "General Math Error")
        : std::runtime_error(msg) {}
};

class DivideByZero : public MathError {
public:
    DivideByZero() : MathError("Division by zero is undefined.") {}
};

double divide(double a, double b) {
    if (b == 0) {
        throw DivideByZero();
    }
    return a / b;
}

int main() {
    // Catch the most specific exception before its base class.
    try {
        divide(10, 0);
    } catch (const DivideByZero& e) {
        std::cout << "[Caught by DivideByZero]: " << e.what() << '\n';
    } catch (const MathError& e) {
        std::cout << "[Caught by MathError]: " << e.what() << '\n';
    }

    return 0;
}