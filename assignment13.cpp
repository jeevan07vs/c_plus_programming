#include <iostream>

class Tracer {
private:
    int id;
public:
    Tracer(int i) : id(i) {
        std::cout << "Tracer " << id << " constructed.\n";
    }
    ~Tracer() {
        std::cout << "Tracer " << id << " destroyed.\n";
    }
};

int main() {
    for (int i = 0; i < 3; ++i) {
        Tracer* t = new Tracer(i);
        // Comment out the line below to observe the leak with -fsanitize=address
        delete t; 
    }
    return 0;
}