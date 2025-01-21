#include <iostream>

int main()
{
    const int ITEMS_CNT = 5;
    int coupon_price;
    int coupon_discount;

    std::cout << "Enter the coupon price (rs): ";
    std::cin >> coupon_price;

    std::cout << "Enter the discount price of the coupon (rs): ";
    std::cin >> coupon_discount;

    int prices[ITEMS_CNT];
    int total_cost_without_coupon = 0;

    std::cout << "\nEnter item prices (rs) of\n";

    for (int i = 0; i < ITEMS_CNT; i++)
    {
        std::cout << "item" << (i + 1) << ": ";
        std::cin >> prices[i];
        total_cost_without_coupon += prices[i];
    }

    int saving_amount = 0;

    for (int i = 0; i < ITEMS_CNT; i++)
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

    int total_cost_with_coupon = total_cost_without_coupon - saving_amount + coupon_price;

    if (total_cost_with_coupon < total_cost_without_coupon)
    {
        std::cout << "\nDO use coupon\n";
    }
    else
    {
        std::cout << "\nDO NOT use coupon\n";
    }

    return 0;
}