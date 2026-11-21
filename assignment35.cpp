#include <iostream>
#include <memory>

int main() 
{
    auto ptr = std::make_unique<int>(42);
    auto arr = std::make_unique<int[]>(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    std::cout << *ptr << " " << arr[1] << '\n';

    // No delete or delete[] needed; memory is freed automatically
    return 0;
}