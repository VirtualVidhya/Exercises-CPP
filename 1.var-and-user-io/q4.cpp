#include<iostream>

int main()
{
    int n = 0;

    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Double of " << n << ": " << 2*n << '\n';
    std::cout << "Triple of " << n << ": " << 3*n << '\n';

    return 0;
}