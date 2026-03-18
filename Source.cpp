#include <iostream>
#include <string>
#include <iomanip>
#include "WeeklyWeather.h"  

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    WeeklyWeather weeklyWeather("weekly_weather.json");

    int choice;

    do {
        std::cout << "\n╔════════════════════════════════╗\n";
        std::cout << "║     МЕНЮ ПРОГНОЗА ПОГОДЫ       ║\n";
        std::cout << "╠════════════════════════════════╣\n";
        std::cout << "║ 1. Показать прогноз на неделю ║\n";
        std::cout << "║ 2. Сохранить в JSON файл      ║\n";
        std::cout << "║ 3. Показать статистику        ║\n";
        std::cout << "║ 4. Вывести количество записей ║\n";
        std::cout << "║ 0. Выход                       ║\n";
        std::cout << "╚════════════════════════════════╝\n";
        std::cout << "Выберите действие: ";

        std::cin >> choice;

        switch (choice) {
        case 1:
            weeklyWeather.displayWeeklyData();
            break;

        case 2:
            if (weeklyWeather.saveToFile()) {
                std::cout << " Файл успешно сохранен!\n";
            }
            break;

        case 3:
            std::cout << "\n СТАТИСТИКА ЗА НЕДЕЛЮ:\n";
            std::cout << "──────────────────────────\n";
            std::cout << "Средняя температура: " << std::fixed << std::setprecision(1)
                << weeklyWeather.calculateAverageTemperature() << "°C\n";
            std::cout << "Максимальная температура: " << weeklyWeather.findMaxTemperature() << "°C\n";
            std::cout << "Минимальная температура: " << weeklyWeather.findMinTemperature() << "°C\n";
            std::cout << "Средняя влажность: " << weeklyWeather.calculateAverageHumidity() << "%\n";
            std::cout << "Среднее давление: " << weeklyWeather.calculateAveragePressure() << " мм рт.ст.\n";
            break;

        case 4:
            std::cout << "\nКоличество записей: " << weeklyWeather.getSize() << "\n";
            break;

        case 0:
            std::cout << "\n Программа завершена. До свидания!\n";
            break;

        default:
            std::cout << " Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
