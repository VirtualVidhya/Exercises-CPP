#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> cities = {"Surat", "Valsad", "Ahmedabad", "Vadodara", "Gandhinagar"};

    std::cout << "The final city on your itinerary is: " << cities.back() << std::endl;

    return 0;
}