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
#include <limits>
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
	std::string log = "";
	std::string pin = "";

	void Start() {

		while (true) {
			if (log == "" && pin == "") {
				startMenu(log, pin);
			}
			if (pubCheckEnter(log, pin)) {
				id = pubGetId(log, pin);
				if (id == 1) {
					addFunc::adminMenu(choose);
				}
				else {
					menu();
				}
				break;
			}
			else {
				if (errorLog(log, pin)) {
					id = pubGetId(log, pin);
					menu();
					break;
				}
				else {
					log = "";
					pin = "";
					continue;
				}
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
			<< azure
			<< "Enter your login:" << endl << "   |";
		addFunc::clearCin();

		std::cin >> log;

		cout
			<< azure
			<< "Enter your password:" << endl << "   |";
		addFunc::clearCin();

		std::cin >> pin;
	}

	bool errorLog(std::string& log, std::string& pin) {
		std::cout
			<< red
			<< "[[[   | ERROR |   ]]]"
			<< std::endl
			<< "This account doesn't exist("
			<< azure
			<< std::endl
			<< "Press 1 to create this."
			<< white
			<< std::endl;
		int v = 0;
		std::cin >> v;
		if (v == 1) {
			system("cls");
			if (pubCreateAccount(log, pin)) {
				std::cout << green << "Account created!" << white << std::endl;
				return true;
			}
			else {
				std::cout << red << "This account name was takken." << white << std::endl;
				return false;
			}
			system("pause");
		}
		else {
			log = "";
			pin = "";
			v = 0;
			return false;
		}
	}


	void menu() {
		while (true) {
			system("cls");
			cout
				<< azure
				<< "<<<<<<<<< [ MENU ] >>>>>>>>>" << endl
				<< "| 1) operations            |" << endl
				<< "| 2) user settings         |-" << endl
				<< "| 3) notifications         |-" << endl
				<< "| 4)                       |" << endl
				<< "| 5) check additional info |" << endl
				<< "| " << red << "else - SIGN OUT" << azure << "          |" << endl
				<< "============================"
				<< endl
				<< green
				<< "Enter: "
				<< white;
			addFunc::clearCin();
			cin >> choose;
			if (choose == 1) {  operationMenu(); }
			else if (choose == 2) {  }
			else if (choose == 3) {	}
			else if (choose == 4) {	}
			else if (choose == 5) { addFunc::additionalInfo(); }
			else { break; }
		}
	}

	void operationMenu() {
		while (true) {
			system("cls");
			cout
				<< azure
				<< "<<< [  OPERATION MENU  ] >>>" << endl
				<< "| 1) create new deposits   |" << endl
				<< "| 2) check your deposits   |" << endl
				<< "| 3) actions with deposits |-" << endl
				<< "| 4) top up your account   |" << endl
				<< "| 5) info about percents   |" << endl
				<< "| " << yellow << "else - go to main menu" << azure << "   |" << endl
				<< "============================"
				<< endl
				<< green
				<< "Enter: "
				<< white;
			addFunc::clearCin();
			int operationChoose;
			cin >> operationChoose;
			if (operationChoose == 1) { createNewDeposit(); }
			else if (operationChoose == 2) { checkAllDepoitsOfUser(); }
			else if (operationChoose == 3) { }
			else if (operationChoose == 4) { topUpAccount(); }
			else if (operationChoose == 5) { system("start https://docs.google.com/spreadsheets/d/e/2PACX-1vT75Nqncc-yMDMUaPUby5q1Nf2Sb3el57WaOd_bT9ecciTyCRIls8SRM7byeMsgpb6MILcQBENpeFYP/pubhtml?gid=0&single=true"); }
			else { break; }
		}
	}


	void tableOfUser() {
		int xlen;
		addFunc::countSymbolsForDepositTable(id, xlen);
	}


	void createNewDeposit() {
		system("cls");
		if (pubCheckIsSumSmallerWallet(id, 1)) {
			std::cout << azure << "Enter name of deposit: " << white << std::endl;
			addFunc::clearCin();
			std::string nameOfDeposit;
			getline(std::cin, nameOfDeposit);
			cout << azure << "Enter sum of deposit: " << white << std::endl;
			unsigned long long sum = 0;
			while (!pubCheckIsSumSmallerWallet(id, sum)) {
				addFunc::clearCin();
				std::cin >> sum;
			}
			cout << azure << "Enter type of deposit(1 - 5): " << white << std::endl;
			for (int i = 1; i < 6; i++) { std::cout << i << ") " << addFunc::getPercentsHoldTimeByTypeInString(i) << std::endl; }// + ((i - 1) * 5)) << std::endl; }//
			unsigned int typeTime = 0;
			while (typeTime < 1 || typeTime > 5) {
				addFunc::clearCin();
				std::cin >> typeTime;
			}			
			if (pubCreateDeposit(log, pin, nameOfDeposit, sum, addFunc::countTypeBySummAndTime(sum, typeTime))) {
				std::cout << green << "Deposit created!" << white << std::endl;
			}
			else {
				std::cout << red << "[[[   | ERROR |   ]]]" << white << std::endl;
			}
		}
		else {
			std::cout << red << "Kazna pusta, Milord" << white << std::endl;
		}
		system("pause");
	}

	void checkAllDepoitsOfUser() {
		system("cls");
		std::cout
			<< green
			<< "[ ";
		if (GetPersonName(id).size()) { std::cout << "Full name: " << GetPersonName(id) << " ]" << std::endl << "[ "; }
		std::cout << "Login: " << GetLogName(id) << " | Money in wallet: " << GetUserWallet(id) << " ]" << std::endl;
		for (int i = 0; i < GetCountOfDeposits(id); i++) {
			std::cout
				<< azure
				<< "=====================" << std::endl
				<< "| #" << i + 1 << yellow << std::endl
				<< "| Date: " << GetDateOfDeposit(id, i).day << "." << GetDateOfDeposit(id, i).month << "." << GetDateOfDeposit(id, i).year << std::endl
				<< "| Name of deposit: " << GetNameOfDeposit(id, i) << std::endl
				<< "| Percentes per annum: " << addFunc::getPercentsByType(GetTypeOfDeposit(id, i)) * 100 << "%" << std::endl
				<< "| Time to hold: " << addFunc::getPercentsHoldTimeByTypeInString(GetTypeOfDeposit(id, i)) << std::endl
				<< "| Sum: " << GetSumOfDeposit(id, i) << std::endl;
			if (pubIsDepositHoldComplete(id, i)) { std::cout << green; }
			else { std::cout << red; }
			std::cout
				<< "| Percents: " << GetPercentsOfDeposit(id, i)
				<< white << std::endl << std::endl;
		}
		system("pause");
	}

	void topUpAccount() {
		int id = pubGetId(log, pin) - 1;
		unsigned long long sumToTopUp = 0;
		while (sumToTopUp < 1 || sumToTopUp > 9999999) {
			system("cls");
			std::cout
				<< green
				<< "Enter the sum to top up account: "
				<< white << std::endl;
			addFunc::clearCin();
			std::cin >> sumToTopUp;
			if (sumToTopUp > 9999999) {
				system("start https://www.nalog.gov.ru/rn77/");
				addFunc::MAKSDEBIL();
			}
		}
		std::cout << green << "In your wallet: " << pubTopUpAccount(sumToTopUp, id) << " rubels" << white << std::endl;
		system("pause");
	}
};
