// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /


//biblioteki
#include <iostream>
using namespace std;

//files
#include "color.h"
#include "Taylor_series.h"
#include "Menu.h"


int main() {
	Menu U;
	cout << green << "Program launched))" << white << endl;
	U.menu();

	
	cout << red << "The program is stopped" << white << endl;
	return 0;
}