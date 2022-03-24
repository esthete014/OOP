// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || Copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /

#pragma once
#include "engine.h"
#include "color.h"
class engine;
using namespace std;


class Menu {
	friend engine;
public:
	void menu() {
		engine Engine;
		Engine.ChooseFilePath();
		Engine.CheckOldFile(Engine.PATH[Engine.PATHN]);

		while (true) {
			cout
				<< blue
				<< "|----- [ MENU ] -----|" << endl
				<< "1) Delete all" << endl
				<< "2) Enter new entry" << endl
				<< "3) Check all entries" << endl
				<< "else - exit" << endl
				<< white;
			int chooseMenu;
			cin >> chooseMenu;
			if (chooseMenu == 1) {
				Engine.DeleteAll(Engine.PATH[Engine.PATHN]);
			}
			else if (chooseMenu == 2) {
				Engine.VvodSteps(Engine.PATH[Engine.PATHN]);
			}
			else if (chooseMenu == 3) {
				Engine.VivodAll(Engine.PATH[Engine.PATHN]);
			}
			else if (chooseMenu == 4) {

			}
			else {
				break;
			}

		}


	}//end of void menu
};//end of class Menu