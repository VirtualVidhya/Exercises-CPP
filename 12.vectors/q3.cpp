#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> basket;
    std::string item;

    std::cout << "Add items to your shopping basket (type \"done\" to finish):\n";

    while (true)
    {
        std::cout << "Add item: ";
        std::getline(std::cin >> std::ws, item);

        if (item == "done")
        {
            break;
        }

        basket.push_back(item);
    }

    std::cout << "\nYour shopping basket:\n";
    for (const auto &i : basket)
    {
        std::cout << i << "\n";
    }

    std::cout << "\nYou have total " << basket.size() << " items in your basket.\n";

    return 0;
}
