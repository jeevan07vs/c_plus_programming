#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main() {
    ifstream inFile("nums.txt");
    if (!inFile) {
        cerr << "Error opening nums.txt" << endl;
        return 1;
    }

    int num;
    int count = 0;
    long long sum = 0;
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();

    while (inFile >> num) {
        count++;
        sum += num;
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    inFile.close();

    if (count > 0) {
        cout << "Count: " << count << endl;
        cout << "Sum:   " << sum << endl;
        cout << "Min:   " << minVal << endl;
        cout << "Max:   " << maxVal << endl;
    } else {
        cout << "The file is empty or contains no valid integers." << endl;
    }

    return 0;
}
