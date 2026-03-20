#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "json.hpp"


using json = nlohmann::json;

int main() {
    setlocale(LC_ALL, "Russian");

    std::string inputFile = "input.txt";      
    std::string outputFile = "output.json";   

    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cout << "Файл не записался! Ошибка: не удалось открыть исходный файл " << inputFile << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(inFile, line)) {
        content += line + "\n";
    }
    inFile.close();

    json j;
    try {
        j = json::parse(content);
    }
    catch (const json::parse_error& e) {
        std::cout << "Файл не записался! Ошибка парсинга JSON: " << e.what() << std::endl;
        return 1;
    }

    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cout << "Файл не записался! Ошибка: не удалось создать выходной файл " << outputFile << std::endl;
        return 1;
    }

    outFile << j.dump(4);  
    outFile.close();

    std::cout << "Файл записался! Результат сохранен в " << outputFile << std::endl;

    return 0;
}