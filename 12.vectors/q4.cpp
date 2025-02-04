#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> beverages = {"Coffee", "Iced Tea", "Smoothie"};
    std::vector<std::string> snacks = {"Sandwich", "Nachos", "Samosa", "Fries"};
    std::vector<std::string> desserts = {"Brownie", "Waffles"};

    std::cout << "Café Menu\n\n";

    std::cout << "Beverages:\n";
    for (const auto &item : beverages)
    {
        std::cout << "- " << item << "\n";
    }

    std::cout << "\nSnacks:\n";
    for (const auto &item : snacks)
    {
        std::cout << "- " << item << "\n";
    }

    std::cout << "\nDesserts:\n";
    for (const auto &item : desserts)
    {
        std::cout << "- " << item << "\n";
    }

    std::cout << "\nEnjoy your meal!\n";

    return 0;
}
