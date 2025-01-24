#include <iostream>
#include <cmath>

int main()
{
    double p, p0;
    float r;
    int t;

    std::cout << "Enter the starting population (in crores): ";
    std::cin >> p0;

    std::cout << "Enter the percentage rate of growth (in %): ";
    std::cin >> r;

    r = r / 100;

    std::cout << "Enter the time (in years): ";
    std::cin >> t;

    p = p0 * std::pow(1 + r, t);

    std::cout << "Total population after given time (in crores): " << p << std::endl;

    return 0;
}