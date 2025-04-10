#include <iostream>
#include <iomanip>
#include <string>

// Define an unscoped enum for the days of the week.
enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    TOTAL_DAYS
};

int main()
{
    int sales[TOTAL_DAYS];
    std::string dayNames[TOTAL_DAYS] = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // Input: Use enum values to loop through each day.
    for (Day d = MONDAY; d < TOTAL_DAYS; d = static_cast<Day>(d + 1))
    {
        std::cout << "Enter sales for " << dayNames[d] << ": ";
        std::cin >> sales[d];
    }

    // Initialize stats using the first day's sales.
    int total = sales[MONDAY];
    int highest = sales[MONDAY];
    int lowest = sales[MONDAY];
    Day highestDay = MONDAY;
    Day lowestDay = MONDAY;

    // Process sales data: iterate using enums.
    for (Day d = static_cast<Day>(MONDAY + 1); d < TOTAL_DAYS; d = static_cast<Day>(d + 1))
    {
        total += sales[d];
        if (sales[d] > highest)
        {
            highest = sales[d];
            highestDay = d;
        }
        if (sales[d] < lowest)
        {
            lowest = sales[d];
            lowestDay = d;
        }
    }

    // Calculate average sales.
    double average = static_cast<double>(total) / TOTAL_DAYS;

    // Output results.
    std::cout << "\nHighest sales: " << dayNames[highestDay] << " (₹" << highest << ")\n";
    std::cout << "Lowest sales: " << dayNames[lowestDay] << " (₹" << lowest << ")\n";
    std::cout << "Average sales: ₹" << std::fixed << std::setprecision(2) << average << "\n";

    return 0;
}
