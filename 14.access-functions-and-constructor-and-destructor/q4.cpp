#include <iostream>

class SmartThermostat
{
private:
    double temperature;
    static constexpr double MIN_TEMP = 10.0;
    static constexpr double MAX_TEMP = 40.0;

public:
    SmartThermostat(double initialTemp)
    {
        if (initialTemp < MIN_TEMP)
        {
            std::cout << "Warning: Initial temperature too low! Setting to " << MIN_TEMP << "°C.\n";
            temperature = MIN_TEMP;
        }
        else if (initialTemp > MAX_TEMP)
        {
            std::cout << "Warning: Initial temperature too high! Setting to " << MAX_TEMP << "°C.\n";
            temperature = MAX_TEMP;
        }
        else
        {
            temperature = initialTemp;
        }
    }

    double getTemperature() const
    {
        return temperature;
    }

    void setTemperature(double newTemp)
    {
        if (newTemp < MIN_TEMP)
        {
            std::cout << "Warning: Temperature too low! Setting to minimum " << MIN_TEMP << "°C.\n";
            temperature = MIN_TEMP;
        }
        else if (newTemp > MAX_TEMP)
        {
            std::cout << "Warning: Temperature too high! Setting to maximum " << MAX_TEMP << "°C.\n";
            temperature = MAX_TEMP;
        }
        else
        {
            std::cout << "Temperature set to " << newTemp << "°C.\n";
            temperature = newTemp;
        }
    }

    std::string getThermostatStatus() const
    {
        if (temperature < 20.0)
        {
            return "Heating Mode ON (Room is too cold)";
        }
        else if (temperature > 30.0)
        {
            return "Cooling Mode ON (Room is too warm)";
        }
        else
        {
            return "Temperature is comfortable. No heating or cooling needed.";
        }
    }

    bool isEnergySavingMode() const
    {
        return (temperature >= 20.0 && temperature <= 30.0);
    }

    void displayStatus() const
    {
        std::cout << "\nCurrent Temperature: " << temperature << "°C\n";
        std::cout << "Status: " << getThermostatStatus() << "\n";
        std::cout << "Energy-Saving Mode: " << (isEnergySavingMode() ? "ON" : "OFF") << "\n";
    }
};

int main()
{
    std::cout << "--- Initializing Thermostat with 18°C ---\n";
    SmartThermostat thermostat(18);
    thermostat.displayStatus();

    std::cout << "\n--- Attempting to Set Temperature to 32°C ---\n";
    thermostat.setTemperature(32);
    thermostat.displayStatus();

    std::cout << "\n--- Attempting to Set Temperature to 22°C ---\n";
    thermostat.setTemperature(22);
    thermostat.displayStatus();

    std::cout << "\n--- Attempting to Set Temperature to 10°C ---\n";
    thermostat.setTemperature(10);
    thermostat.displayStatus();

    return 0;
}
