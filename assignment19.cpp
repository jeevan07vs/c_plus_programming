#include <iostream>
#include <stdexcept>

using namespace std;

class SafeArray {
private:
    int* arr;
    int size;
public:
    SafeArray(int s) : size(s) {
        if (s <= 0) throw invalid_argument("Size must be positive.");
        arr = new int[size](); // Zero-initialized
    }

    // Destructor to prevent memory leaks
    ~SafeArray() {
        delete[] arr;
    }

    // Overload [] for modification
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds!");
        }
        return arr[index];
    }

    // Overload [] for read-only access on const objects
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds!");
        }
        return arr[index];
    }
};
int main() {
    SafeArray a(5);

    try {
        a[0] = 10;
        a[4] = 50;
        cout << "a[4] = " << a[4] << endl;

        // Attempt out-of-range access
        cout << a[5] << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
