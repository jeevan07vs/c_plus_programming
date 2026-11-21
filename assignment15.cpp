#include <iostream>
#include <iomanip>

class Time {
private:
    int hours;
    int minutes;
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void display() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes;
    }

    // Declare laterOf as a friend function
    friend Time laterOf(const Time& t1, const Time& t2);
};

// Define the friend function outside the class (no Time:: scope needed)
Time laterOf(const Time& t1, const Time& t2) {
    if (t1.hours > t2.hours) {
        return t1;
    } else if (t1.hours < t2.hours) {
        return t2;
    } else {
        // Hours are equal, so compare minutes
        return (t1.minutes >= t2.minutes) ? t1 : t2;
    }
}
int main() {
    Time morning(9, 45);
    Time afternoon(14, 20);

    Time later = laterOf(morning, afternoon);
    std::cout << "The later time is: ";
    later.display(); // Outputs 14:20
    std::cout << "\n";

    return 0;
}
