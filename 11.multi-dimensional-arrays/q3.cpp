#include <iostream>

int main()
{
    const int DAYS = 7;
    const int TIMES = 4;
    const std::string TIME_LABELS[TIMES] = {"Morning", "Noon", "Evening", "Night"};
    int temperatures[DAYS][TIMES];

    std::cout << "----------------\n";
    std::cout << "Enter temperature readings for each day and time:\n";
    std::cout << "----------------\n\n";

    for (int day = 0; day < DAYS; day++)
    {
        std::cout << "Day " << (day + 1) << ":\n";
        std::cout << "--------\n";
        for (int time = 0; time < TIMES; time++)
        {
            std::cout << TIME_LABELS[time] << ": ";
            std::cin >> temperatures[day][time];
        }
        std::cout << "\n";
    }

    std::cout << "----------------\n";

    int query_day;
    std::cout << "\nEnter the day number (1-7) to get the average temperature: ";
    std::cin >> query_day;

    if (query_day < 1 || query_day > DAYS)
    {
        std::cout << "Invalid day number!\n";

        return 1;
    }

    int sum = 0;
    for (int time = 0; time < TIMES; time++)
    {
        sum += temperatures[query_day - 1][time];
    }
    std::cout << "Average temperature on Day " << query_day << ": " << (sum / TIMES) << "°C\n";

    int hottest_temp = temperatures[0][0], coldest_temp = temperatures[0][0];
    int hottest_day = 0, coldest_day = 0;
    int hottest_time = 0, coldest_time = 0;

    for (int day = 0; day < DAYS; day++)
    {
        for (int time = 0; time < TIMES; time++)
        {
            if (temperatures[day][time] > hottest_temp)
            {
                hottest_temp = temperatures[day][time];
                hottest_day = day;
                hottest_time = time;
            }

            if (temperatures[day][time] < coldest_temp)
            {
                coldest_temp = temperatures[day][time];
                coldest_day = day;
                coldest_time = time;
            }
        }
    }

    std::cout << "\n----------------\n";
    std::cout << "Hottest temperature of the week: " << hottest_temp << "°C on Day " << (hottest_day + 1) << " (" << TIME_LABELS[hottest_time] << ")\n";
    std::cout << "Coldest temperature of the week: " << coldest_temp << "°C on Day " << (coldest_day + 1) << " (" << TIME_LABELS[coldest_time] << ")\n";

    return 0;
}
