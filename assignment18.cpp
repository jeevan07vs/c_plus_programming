#include <iostream>
#include <numeric> // For std::gcd (C++17)
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int num;
    int den;

    void simplify() {
        if (den == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        // Keep the negative sign in the numerator
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int common = gcd(abs(num), abs(den));
        num /= common;
        den /= common;
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    // Overload << for output
    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.num << "/" << f.den;
        return out;
    }

    // Overload >> for input (expects format: num den)
    friend istream& operator>>(istream& in, Fraction& f) {
        in >> f.num >> f.den;
        f.simplify();
        return in;
    }
};
int main() {
    Fraction f1(12, 16);
    cout << "Auto-simplified f1: " << f1 << endl; // Outputs 3/4

    Fraction f2;
    cout << "Enter numerator and denominator: ";
    cin >> f2;
    cout << "Simplified input: " << f2 << endl;
    return 0;
}