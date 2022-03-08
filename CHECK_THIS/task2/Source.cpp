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
#include "Menu.h"
#include "var5.h"
#include "var6.h"



int main() {
	srand(time(0));
	Menu U;
	int progvar;
	cout
		<< "programm started))"
		<< endl;
	while (1) {
		cout
			<< "which variant do you want to start?"
			<< endl
			<< "0 - exit"
			<< endl
			<< "1 - variant 5"
			<< endl
			<< "2 - variant 6"
			<< endl;
		cin >> progvar;
		if (progvar == 1) {
			U.menu1();
		}
		if (progvar == 2) {
			U.menu2();
		}
		else {
			break;
		}
	}
	return 0;
}