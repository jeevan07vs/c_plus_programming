#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    if (!inFile || !outFile) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(inFile, line)) {
        outFile << lineNumber << ": " << line << "\n";
        lineNumber++;
    }

    inFile.close();
    outFile.close();

    cout << "File copied successfully with line numbers." << endl;
    return 0;
}
