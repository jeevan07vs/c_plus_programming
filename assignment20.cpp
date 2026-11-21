#include <iostream>
#include <string>

using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}

    void displayBase() const {
        cout << "Name: " << name << ", ID: " << id;
    }
    int main() {
        return 0;
    }
};

// Derived class 1
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int i, int size) : Employee(n, i), teamSize(size) {}

    void printDetails() const {
        cout << "[Manager] ";
        displayBase();
        cout << ", Team Size: " << teamSize << endl;
    }
};

// Derived class 2
class Engineer : public Employee {
private:
    string skill;

public:
    Engineer(string n, int i, string s) : Employee(n, i), skill(s) {}

    void printDetails() const {
        cout << "[Engineer] ";
        displayBase();
        cout << ", Primary Skill: " << skill << endl;
    }
};

int main() {
    Manager mgr("Alice", 101, 12);
    Engineer eng("Bob", 102, "C++ Systems");

    mgr.printDetails();
    eng.printDetails();

    return 0;
}
