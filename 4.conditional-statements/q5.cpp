#include <iostream>

int main()
{
    int num = 0;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num % 3 == 0)
    {
        std::cout << num << " is divisible by " << 3 << ".\n";
    }
    else
    {
        std::cout << num << " is not divisible by " << 3 << ".\n";
    }
    return 0;
}