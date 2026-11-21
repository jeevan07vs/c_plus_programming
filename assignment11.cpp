#include <iostream>
class Matrix {private:
    int rows;
    int cols;
    int** data;
public:
    // Constructor: allocates an m x n grid
    Matrix(int m, int n) : rows(m), cols(n) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]{0}; // Initialize elements to 0
        }
    }

    // Deep Copy Constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j]; // Copy values, not pointers
            }
        }
    }

    // Destructor: frees the allocated grid
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i]; // Free each row
        }
        delete[] data; // Free the array of row pointers
    }

    // Helper methods to set and get values
    void set(int r, int c, int val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        }
    }

    int get(int r, int c) const {
        return data[r][c];
    }
};
int main() {
    Matrix m1(2, 3);
    m1.set(0, 1, 42);

    Matrix m2 = m1; // Invokes deep copy constructor
    m2.set(0, 1, 99);

    std::cout << "m1(0,1): " << m1.get(0, 1) << "\n"; // Outputs 42
    std::cout << "m2(0,1): " << m2.get(0, 1) << "\n"; // Outputs 99

    return 0; // Destructors automatically clean up m1 and m2
}
