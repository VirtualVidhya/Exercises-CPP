#include <iostream>

int main()
{
    const int items_count = 5;
    int coupon_price;
    int coupon_discount;

    std::cout << "Enter the coupon price (rs): ";
    std::cin >> coupon_price;

    std::cout << "Enter the discount price of the coupon (rs): ";
    std::cin >> coupon_discount;
    
    int prices[items_count];

    std::cout << "\nEnter item prices (rs)\n";

    for (int i = 0; i < items_count; i++)
    {
        std::cout << "item" << (i+1) << ": ";
        std::cin >> prices[i];
    }

    int saving_amount = 0;

    for (int i = 0; i < items_count; i++)
    {
        if (prices[i] >= coupon_discount)
        {
            saving_amount += coupon_discount;
        }
        else
        {
            saving_amount += prices[i];
        }
    }

    if (saving_amount > coupon_price)
    {
        std::cout << "\nDO use coupon\n";
    }
    else
    {
        std::cout << "\nDO NOT use coupon\n";
    }

    return 0;
}