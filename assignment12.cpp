#include <iostream>#include <stdexcept>
class Stack {private:
    int* buffer;
    int capacity;
    int topIndex;
public:
    // Constructor: allocates the dynamic array buffer
    Stack(int cap) : capacity(cap), topIndex(-1) {
        buffer = new int[capacity];
    }

    // Destructor: releases the dynamic buffer
    ~Stack() {
        delete[] buffer;
    }

    // Push an element onto the stack
    void push(int value) {
        if (topIndex >= capacity - 1) {
            throw std::overflow_error("Stack overflow");
        }
        buffer[++topIndex] = value;
    }

    // Pop and return the top element
    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return buffer[topIndex--];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};
int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Popped: " << s.pop() << "\n"; // Outputs 30
    std::cout << "Popped: " << s.pop() << "\n"; // Outputs 20

    return 0; // Destructor frees the buffer
}
