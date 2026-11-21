#include <iostream>
using namespace std;
class Complex {private:
    double real;
    double imag;
public:
    // Default constructor
    Complex() : real(0.0), imag(0.0) {}

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " - " << -imag << "i" << endl;
        }
    }
};
int main() {
    // Create a small array of complex numbers
    Complex numbers[3];

    numbers[0].setData(2.5, 3.0);
    numbers[1].setData(-1.0, 4.5);
    numbers[2].setData(3.0, -2.0);

    // Print the array
    for (int i = 0; i < 3; i++) {
        cout << "Complex[" << i << "]: ";
        numbers[i].display();
    }

    return 0;
}
