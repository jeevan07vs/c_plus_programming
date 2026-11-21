#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    // Min-heap to keep track of the top 3 largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        minHeap.push(val);
        
        // If size exceeds 3, remove the smallest of the top candidates
        if (minHeap.size() > 3) {
            minHeap.pop();
        }
    }

    cout << "Top 3 largest (in ascending order): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n";

    return 0;
}
