#include <iostream>
using namespace std;
class Counter {private:
    int count;
public:
    // Constructor initializes count to 0
    Counter() : count(0) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }
};
int main() {
    // Create an array of 3 counters
    Counter counters[3];

    // Exercise the counters
    counters[0].increment();
    counters[0].increment();

    counters[1].increment();
    counters[1].reset();

    counters[2].increment();
    counters[2].increment();
    counters[2].increment();

    // Display results
    for (int i = 0; i < 3; i++) {
        cout << "Counter " << i << ": " << counters[i].get() << endl;
    }

    return 0;
}