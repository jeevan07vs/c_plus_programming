#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    unordered_map<string, int> freq;
    string word;

    cout << "Enter words (press Ctrl+D on Linux/Mac or Ctrl+Z then Enter on Windows to finish):" << endl;
    while (cin >> word) {
        freq[word]++;
    }

    string mostFrequent;
    int maxCount = 0;

    cout << "\nWord Frequencies:" << endl;
    for (const auto& pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }

    if (!mostFrequent.empty()) {
        cout << "\nMost frequent word: " << mostFrequent << " (" << maxCount << " times)" << endl;
    }

    return 0;
}