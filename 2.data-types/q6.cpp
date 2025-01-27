#include<iostream>

int main()
{
    bool wantToTip = false;
    
    std::cin >> std::boolalpha;
    std::cout << "Would you like to give a tip: ";
    std::cin >> wantToTip;

    std::cout << std::boolalpha;
    std::cout << "Is user willing to give a tip:: " << wantToTip << '\n';

    return 0;
}