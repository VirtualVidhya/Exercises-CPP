#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string accountHolder;
    long long accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(std::string name, long long accNum, double initialBalance)
    {
        accountHolder = name;
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0; // Prevent negative balance
    }

    // Deposit money into the account
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposited rs." << amount << " successfully!\n";
        }
        else
        {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    // Withdraw money (only if balance is sufficient)
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cout << "Insufficient balance! Withdrawal failed.\n";
        }
        else if (amount <= 0)
        {
            std::cout << "Invalid withdrawal amount!\n";
        }
        else
        {
            balance -= amount;
            std::cout << "Withdrawn rs." << amount << " successfully!\n";
        }
    }

    // Display the account details
    void displayAccount() const
    {
        std::cout << "\nAccount Details:\n";
        std::cout << "Name: " << accountHolder << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Balance: rs." << balance << "\n\n";
    }
};

int main()
{
    // Creating a bank account with initial details
    BankAccount customer("Ramesh Panipuriwala", 78563249, 50000);

    // Display initial account details
    customer.displayAccount();

    // Deposit rs.10000
    customer.deposit(10000);
    customer.displayAccount();

    // Withdraw rs.20000
    customer.withdraw(20000);
    customer.displayAccount();

    // Attempt to withdraw rs.50000 (insufficient balance)
    customer.withdraw(50000);

    return 0;
}
