#include <iostream>

class MobilePhone
{
private:
    std::string m_brand;
    std::string m_model;
    int m_price;

public:
    void setDetails(std::string b, std::string m, int p)
    {
        m_brand = b;
        m_model = m;
        m_price = p;
    }

    void updatePrice(int newPrice)
    {
        m_price = newPrice;
    }

    void displayDetails()
    {
        std::cout << "\nPhone Details:" << '\n';
        std::cout << "Brand: " << m_brand << '\n';
        std::cout << "Model: " << m_model << '\n';
        std::cout << "Price: rs." << m_price << '\n';
    }
};

int main()
{
    MobilePhone phone;

    phone.setDetails("Apple", "iPhone 16", 85000);
    phone.displayDetails();

    phone.updatePrice(72500);
    phone.displayDetails();

    return 0;
}
