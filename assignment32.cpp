#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    vector<pair<string, int>> items = {
        {"Alice", 85},
        {"Bob", 72},
        {"Charlie", 95},
        {"Diana", 68}
    };

    // Sort ascending by the second element (.second)
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    // Print the sorted pairs
    for (const auto& p : items) {
        cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}