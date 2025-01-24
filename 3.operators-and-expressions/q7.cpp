#include <iostream>

int main() 
{
    const float PI = 3.14;

    float radius;

    std::cout << "Enter the value of radius: ";
    std::cin >> radius;

    float circumference = 2 * PI * radius;

    float area = PI * radius * radius;

    std::cout << "Circumference: " << circumference << '\n';
    std::cout << "Area: " << area << '\n';

    return 0;
}