#include <iostream>
#include <string>
#include <vector>

// Enum for Food Categories
enum FoodCategory
{
    STARTER,
    MAIN_COURSE,
    DESSERT,
    BEVERAGE
};

// Class for a Menu Item
class MenuItem
{
private:
    std::string m_name;
    FoodCategory m_category;
    int m_price;

public:
    MenuItem(std::string name, FoodCategory category, int price)
        : m_name{name}, m_category{category}, m_price{price} {}

    FoodCategory getCategory() const { return m_category; }

    void display() const
    {
        std::cout << "- " << m_name << " (₹" << m_price << ")\n";
    }
};

// Function to convert category number to string (for display)
std::string categoryToString(FoodCategory category)
{
    switch (category)
    {
    case STARTER:
        return "Starter";
    case MAIN_COURSE:
        return "Main Course";
    case DESSERT:
        return "Dessert";
    case BEVERAGE:
        return "Beverage";
    default:
        return "Unknown";
    }
}

int main()
{
    // Creating a small menu
    std::vector<MenuItem> menu{
        MenuItem("Paneer Tikka", STARTER, 220),
        MenuItem("Butter Chicken", MAIN_COURSE, 320),
        MenuItem("Veg Biryani", MAIN_COURSE, 220),
        MenuItem("Chocolate Lava Cake", DESSERT, 150),
        MenuItem("Masala Lemonade", BEVERAGE, 90)};

    // Show category options
    std::cout << "What would you like to see?\n";
    std::cout << "0 - Starter\n1 - Main Course\n2 - Dessert\n3 - Beverage\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    if (choice < 0 || choice > 3)
    {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    FoodCategory selectedCategory = static_cast<FoodCategory>(choice);

    std::cout << "\nItems in " << categoryToString(selectedCategory) << ":\n";

    for (const auto &item : menu)
    {
        if (item.getCategory() == selectedCategory)
        {
            item.display();
        }
    }

    return 0;
}
