#include "WeeklyWeather.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void WeeklyWeather::initializeTestData() {
    weekWeather.clear();

    dayNames = {
        "Понедельник", "Вторник", "Среда", "Четверг",
        "Пятница", "Суббота", "Воскресенье"
    };

    weekWeather.push_back(Weather("26.02.2026", "Northern", -5.5, 85.0, 750.0, "Monday"));
    weekWeather.push_back(Weather("27.02.2026", "Northeast", -3.2, 78.0, 752.5, "Tuesday"));
    weekWeather.push_back(Weather("28.02.2026", "Eastern", -1.8, 72.0, 755.0, "Wednesday"));
    weekWeather.push_back(Weather("01.03.2026", "South-east", 0.5, 70.0, 753.2, "Thursday"));
    weekWeather.push_back(Weather("02.03.2026", "South", 2.3, 75.0, 751.8, "Friday"));
    weekWeather.push_back(Weather("03.03.2026", "Southwest", 1.5, 80.0, 749.5, "Saturday"));
    weekWeather.push_back(Weather("04.03.2026", "Western", -0.7, 82.0, 748.0, "Sunday"));
}

WeeklyWeather::WeeklyWeather(const std::string& fname) : filename(fname) {
    initializeTestData();
}

bool WeeklyWeather::saveToFile() {
    if (weekWeather.empty()) {
        std::cout << "Нет данных для сохранения!\n";
        return false;
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return false;
    }

    file << "{\n";
    file << "  \"weeklyWeather\": [\n";

    for (size_t i = 0; i < weekWeather.size(); ++i) {
        file << weekWeather[i].toJSON();
        if (i < weekWeather.size() - 1) {
            file << ",";
        }
        file << "\n";
    }

    file << "  ],\n";
    file << "  \"statistics\": {\n";
    file << "    \"averageTemperature\": " << calculateAverageTemperature() << ",\n";
    file << "    \"maxTemperature\": " << findMaxTemperature() << ",\n";
    file << "    \"minTemperature\": " << findMinTemperature() << ",\n";
    file << "    \"averageHumidity\": " << calculateAverageHumidity() << ",\n";
    file << "    \"averagePressure\": " << calculateAveragePressure() << "\n";
    file << "  }\n";
    file << "}\n";

    file.close();
    std::cout << "\n✓ Данные успешно сохранены в файл " << filename << std::endl;
    return true;
}

void WeeklyWeather::displayWeeklyData() const {
    if (weekWeather.empty()) {
        std::cout << "\nНет данных о погоде.\n";
        return;
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║     ПРОГНОЗ ПОГОДЫ НА НЕДЕЛЮ         ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";

    for (size_t i = 0; i < weekWeather.size(); ++i) {
        weekWeather[i].display();
    }

    std::cout << "\n📊 СТАТИСТИКА ЗА НЕДЕЛЮ:\n";
    std::cout << "──────────────────────────\n";
    std::cout << "Средняя температура: " << std::fixed << std::setprecision(1)
        << calculateAverageTemperature() << "°C\n";
    std::cout << "Максимальная температура: " << findMaxTemperature() << "°C\n";
    std::cout << "Минимальная температура: " << findMinTemperature() << "°C\n";
    std::cout << "Средняя влажность: " << calculateAverageHumidity() << "%\n";
    std::cout << "Среднее давление: " << calculateAveragePressure() << " мм рт.ст.\n";
}

double WeeklyWeather::calculateAverageTemperature() const {
    if (weekWeather.empty()) return 0;
    double sum = 0;
    for (const auto& w : weekWeather) {
        sum += w.getTemperature();
    }
    return sum / weekWeather.size();
}

double WeeklyWeather::findMaxTemperature() const {
    if (weekWeather.empty()) return 0;
    double max = weekWeather[0].getTemperature();
    for (const auto& w : weekWeather) {
        if (w.getTemperature() > max) {
            max = w.getTemperature();
        }
    }
    return max;
}

double WeeklyWeather::findMinTemperature() const {
    if (weekWeather.empty()) return 0;
    double min = weekWeather[0].getTemperature();
    for (const auto& w : weekWeather) {
        if (w.getTemperature() < min) {
            min = w.getTemperature();
        }
    }
    return min;
}

double WeeklyWeather::calculateAverageHumidity() const {
    if (weekWeather.empty()) return 0;
    double sum = 0;
    for (const auto& w : weekWeather) {
        sum += w.getHumidity();
    }
    return sum / weekWeather.size();
}

double WeeklyWeather::calculateAveragePressure() const {
    if (weekWeather.empty()) return 0;
    double sum = 0;
    for (const auto& w : weekWeather) {
        sum += w.getPressure();
    }
    return sum / weekWeather.size();
}

void WeeklyWeather::updateData(int index, const Weather& newWeather) {
    if (index >= 0 && index < weekWeather.size()) {
        weekWeather[index] = newWeather;
    }
}

size_t WeeklyWeather::getSize() const {
    return weekWeather.size();
}
