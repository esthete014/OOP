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
#pragma warning(suppress : 4996)
using namespace std;

//files
#include "Menu.h"
#include "var5.h"
#include "var6.h"



int main() {
	srand(time(0));
	Menu U;
	int progvar;
	cout
		<< "programm started))\n"
		<< "which variant do you want to start?\n"
		<< "1 - variant 5\n2 - variant 6"
		<< endl;
	cin >> progvar;
	while (0 < progvar < 3 == false) {
		cout
			<< "error"
			<< endl;
		cin >> progvar;
	}
	if (progvar == 1) {
		U.menu1();
	}
	else {
		U.menu2();
	};

	return 0;
}