#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student {public:
    string name;
    int marks;
};
int main() {
    // 1. Write sample records to file
    ofstream outFile("students.txt");
    outFile << "Alice 88\n";
    outFile << "Bob 95\n";
    outFile << "Charlie 91\n";
    outFile.close();

    // 2. Read records back into an array of Student objects
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening students.txt" << endl;
        return 1;
    }

    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int count = 0;

    while (count < MAX_STUDENTS && (inFile >> students[count].name >> students[count].marks)) {
        count++;
    }
    inFile.close();

    // 3. Find and print the topper
    if (count > 0) {
        int topperIndex = 0;
        for (int i = 1; i < count; i++) {
            if (students[i].marks > students[topperIndex].marks) {
                topperIndex = i;
            }
        }
        cout << "Topper: " << students[topperIndex].name 
             << " with " << students[topperIndex].marks << " marks." << endl;
    } else {
        cout << "No student records found." << endl;
    }

    return 0;
}