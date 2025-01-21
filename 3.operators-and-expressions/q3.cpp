#include <iostream>

int main()
{
    int l, w;

    std::cout << "Enter the length & width of a rectangle: ";
    std::cin >> l >> w;

    std::cout << "Perimeter: " << 2 * (l + w) << '\n';
    std::cout << "Area: " << l * w << '\n';

    return 0;
}