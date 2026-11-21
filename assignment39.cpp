#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") 
             << (imag >= 0 ? imag : -imag) << "i\n";
    }
};

int main() {
    Complex nums[3]; // Small array of complex numbers

    nums[0].setData(2.5, 3.0);
    nums[1].setData(4.0, -1.5);
    nums[2].setData(0.0, 5.2);

    for (int i = 0; i < 3; i++) {
        cout << "Complex[" << i << "] = ";
        nums[i].display();
    }
    return 0;
}