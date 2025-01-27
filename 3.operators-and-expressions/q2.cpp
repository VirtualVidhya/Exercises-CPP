#include <iostream>

int main()
{
    int a, b, c;

    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;

    std::cout << "The average of " << a << ", " << b << " and " << c << " is " << (a + b + c) / 3 << ".\n";

    return 0;
}