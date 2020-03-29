#pragma once

#include <vector>
#include <string>
#include <utility>
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>

/**
 * @brief Класс для создания блоков команд и работы с ними (формирование, вывод, сохнанение в файл).
 */
class Bulk
{
    private:
    std::vector<std::string> bulk;  ///< вектор для хранения команд в виде строк
    std::pair<bool,uint8_t> checkD; ///< переменная для проверки использования знаков динамического разделения блоков "{" и "}" и хранения состояния о их кол-ве
    decltype(std::chrono::seconds(std::time(NULL))) time;   ///< храненит времени ввода первой команды в блок
    const int count;        ///< хранит информацию о размере блока, задаеться при запуске программы (инициализируеться в конструкторе)
    int countTry;           ///< оставшееся ко-во команд для ввода в блок для его формирования

    void checkDilimiter(std::string& str);
    void writeFile();
    void clearData();

    public:
    Bulk(int count);
    void setData(std::string&& str);
    void printData();
    int getQuantity();

};

