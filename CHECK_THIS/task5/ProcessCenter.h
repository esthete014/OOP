// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /


#pragma once
#include "userslib.h"
#include "additionalFunctions.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class ProcessCenter : private Users, private addFunc {
public:

	ProcessCenter() {
		choose = 0;		
		Start();
	}


private:
	int choose;
	int id;

	void Start() {
		std::string log;
		std::string pin;

		while (true) {
			startMenu(log, pin);
			if (pubCheckEnter(log, pin)) {
				id = pubGetId(log, pin);
				if (id == 1) {
					adminMenu();
				}
				else {
					menu();
				}
			}
			else {
				if (errorLog(log, pin)) {
					id = pubGetId(log, pin);
					menu();
				}
			}
			break;
		}
	}

	void menu() {
		while (choose < 1 || choose > 5) {
			system("cls");
			cout
				<< blue
				<< endl
				<< "<<<<<<<< [ MENU ] >>>>>>>>" << endl
				<< "| 1) check your deposits |" << endl
				<< "| 2) " << endl
				<< "| 3) " << endl
				<< "| 4) " << endl
				<< "| 5) " << endl
				<< "| " << red << "else - EXIT" << blue << "            |" << endl
				<< "=========================="
				<< endl
				<< white
				<< "Enter: ";
			cin >> choose;
			if (choose == 1) {
				
			}
			else if (choose == 2) {

			}
			else if (choose == 3) {

			}
			else if (choose == 4) {

			}
			else if (choose == 5) {

			}
			else {
				break;
			}
		}
	}


	void adminMenu() {
		while (choose < 1 || choose > 5) {
			system("cls");
			cout
				<< green
				<< blue
				<< "<<<< [ ADMIN'S MENU ] >>>>" << endl
				<< "1) " << endl
				<< "2) " << endl
				<< "3) " << endl
				<< "4) " << endl
				<< "5) " << endl
				<< "else - EXIT" << endl
				<< white
				<< endl;
			cin >> choose;
			if (choose == 1) {

			}
			else if (choose == 2) {

			}
			else if (choose == 3) {

			}
			else if (choose == 4) {

			}
			else if (choose == 5) {

			}
			else {
				break;
			}
		}
	}

	void startMenu(std::string& log, std::string& pin) {
		system("cls");
		cout
			<< green
			<< " ----------------- " << endl
			<< "[    LOGINING     ]" << endl
			<< " ----------------- " << endl
			<< endl
			<< blue
			<< "Enter your login:" << endl << "   |";
		cin >> log;
		cout
			<< blue
			<< "Enter your login:" << endl << "   |";
		cin >> pin;
	}

	bool errorLog(std::string log, std::string pin) {
		cout
			<< red
			<< "[[[   | ERROR |   ]]]"
			<< endl
			<< "This account doesn't exist("
			<< blue
			<< endl
			<< "Press 1 to create this."
			<< white
			<< endl;
		int v;
		cin >> v;
		if (v == 1) {
			if (pubCreateAccount(log, pin)) {
				system("cls");
				cout << green << "Account created!" << white << endl;
				return true;
			}
			else {
				cout << red << "This account name was takken." << white << endl;
				system("pause");
				return false;
			}
		}
		else {
			return false;
		}
	}
};
