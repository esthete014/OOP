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
				<< "| 2) user settings         |" << endl
				<< "| 3) notifications         |" << endl
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
			else if (choose == 2) { userSettings(); }
			else if (choose == 3) { checkNotifications(); }
			else if (choose == 4) {	}
			else if (choose == 5) { addFunc::additionalInfo(); }
			else { break; }
		}
	}

	void userSettings() {
		system("cls");
		printUserInfo(id, true);
		std::cout << azure << "You can change your name(press 1): " << white;
		unsigned doChangeName;
		addFunc::clearCin();
		std::cin >> doChangeName;
		if (doChangeName == 1) {
			system("cls");
			std::cout << azure << "Enter your name: " << white << std::endl;
			addFunc::clearCin();
			std::string userName;
			getline(std::cin, userName);
			if (pubChangeUserName(id, userName)) {
				std::cout << green << "Name changed!" << white << std::endl;
			}
			else {
				std::cout << green << "Name saved!" << white << std::endl;
			}
			system("pause");
		}
	}

	void checkNotifications() {
		system("cls");
		std::cout << azure << "Hello, ";
		if (GetPersonName(id).size()) { std::cout << GetPersonName(id); }
		else { std::cout << GetLogName(id); }
		std::cout << "!" << green << std::endl << std::endl;
		bool flagIsAnyDepComplete = false;
		for (int i = 0; i < GetCountOfDeposits(id); i++) {
			if (pubIsDepositHoldComplete(id, i)) {
				flagIsAnyDepComplete = true;
				printDeposit(i, false);
			}
		}
		if (!flagIsAnyDepComplete) { std::cout << red << "None notifications(" << white << std::endl; }
		system("pause");
	}

	void operationMenu() {
		while (true) {
			system("cls");
			cout
				<< azure
				<< "<<< [  OPERATION MENU  ] >>>" << endl
				<< "| 1) create new deposits   |" << endl
				<< "| 2) check your deposits   |" << endl
				<< "| 3) actions with deposits |" << endl
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
			else if (operationChoose == 3) { actionsWitDeposits(); }
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
		printUserInfo(id, false);
		if (pubCheckIsSumSmallerWallet(id, 101)) {
			std::cout << azure << "Enter name of deposit: " << white << std::endl;
			addFunc::clearCin();
			std::string nameOfDeposit;
			getline(std::cin, nameOfDeposit);
			cout << azure << "Enter sum of deposit: " << white << std::endl;
			unsigned long long sum = 0;
			while (!pubCheckIsSumSmallerWallet(id, sum)) {
				addFunc::clearCin();
				std::cin >> sum;
				if (sum > 100) { if (!pubCheckIsSumSmallerWallet(id, sum)) {
						std::cout << red << "Money in wallet: " << GetUserWallet(id) << " < entered sum: " << sum << white << std::endl;
					}
				}
				else { std::cout << red << "Sum must be greater than 100!" << white << std::endl; }
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
		printUserInfo(id, false);
		for (int i = 0; i < GetCountOfDeposits(id); i++) {
			printDeposit(i, true);
		}
		system("pause");
	}

	void actionsWitDeposits() {
		system("cls");
		std::vector<unsigned int> numbersCompleteDep;
		for (int i = 0; i < GetCountOfDeposits(id); i++) {
			if (pubIsDepositHoldComplete(id, i)) {
				numbersCompleteDep.push_back(i);
				printDeposit(i, false);
			}
		}
		if (!numbersCompleteDep.size()) { std::cout << red << "None deposits!" << white << std::endl; }
		else {
			std::cout << azure << "Enter numbers of deposits to withdraw: " << white;
			addFunc::clearCin();
			std::string numbersToWithdraw;
			getline(std::cin, numbersToWithdraw);
			std::vector<unsigned int> withdrawedNumbers = pubWithdrawMoney(id, numbersCompleteDep, numbersToWithdraw);
			std::cout << std::endl;
			if (withdrawedNumbers.size()) {
				std::cout << "Withdrawed deposit";
				if (withdrawedNumbers.size() == 1) { std::cout << ": "; }
				else { std::cout << "s: "; }
				for (int i = 0; i < withdrawedNumbers.size(); i++) {
					std::cout << withdrawedNumbers[i] + 1;
					if (i == withdrawedNumbers.size() - 2) { std::cout << " and "; }
					else if (i == withdrawedNumbers.size() - 1) { std::cout << std::endl; }
					else { std::cout << ", "; }
				}
				system("pause");
				system("cls");
				printUserInfo(id, false);
				for (int i = 0; i < GetCountOfDeposits(id); i++) { printDeposit(i, true); }
			}
			else{ std::cout << red << "Incorrect input!" << white << std::endl; }
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
		std::cout << green << "In your wallet: " << pubTopUpAccount(id, sumToTopUp) << " rubels" << white << std::endl;
		system("pause");
	}



	void printDeposit(int number, bool doCheckComplete) {
		std::cout
			<< azure
			<< "=====================" << std::endl
			<< "| #" << number + 1 << yellow << std::endl
			<< "| Date: " << GetDateOfDeposit(id, number).day << "." << GetDateOfDeposit(id, number).month << "." << GetDateOfDeposit(id, number).year << std::endl
			<< "| Name of deposit: " << GetNameOfDeposit(id, number) << std::endl
			<< "| Percentes per annum: " << addFunc::getPercentsByType(GetTypeOfDeposit(id, number)) * 100 << "%" << std::endl
			<< "| Time to hold: " << addFunc::getPercentsHoldTimeByTypeInString(GetTypeOfDeposit(id, number)) << std::endl
			<< "| Sum: " << GetSumOfDeposit(id, number) << std::endl;
		if (doCheckComplete) {
			if (pubIsDepositHoldComplete(id, number)) { std::cout << green; }
			else { std::cout << red; }
		}
		else { std::cout << green; }
		std::cout
			<< "| Percents: " << GetPercentsOfDeposit(id, number)
			<< white << std::endl << std::endl;
	}

	void printUserInfo(int id, bool writeFullNameInAnyCase) {
		std::cout
			<< green
			<< "[ ";
		if (writeFullNameInAnyCase) {
			if (GetPersonName(id).size()) {	std::cout << "Full name: " << GetPersonName(id) << " ]" << std::endl << "[ "; }
			else { std::cout << "Full name: " << red << "NONE" << green << " ]" << std::endl; }
		}
		else{ if (GetPersonName(id).size()) { std::cout << "Full name: " << GetPersonName(id) << " ]" << std::endl << "[ "; } }
		std::cout << "Login: " << GetLogName(id) << " | Money in wallet: " << GetUserWallet(id) << " ]" << white << std::endl;
	}
};
