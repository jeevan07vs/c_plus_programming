#include <iostream>
#include <string>

using namespace std;

// Level 1: Base class
class Shape {
protected:
    string color;

public:
    Shape(string c) : color(c) {
        cout << "1. Shape constructor called (Color: " << color << ")" << endl;
    }
};

// Level 2: Derived from Shape
class Polygon : public Shape {
protected:
    int numSides;

public:
    Polygon(string c, int sides) : Shape(c), numSides(sides) {
        cout << "2. Polygon constructor called (Sides: " << numSides << ")" << endl;
    }
};

// Level 3: Derived from Polygon
class Rectangle : public Polygon {
private:
    double area;

public:
    Rectangle(string c, double a) : Polygon(c, 4), area(a) {
        cout << "3. Rectangle constructor called (Area: " << area << ")" << endl;
    }
};

int main() {
    cout << "Creating a Rectangle object:" << endl;
    Rectangle rect("Blue", 25.5);
    return 0;
}