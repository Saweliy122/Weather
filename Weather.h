#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <codecvt> 
class Weather {
private:
    std::string date;
    std::string windDirection;
    double temperature;
    double humidity;
    double pressure;
    std::string dayOfWeek;

public:

    Weather() : temperature(0.0), humidity(0.0), pressure(0.0) {}


    Weather(std::string d, std::string wind, double temp, double hum, double pres, std::string day)
        : date(d), windDirection(wind), temperature(temp), humidity(hum), pressure(pres), dayOfWeek(day) {}


    std::string getDate() const { return date; }
    std::string getWindDirection() const { return windDirection; }
    double getTemperature() const { return temperature; }
    double getHumidity() const { return humidity; }
    double getPressure() const { return pressure; }
    std::string getDayOfWeek() const { return dayOfWeek; }


    std::string toJSON() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1);
        ss << "    {\n";
        ss << "      \"dayOfWeek\": \"" << dayOfWeek << "\",\n";
        ss << "      \"date\": \"" << date << "\",\n";
        ss << "      \"windDirection\": \"" << windDirection << "\",\n";
        ss << "      \"temperature\": " << temperature << ",\n";
        ss << "      \"humidity\": " << humidity << ",\n";
        ss << "      \"pressure\": " << pressure << "\n";
        ss << "    }";
        return ss.str();
    }


    void display() const {
        std::cout << "┌─────────────────────────────────┐\n";
        std::cout << "│ " << std::left << std::setw(15) << dayOfWeek << " │ " << std::setw(10) << date << " │\n";
        std::cout << "├─────────────────────────────────┤\n";
        std::cout << "│ Ветер: " << std::left << std::setw(20) << windDirection << "│\n";
        std::cout << "│ Температура: " << std::setw(16) << std::to_string(temperature) + "°C" << "│\n";
        std::cout << "│ Влажность: " << std::setw(18) << std::to_string(humidity) + "%" << "│\n";
        std::cout << "│ Давление: " << std::setw(18) << std::to_string(pressure) + " мм рт.ст." << "│\n";
        std::cout << "└─────────────────────────────────┘\n";
    }
};

