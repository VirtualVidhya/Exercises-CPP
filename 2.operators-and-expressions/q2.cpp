#include <iostream>

int main()
{
    int a;

    std::cout << "Enter an integer: ";
    std::cin >> a;

    std::cout << "Double of " << a << ": " << a * 2 << '\n';
    std::cout << "Triple of " << a << ": " << a * 3 << '\n';

    return 0;
}