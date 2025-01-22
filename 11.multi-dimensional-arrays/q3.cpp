#include <iostream>

const int ROWS = 5;
const int COLS = 6;

void displaySeats(bool seats[ROWS][COLS])
{
    std::cout << "\nCurrent Seating Chart:\n\n";
    std::cout << "     ";
    for (int col = 0; col < COLS; ++col)
    {
        std::cout << col + 1 << " ";
    }
    std::cout << "\n";
    std::cout << "    -";
    for (int col = 0; col < COLS; ++col)
    {
        std::cout << "--";
    }
    std::cout << "\n";
    for (int row = 0; row < ROWS; ++row)
    {
        std::cout << row + 1 << "  | ";
        for (int col = 0; col < COLS; ++col)
        {
            if (seats[row][col])
            {
                std::cout << "X "; // X represents a booked seat
            }
            else
            {
                std::cout << "O "; // O represents an available seat
            }
        }
        std::cout << "\n";
    }
}

bool isSeatAvailable(bool seats[ROWS][COLS], int row, int col)
{
    return !seats[row][col];
}

void bookSeat(bool seats[ROWS][COLS], int row, int col)
{
    if (isSeatAvailable(seats, row, col))
    {
        seats[row][col] = true;
        std::cout << "Seat booked successfully!\n";
    }
    else
    {
        std::cout << "Seat is already occupied. Please choose another seat.\n";
    }
}

int main()
{
    bool seats[ROWS][COLS] = {false}; // Initialize all seats as available

    int choice;
    do
    {
        std::cout << "\n----------------\n";
        std::cout << "# Options:\n";
        std::cout << "1. Display Seating Chart\n";
        std::cout << "2. Check Seat Availability\n";
        std::cout << "3. Book a Seat\n";
        std::cout << "4. Exit\n";
        std::cout << "----------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            displaySeats(seats);
            break;
        case 2:
        {
            int row, col;
            std::cout << "\nEnter row (1-" << ROWS << ") and column (1-" << COLS << ") to check availability: ";
            std::cin >> row >> col;
            if (row < 1 || row > ROWS || col < 1 || col > COLS)
            {
                std::cout << "Invalid seat selection.\n";
            }
            else
            {
                if (isSeatAvailable(seats, row - 1, col - 1))
                {
                    std::cout << "Seat is available.\n";
                }
                else
                {
                    std::cout << "Seat is already occupied.\n";
                }
            }
            break;
        }
        case 3:
        {
            int row, col;
            std::cout << "\nEnter row (1-" << ROWS << ") and column (1-" << COLS << ") to book: ";
            std::cin >> row >> col;
            if (row < 1 || row > ROWS || col < 1 || col > COLS)
            {
                std::cout << "Invalid seat selection.\n";
            }
            else
            {
                bookSeat(seats, row - 1, col - 1);
                displaySeats(seats);
            }
            break;
        }
        case 4:
            std::cout << "\nExiting the system.\n";
            break;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    } 
    while (choice != 4);

    return 0;
}