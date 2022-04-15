// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || Copyright 2022 ||      |
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
#include "color.h"


int main() {
	cout
		<< green << "|--------------[ PROGRAM STARTED! ]--------------|" << endl
		<< "| This program will help you to count your steps |" << white << endl;
	Menu user;
	user.menu();
	cout
		<< red << "|--------------[ PROGRAM CLOSED! ]--------------|" << white << endl;
}