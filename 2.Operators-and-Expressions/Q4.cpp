#include <iostream>

int main()
{
    int biscuit_price, waffer_price, icecream_price;

    std::cout << "Enter the cost of 3 food items: ";
    std::cin >> biscuit_price >> waffer_price >> icecream_price;

    int total_cost = biscuit_price + waffer_price + icecream_price;
    float gst_amount = total_cost * 0.18;

    std::cout << "Total Cost: " << total_cost << '\n';
    std::cout << "GST Amount: " << gst_amount << '\n';
    std::cout << "Total Bill: " << total_cost + gst_amount << '\n';

    return 0;
}