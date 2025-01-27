#include <iostream>

int main()
{
    bool isRaining = false;
    int windSpeed = 10;

    std::cout << "Is it raining? (0 for false, 1 for true): ";
    std::cin >> isRaining;

    std::cout << "Wind speeds (km/h): ";
    std::cin >> windSpeed;

    if (!isRaining && (windSpeed >= 5 && windSpeed <= 20))
    {
        std::cout << "It's a good condition for paragliding." << std::endl;
    }
    else
    {
        std::cout << "It's NOT a good condition for paragliding." << std::endl;
    }

    return 0;
}
