#include <iostream>
class Counter {private:
    int count; 
    static int totalCreated;
    static int currentlyAlive;
public:
    
    Counter(int c = 0) : count(c) {
        totalCreated++;
        currentlyAlive++;
    }

    Counter(const Counter& other) : count(other.count) {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    static int getTotalCreated() {
        return totalCreated;
    }

    static int getCurrentlyAlive() {
        return currentlyAlive;
    }
};
int main() {
    Counter c1;
    {
        Counter c2;
        Counter c3 = c1;
        std::cout << "Created: " << Counter::getTotalCreated() << "\n"; // 3
        std::cout << "Alive: " << Counter::getCurrentlyAlive() << "\n"; // 3
    } 

    std::cout << "Created: " << Counter::getTotalCreated() << "\n";     // 3
    std::cout << "Alive: " << Counter::getCurrentlyAlive() << "\n";     // 1

    return 0;
}