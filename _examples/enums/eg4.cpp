#include <iostream>
#include <string>
#include <limits>

// Define an enum class for shirt colors
enum class ShirtColor
{
    red,
    blue,
    green,
    yellow
};

// Overload the output operator to print ShirtColor in a human-readable form
std::ostream &operator<<(std::ostream &os, const ShirtColor &color)
{
    switch (color)
    {
    case ShirtColor::red:
        os << "red";
        break;
    case ShirtColor::blue:
        os << "blue";
        break;
    case ShirtColor::green:
        os << "green";
        break;
    case ShirtColor::yellow:
        os << "yellow";
        break;
    default:
        os << "unknown";
        break;
    }
    return os;
}

// Overload the input operator to read ShirtColor from a stream using a string representation
std::istream &operator>>(std::istream &is, ShirtColor &color)
{
    std::string token;
    is >> token;

    // Convert the input token to a ShirtColor (case sensitive, but you can add case-insensitivity)
    if (token == "red" || token == "Red")
    {
        color = ShirtColor::red;
    }
    else if (token == "blue" || token == "Blue")
    {
        color = ShirtColor::blue;
    }
    else if (token == "green" || token == "Green")
    {
        color = ShirtColor::green;
    }
    else if (token == "yellow" || token == "Yellow")
    {
        color = ShirtColor::yellow;
    }
    else
    {
        // If the token doesn't match any known colors, set the failbit on the stream
        is.setstate(std::ios::failbit);
    }

    return is;
}

int main()
{
    ShirtColor color;

    // Prompt user to enter a shirt color
    std::cout << "Enter your shirt color (red, blue, green, yellow): ";
    std::cin >> color;

    if (std::cin) // if we found a match
    {
        std::cout << "The selected shirt color is: " << color << '\n';
    }
    else
    {
        std::cin.clear(); // reset the input stream to good
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter one of the following colors: red, blue, green, yellow.\n";
    }

    // Attempt to read the user's input
    // if (!(std::cin >> color))
    // {
    //     std::cerr << "Invalid input! Please enter one of the following colors: red, blue, green, yellow.\n";
    //     return 1;
    // }

    // // Output the result using the overloaded operator<<
    // std::cout << "The selected shirt color is: " << color << std::endl;

    return 0;
}
