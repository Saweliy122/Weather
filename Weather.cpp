#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "json.hpp"

using json = nlohmann::json;

std::vector<std::string> split(const std::string& line, char delimiter = ';') {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    setlocale(LC_ALL, "RU");
    std::string inputFile = "input.csv";
    std::string outputFile = "output.json";

    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cout << "Ошибка открытия файла." << inputFile << std::endl;
        return 1;
    }

    json j;
    j["weeklyWeather"] = json::array();

    std::string line;
    int lineNum = 0;

    while (std::getline(inFile, line)) {
        lineNum++;
        if (line.empty() || lineNum == 1) continue; 

        std::vector<std::string> parts = split(line);
        if (parts.size() == 6) {
            j["weeklyWeather"].push_back({
                {"dayOfWeek", parts[0]},
                {"date", parts[1]},
                {"windDirection", parts[2]},
                {"temperature", std::stod(parts[3])},
                {"humidity", std::stod(parts[4])},
                {"pressure", std::stod(parts[5])}
                });
        }
    }

    inFile.close();

    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cout << "Ошибка в создании файла." << outputFile << std::endl;
        return 1;
    }

    outFile << j.dump(4);
    outFile.close();

    std::cout << "JSON файл сконвертирован!\n";

    return 0;
}