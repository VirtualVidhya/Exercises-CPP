#include <iostream>

int main()
{
    const int DAYS_CNT = 7;
    int temperatures[DAYS_CNT];

    std::cout << "Enter the temperature (°C) for\n";

    for (int i = 0; i < DAYS_CNT; i++)
    {
        std::cout << "day" << (i + 1) << ": ";
        std::cin >> temperatures[i];
    }

    std::cout << "\nTemperatures for\n";

    for (int i = 0; i < DAYS_CNT; i++)
    {
        std::cout << "day" << (i + 1) << ": " << temperatures[i] << "°C\n";
    }

    int temp_sum = 0;
    int highest_temp = temperatures[0], lowest_temp = temperatures[0];
    int highestDay = 1, lowestDay = 1;

    for (int i = 0; i < DAYS_CNT; i++)
    {
        temp_sum += temperatures[i];

        if (temperatures[i] > highest_temp)
        {
            highest_temp = temperatures[i];
            highestDay = i + 1;
        }

        if (temperatures[i] < lowest_temp)
        {
            lowest_temp = temperatures[i];
            lowestDay = i + 1;
        }
    }

    float avg_temp = temp_sum / (float)DAYS_CNT;

    std::cout << "\nAverage Temperature (°C): " << avg_temp << '\n';
    std::cout << "Lowest Temperature of the week (°C): " << lowest_temp << " on day" << lowestDay << '\n';
    std::cout << "Highest Temperature of the week (°C): " << highest_temp << " on day" << highestDay << '\n';

    return 0;
}
