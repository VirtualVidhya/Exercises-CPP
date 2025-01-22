#include <iostream>

const int FLOORS = 3;
const int ROOMS = 2;
const int BEDS = 4;

void displayBeds(bool beds[FLOORS][ROOMS][BEDS])
{
    std::cout << "\nCurrent Bed Status:\n";
    for (int floor = 0; floor < FLOORS; ++floor)
    {
        std::cout << "Floor " << floor + 1 << ":\n";
        for (int room = 0; room < ROOMS; ++room)
        {
            std::cout << "  Room " << room + 1 << ": ";
            for (int bed = 0; bed < BEDS; ++bed)
            {
                if (beds[floor][room][bed])
                {
                    std::cout << "X "; // X represents an occupied bed
                }
                else
                {
                    std::cout << "O "; // O represents a vacant bed
                }
            }
            std::cout << "\n";
        }
    }
}

void checkAvailability(bool beds[FLOORS][ROOMS][BEDS], int floor, int room)
{
    if (floor < 1 || floor > FLOORS || room < 1 || room > ROOMS)
    {
        std::cout << "\nInvalid floor or room number.\n";
        return;
    }

    std::cout << "\nBed availability in Floor " << floor << ", Room " << room << ":\n";
    for (int bed = 0; bed < BEDS; ++bed)
    {
        if (!beds[floor - 1][room - 1][bed])
        {
            std::cout << "Bed " << bed + 1 << " is available.\n";
        }
        else
        {
            std::cout << "Bed " << bed + 1 << " is occupied.\n";
        }
    }
}

void bookBed(bool beds[FLOORS][ROOMS][BEDS], int floor, int room, int bed)
{
    if (floor < 1 || floor > FLOORS || room < 1 || room > ROOMS || bed < 1 || bed > BEDS)
    {
        std::cout << "\nInvalid floor, room, or bed number.\n";
        return;
    }

    if (!beds[floor - 1][room - 1][bed - 1])
    {
        beds[floor - 1][room - 1][bed - 1] = true;
        std::cout << "\nBed booked successfully!\n";
    }
    else
    {
        std::cout << "\nBed is already occupied. Please choose another bed.\n";
    }
}

void displayVacantBeds(bool beds[FLOORS][ROOMS][BEDS])
{
    int vacant = 0;
    for (int floor = 0; floor < FLOORS; ++floor)
    {
        for (int room = 0; room < ROOMS; ++room)
        {
            for (int bed = 0; bed < BEDS; ++bed)
            {
                if (!beds[floor][room][bed])
                {
                    vacant++;
                }
            }
        }
    }
    std::cout << "\nTotal vacant beds in the hospital: " << vacant << "\n";
}

int main()
{
    bool beds[FLOORS][ROOMS][BEDS] = {false};

    int choice;
    do
    {
        std::cout << "\n----------------\n";
        std::cout << "# Options:\n";
        std::cout << "\n1. Display Bed Status\n";
        std::cout << "2. Check Bed Availability\n";
        std::cout << "3. Book a Bed\n";
        std::cout << "4. Display Total Vacant Beds\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            displayBeds(beds);
            break;
        case 2:
        {
            int floor, room;
            std::cout << "\nEnter floor (1-" << FLOORS << ") and room (1-" << ROOMS << ") to check availability: ";
            std::cin >> floor >> room;
            checkAvailability(beds, floor, room);
            break;
        }
        case 3:
        {
            int floor, room, bed;
            std::cout << "\nEnter floor (1-" << FLOORS << "), room (1-" << ROOMS << "), and bed (1-" << BEDS << ") to book: ";
            std::cin >> floor >> room >> bed;
            bookBed(beds, floor, room, bed);
            break;
        }
        case 4:
            displayVacantBeds(beds);
            break;
        case 5:
            std::cout << "\nExiting the system.\n";
            break;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    } 
    while (choice != 5);

    return 0;
}