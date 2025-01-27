#include <iostream>

int main()
{
    char bucketSize = 'M';

    std::cout << "Enter the popcorn-bucket size: ";
    std::cin >> bucketSize;

    int price = 0;

    switch (bucketSize)
    {
    case 'L':
        price = 200;
        break;
    case 'M':
        price = 100;
        break;
    case 'S':
        price = 50;
        break;
    default:
        std::cout << "Invalid bucket size!\n";
        return 1;
    }

    std::cout << "Price: " << price << std::endl;

    return 0;
}
