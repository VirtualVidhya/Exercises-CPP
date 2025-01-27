#include <iostream>
#include <cmath>

int main()
{
    int first_number = 1, second_number = 1;
    char operator_chosen = '+';

    std::cout << "first_number: ";
    std::cin >> first_number;

    std::cout << "second_number: ";
    std::cin >> second_number;

    std::cout << "operator_chosen: ";
    std::cin >> operator_chosen;

    std::cout << "output: " << first_number << " " << operator_chosen << " " << second_number << " = ";

    switch (operator_chosen)
    {
    case '+':
        std::cout << (first_number + second_number) << std::endl;
        break;
    case '-':
        std::cout << (first_number - second_number) << std::endl;
        break;
    case '*':
        std::cout << (first_number * second_number) << std::endl;
        break;
    case '/':
    {
        if (second_number != 0)
        {
            std::cout << (first_number / second_number) << std::endl;
        }
        else
        {
            std::cout << "Error! Division by zero is not allowed." << std::endl;
        }

        break;
    }
    case '%':
        std::cout << (first_number % second_number) << std::endl;
        break;
    case '^':
        std::cout << pow(first_number, second_number) << std::endl;
        break;
    default:
        std::cout << "Invalid operator!" << std::endl;
    }

    return 0;
}
