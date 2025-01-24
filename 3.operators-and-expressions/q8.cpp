#include <iostream>

int main()
{
    float celsius;

    std::cout << "Enter the value of temperature in Celsius: ";
    std::cin >> celsius;

    float kelvin = celsius + 273;

    float fahrenheit = (9.0 / 5.0) * celsius + 32;

    std::cout << "Temperature in Kelvin: " << kelvin << std::endl;
    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}