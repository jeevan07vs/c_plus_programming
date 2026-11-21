#include <iostream>
#include <string>

using namespace std;

// Virtual base class
class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {}

    void showName() const {
        cout << "Name: " << name << endl;
    }
};

// Inherit virtually from Person
class Student : virtual public Person {
protected:
    int studentId;

public:
    Student(string n, int sId) : Person(n), studentId(sId) {}
};

// Inherit virtually from Person
class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(string n, int eId) : Person(n), empId(eId) {}
};

// Derived from both Student and Employee
class TA : public Student, public Employee {
private:
    string course;

public:
    // TA explicitly initializes the virtual base class Person
    TA(string n, int sId, int eId, string c)
        : Person(n), Student(n, sId), Employee(n, eId), course(c) {}

    void displayTA() const {
        showName(); // Person appears only once, so no ambiguity
        cout << "Student ID: " << studentId << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Assisting Course: " << course << endl;
    }
};

int main() {
    TA assistant("Charlie", 5001, 9001, "Data Structures");
    assistant.displayTA();
    return 0;
}