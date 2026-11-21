#include <iostream>
using namespace std;

// Template function to swap two values
template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
// Template function to find the maximum element in an array
template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
int main() {
    // Testing with int
    int x = 10, y = 20;
    swapVals(x, y);
    cout << "Swapped ints: x = " << x << ", y = " << y << endl;

    int intArr[] = {4, 15, 9, 27, 12};
    cout << "Max int: " << findMax(intArr, 5) << endl;

    // Testing with double
    double d1 = 3.14, d2 = 9.81;
    swapVals(d1, d2);
    cout << "Swapped doubles: d1 = " << d1 << ", d2 = " << d2 << endl;

    double doubleArr[] = {2.5, 7.8, 1.2, 5.4};
    cout << "Max double: " << findMax(doubleArr, 4) << endl;

    return 0;
}