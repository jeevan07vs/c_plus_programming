#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main() {
    vector<int> nums = {2, 3, 4, 5, 6};

    // 1. Product of all elements (initial value must be 1, not 0)
    int product = accumulate(nums.begin(), nums.end(), 1, [](int acc, int x) {
        return acc * x;
    });

    // 2. Sum of only the even elements (initial value is 0)
    int evenSum = accumulate(nums.begin(), nums.end(), 0, [](int acc, int x) {
        return (x % 2 == 0) ? (acc + x) : acc;
    });

    cout << "Product of all elements: " << product << "\n"; // 720
    cout << "Sum of even elements: " << evenSum << "\n";   // 12

    return 0;
}