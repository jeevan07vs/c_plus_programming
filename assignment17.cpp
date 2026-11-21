#include <iostream>
using namespace std;
class Money {private:
    int rupees;
    int paise;

    // Helper function to normalize paise into rupees
    void normalize() {
        if (paise >= 100) {
            rupees += paise / 100;
            paise %= 100;
        } else if (paise < 0) {
            int borrow = (-paise + 99) / 100;
            rupees -= borrow;
            paise += borrow * 100;
        }
    }
public:
    Money(int r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    // Overload + operator
    Money operator+(const Money& other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    // Overload - operator
    Money operator-(const Money& other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    void display() const {
        std::cout << "Rs. " << rupees << "." << (paise < 10 ? "0" : "") << paise << std::endl;
    }
};
int main() {
    Money m1(10, 75);
    Money m2(5, 50);

    Money sum = m1 + m2;
    Money diff = m1 - m2;

    std::cout << "Sum: "; sum.display();   // Rs. 16.25
    std::cout << "Diff: "; diff.display(); // Rs. 5.25
    return 0;
}
