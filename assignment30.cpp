#include <iostream>
#include <deque>
#include <string>
#include <stdexcept>
using namespace std;
template <typename T>class Queue {private:
    deque<T> data;
public:
    void enqueue(const T& val) {
        data.push_back(val);
    }

    void dequeue() {
        if (data.empty()) {
            throw out_of_range("Queue is empty");
        }
        data.pop_front();
    }

    T front() const {
        if (data.empty()) {
            throw out_of_range("Queue is empty");
        }
        return data.front();
    }

    bool empty() const {
        return data.empty();
    }
};
int main() {
    Queue<string> q;
    q.enqueue("First");
    q.enqueue("Second");
    q.enqueue("Third");

    cout << "Front element: " << q.front() << endl; // Outputs: First
    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl; // Outputs: Second

    return 0;
}