#include <iostream>
class Order {private:
    int orderID;
    static int nextID;
public:
    // Constructor assigns the current nextID, then increments it
    Order() {
        orderID = nextID++;
    }

    int getID() const {
        return orderID;
    }
};
// Start the ID sequence at 1001int Order::nextID = 1001;
int main() {
    Order o1;
    Order o2;
    Order o3;

    std::cout << "Order 1 ID: " << o1.getID() << "\n"; // 1001
    std::cout << "Order 2 ID: " << o2.getID() << "\n"; // 1002
    std::cout << "Order 3 ID: " << o3.getID() << "\n"; // 1003

    return 0;
}