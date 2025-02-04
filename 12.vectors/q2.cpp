#include <iostream>
#include <vector>
#include <string>

void printGuestList(const std::vector<std::string> &guests)
{
    std::cout << "\nGuest List:" << std::endl;
    for (size_t i = 0; i < guests.size(); ++i)
    {
        std::cout << i + 1 << ". " << guests[i] << std::endl;
    }
}

int main()
{
    std::vector<std::string> guestList = {"Harry", "Jerry", "Gary", "Mary", "Barry"};

    printGuestList(guestList);

    guestList.push_back("Perry");
    guestList.push_back("Carey");
    guestList.push_back("Sherry");

    printGuestList(guestList);

    guestList.pop_back();

    std::cout << "\nAfter omitting the last added guest due to capacity constraints:";
    printGuestList(guestList);

    return 0;
}
