#include <iostream>

int main()
{
    const int SUBJECTS = 5;
    int marks[SUBJECTS];
    int total = 0;

    std::cout << "Enter marks of\n";

    for (int i = 0; i < SUBJECTS; i++)
    {
        std::cout << "subject" << (i + 1) << ": ";
        std::cin >> marks[i];
        total += marks[i];
    }

    std::cout << "\nStudent Marks for\n";
    for (int i = 0; i < SUBJECTS; i++)
    {
        std::cout << "subject" << (i + 1) << ": " << marks[i] << '\n';
    }

    float percentage = (total / (float)(SUBJECTS * 100)) * 100;

    // Display total and percentage
    std::cout << "\nTotal: " << total << '\n';
    std::cout << "Percentage: " << percentage << '\n';

    return 0;
}
