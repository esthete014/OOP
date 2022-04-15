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
		system("cls");
		Engine.CheckOldFile(Engine.PATH[Engine.PATHN]);
		system("pause");
		system("cls");
		while (true) {
			cout
				<< blue
				<< "|-------- [ MENU ] --------|" << endl
				<< "| 1) Delete all            |" << endl
				<< "| 2) Enter new entry       |" << endl
				<< "| 3) Check all entries     |" << endl
				<< "| 4) Find entries by date  |" << endl
				<< "| 5) Beginning of enteries |" << endl
				<< "| else - exit              |" << endl
				<< "|++++++++++++++++++++++++++|" << endl
				<< white;
			int chooseMenu;
			cin >> chooseMenu;
			if (chooseMenu == 1) {
				system("cls");
				Engine.DeleteAll(Engine.PATH[Engine.PATHN]);
				system("pause");
				system("cls");
			}
			else if (chooseMenu == 2) {
				system("cls");
				Engine.VvodSteps(Engine.PATH[Engine.PATHN]);
				system("pause");
				system("cls");
			}
			else if (chooseMenu == 3) {
				system("cls");
				Engine.VivodAll(Engine.PATH[Engine.PATHN]);
				system("pause");
				system("cls");
			}
			else if (chooseMenu == 4) {
				system("cls");
				Engine.FindStepsBy();
				system("pause");
				system("cls");
			}
			else if (chooseMenu == 5) {
				system("cls");
				Engine.BeginningOfEnteries();
				system("pause");
				system("cls");
			}
			else {
				break;
			}
		}//end of while true
	}//end of void menu
};//end of class Menu