#include <iostream>

class SmartCar
{
public:
    enum class DriveMode
    {
        Normal,
        Eco,
        Sport
    };

private:
    int batteryLevel;
    DriveMode mode;

public:
    SmartCar(int initialBattery) : batteryLevel(initialBattery), mode(DriveMode::Normal)
    {
        std::cout << "--- Initializing Smart Car with " << batteryLevel << "% Battery ---\n";
        displayStatus();
    }

    void switchMode(DriveMode newMode)
    {
        if (newMode == DriveMode::Sport && batteryLevel < 50)
        {
            std::cout << "Error: Sport Mode requires at least 50% battery to activate.\n";
            return;
        }
        if (mode == DriveMode::Eco && newMode == DriveMode::Sport)
        {
            std::cout << "Error: Cannot switch to Sport Mode. Battery is too low.\n";
            return;
        }
        mode = newMode;
        displayMode();
    }

    void drive(int distance)
    {
        if (batteryLevel == 0)
        {
            std::cout << "Error: Battery is empty! Cannot drive.\n";
            return;
        }

        int consumption = distance * 3; // Each km consumes 3% battery
        batteryLevel -= consumption;
        if (batteryLevel < 0)
            batteryLevel = 0;

        std::cout << "Drove " << distance << " km. Battery consumed: " << consumption << "%.\n";

        if (batteryLevel < 30 && mode != DriveMode::Eco)
        {
            std::cout << "Drive Mode: Eco Mode (Energy Saving)\n";
            mode = DriveMode::Eco;
        }

        displayStatus();
    }

    void boostBattery(int amount)
    {
        batteryLevel += amount;
        if (batteryLevel > 100)
            batteryLevel = 100;

        std::cout << "Boosted battery by " << amount << "%. Current level: " << batteryLevel << "%.\n";
        if (batteryLevel >= 50)
            mode = DriveMode::Normal; // Reset to normal if battery is sufficient

        displayStatus();
    }

    void displayMode()
    {
        std::cout << "Drive Mode: ";
        switch (mode)
        {
        case DriveMode::Normal:
            std::cout << "Normal Mode (Balanced)";
            break;
        case DriveMode::Eco:
            std::cout << "Eco Mode (Energy Saving)";
            break;
        case DriveMode::Sport:
            std::cout << "Sport Mode (High Performance)";
            break;
        }
        std::cout << "\n";
    }

    void displayStatus()
    {
        displayMode();
        std::cout << "Battery Level: " << batteryLevel << "%\n";

        if (batteryLevel == 0)
            std::cout << "Car Status: Battery empty! Cannot drive.\n";
        else if (batteryLevel < 15)
            std::cout << "Car Status: Low battery! Recharge soon.\n";
        else
            std::cout << "Car Status: Car is running smoothly.\n";

        std::cout << "\n";
    }
};

int main()
{
    SmartCar car(50); // Initialize with 50% battery

    std::cout << "--- Attempting to switch to Sport Mode ---\n";
    car.switchMode(SmartCar::DriveMode::Sport);

    std::cout << "--- Driving 10 km in Normal Mode ---\n";
    car.drive(10);

    std::cout << "--- Boosting Battery by 40% ---\n";
    car.boostBattery(40);

    std::cout << "--- Driving 30 km in Normal Mode ---\n";
    car.drive(30);

    std::cout << "--- Attempting to switch to Sport Mode ---\n";
    car.switchMode(SmartCar::DriveMode::Sport);

    std::cout << "--- Attempting to override to Sport Mode while in Eco Mode ---\n";
    car.switchMode(SmartCar::DriveMode::Sport);

    return 0;
}
