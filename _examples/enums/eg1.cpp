#include <iostream>

enum Color
{
    black,
    red,
    blue,
};

const std::string getColorName(Color color)
{
    switch (color)
    {
    case black:
        return "black";
    case red:
        return "red";
    case blue:
        return "blue";
    default:
        return "???";
    }
}

int main()
{
    const Color shirt {blue};

    std::cout << "Your shirt is " << getColorName(shirt) << '\n';

    return 0;
}