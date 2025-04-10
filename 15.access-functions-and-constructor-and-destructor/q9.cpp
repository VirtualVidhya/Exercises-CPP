#include <iostream>
#include <string>

class VendingMachine
{
private:
    int balance;
    bool productSelected;

    const std::string products[3][2] = {
        {"Chips", "30"},
        {"Soda", "50"},
        {"Chocolate", "40"}};

public:
    VendingMachine() : balance(0), productSelected(false) {}

    void insertMoney(int amount)
    {
        balance += amount;
        std::cout << "Inserted ₹" << amount << " into the vending machine.\n";
    }

    void selectProduct(const std::string &product)
    {
        int price = -1;

        // Searching for the product in the nested array
        for (int i = 0; i < 3; i++)
        {
            if (products[i][0] == product)
            {
                price = std::stoi(products[i][1]); // Convert price from string to int
                break;
            }
        }

        if (price == -1)
        {
            std::cout << "Error: Product not available!\n";
            return;
        }

        if (balance < price)
        {
            std::cout << "Error: Not enough balance to buy " << product << "!\n";
            return;
        }

        balance -= price;
        productSelected = true;
        std::cout << "Selected: " << product << " (₹" << price << ")\n";
        std::cout << "Product dispensed. Change returned: ₹" << balance << "\n";
        balance = 0; // Reset balance after purchase
    }

    void exitMachine()
    {
        if (!productSelected && balance > 0)
        {
            std::cout << "User exited without selecting a product.\n";
            std::cout << "Money returned: ₹" << balance << "\n";
            balance = 0;
        }

        std::cout << "System exited.\n";
    }

    ~VendingMachine()
    {
        if (!productSelected && balance > 0)
        {
            std::cout << "Unexpected shutdown detected! Returning ₹" << balance << " to the user.\n";
            balance = 0;
        }
        
        std::cout << "System exited.\n";
    }
};

int main()
{
    // Case 1: Successful Purchase
    {
        VendingMachine vm;
        vm.insertMoney(50);
        vm.selectProduct("Chips");
    }

    std::cout << "\n";

    // Case 2: User exits without selecting a product
    {
        VendingMachine vm;
        vm.insertMoney(50);
        vm.exitMachine();
    }

    std::cout << "\n";

    // Case 3: Unexpected Shutdown (Handled by Destructor)
    {
        VendingMachine vm;
        vm.insertMoney(100);
        // No product selected, so the destructor will return the money
    }

    return 0;
}
