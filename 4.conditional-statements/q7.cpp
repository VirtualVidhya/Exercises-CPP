#include <iostream>

int main()
{
    float percentage = 0;

    std::cout << "Enter student percentage: ";
    std::cin >> percentage;

    if (percentage < 35)
    {
        std::cout << "Result: Fail" << std::endl;
    }
    else
    {
        if (percentage > 75)
        {
            std::cout << "Result: Pass with Distinction" << std::endl;
        }
        else if (percentage >= 60)
        {
            std::cout << "Result: Pass with Merit" << std::endl;
        }
        else
        {
            std::cout << "Result: Pass" << std::endl;
        }
    }

    return 0;
}
