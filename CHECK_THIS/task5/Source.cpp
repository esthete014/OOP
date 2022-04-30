// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /


//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "color.h"
#include "ProcessCenter.h"
using namespace std;



int main() {
    
    
    cout << green << "[ PROGRAMM STARTED ]" << white << endl;
	system("pause");
    std::string isExit = "0";
    ProcessCenter enter;
    while (true) {
        system("cls");
        std::cout << green << "[ DO YOU WANT TO LOGGING? ]" << white << std::endl;
        std::cout << green << "  1 - yes " << white << "|" << red << " else - TO EXIT" << white << std::endl;
        if (char(cin.peek()) == '\n')
            cin.ignore();
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        cin >> isExit;
        if (isExit == "1") {
            ProcessCenter enter;
        }
        else {
            break;
        }
    }

	return 0;
}