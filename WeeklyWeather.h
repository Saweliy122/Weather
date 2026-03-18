#ifndef WEEKLYWEATHER_H
#define WEEKLYWEATHER_H

#include <string>
#include <vector>
#include "Weather.h"

class WeeklyWeather {
private:
    std::vector<Weather> weekWeather;
    std::string filename;
    std::vector<std::string> dayNames;

    void initializeTestData();

public:
    WeeklyWeather(const std::string& fname);

    bool saveToFile();
    void displayWeeklyData() const;

    double calculateAverageTemperature() const;
    double findMaxTemperature() const;
    double findMinTemperature() const;
    double calculateAverageHumidity() const;
    double calculateAveragePressure() const;

    void updateData(int index, const Weather& newWeather);
    size_t getSize() const;
};

#endif 
