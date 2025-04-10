#include <iostream>
#include <string>

enum CarType
{
    SEDAN = 1,
    SUV,
    HATCHBACK,
    LUXURY
};

int getRentalPricePerDay(CarType type)
{
    switch (type)
    {
    case SEDAN:
        return 2000;
    case SUV:
        return 3000;
    case HATCHBACK:
        return 1500;
    case LUXURY:
        return 5000;
    default:
        return 0;
    }
}

std::string getCarTypeName(CarType type)
{
    switch (type)
    {
    case SEDAN:
        return "Sedan";
    case SUV:
        return "SUV";
    case HATCHBACK:
        return "Hatchback";
    case LUXURY:
        return "Luxury";
    default:
        return "Unknown";
    }
}

int main()
{
    std::cout << "Available car types:\n";
    std::cout << "1. Sedan\n";
    std::cout << "2. SUV\n";
    std::cout << "3. Hatchback\n";
    std::cout << "4. Luxury\n";

    int choice{};
    std::cout << "\nEnter the number for the car type you want to rent: ";
    std::cin >> choice;

    int days{};
    std::cout << "Enter the number of days: ";
    std::cin >> days;

    CarType selectedType = static_cast<CarType>(choice);
    int pricePerDay = getRentalPricePerDay(selectedType);
    int totalCost = pricePerDay * days;

    std::cout << "\nYou selected " << getCarTypeName(selectedType) << " for " << days << " days.\n";
    std::cout << "Rental cost per day: ₹" << pricePerDay << "\n";
    std::cout << "Total cost: ₹" << totalCost << "\n";

    return 0;
}
