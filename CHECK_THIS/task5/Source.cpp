// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "color.h"
#include "ProcessCenter.h"
#include <ctime>
#include <chrono>
using namespace std;

/*
написать:

создание депозитов
запись депозитов в файл протестить
done    протестить чтение
записывать дату автоматически при создании депозита
написать раздел с уведомлениями о процентах депозитов и о выплатах с депозитов
списание депозитов и вообще счет клиента
раздел админа

*/

int main() {
	cout << green << "[ PROGRAMM STARTED ]" << white << endl;

    auto time = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(time);

    std::cout << "Date: " << std::ctime(&end_time) << endl;

    std::string DATE = std::ctime(&end_time);
    std::cout << "Date: " << DATE << endl;

	system("pause");
	ProcessCenter enter;

	return 0;
}