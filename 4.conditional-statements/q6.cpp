#include <iostream>

int main()
{
    int num = 0;

    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << num << " is an " << ((num % 2 == 0) ? "even" : "odd") << " number.\n"; 

    return 0;
}
