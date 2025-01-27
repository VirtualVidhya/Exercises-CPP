#include<iostream>

int main()
{
    char c = 'a';

    std::cout << "Enter a single character: ";
    std::cin >> c;

    std::cout << "You entered" << c << "which has an ASCII code " << static_cast<int>(c) << ".\n";

    return 0;
}