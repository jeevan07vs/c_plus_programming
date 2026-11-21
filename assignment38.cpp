#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
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
    Counter counters[3]; // Array of 3 counters

    // Exercise the counters
    counters[0].increment();
    counters[0].increment();

    counters[1].increment();
    counters[1].reset();

    counters[2].increment();
    counters[2].increment();
    counters[2].increment();

    for (int i = 0; i < 3; i++) {
        cout << "Counter " << i << ": " << counters[i].get() << "\n";
    }
    return 0;
}