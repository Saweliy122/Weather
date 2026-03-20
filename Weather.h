#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>

class Weather {
private:
    std::string date;
    std::string windDirection;
    double temperature;
    double humidity;
    double pressure;
    std::string dayOfWeek;

public:
    Weather();
    Weather(std::string d, std::string wind, double temp, double hum, double pres, std::string day);

    std::string getDate() const;
    std::string getWindDirection() const;
    double getTemperature() const;
    double getHumidity() const;
    double getPressure() const;
    std::string getDayOfWeek() const;

    std::string toJSON() const;
    void display() const;
};

#endif 

