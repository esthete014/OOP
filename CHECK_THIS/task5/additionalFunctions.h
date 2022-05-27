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
#include "Deposit.h"


struct Date
{
	int day = 19, month = 4, year = 2022;
};


class TodayDate {
	time_t now = time(0);
	tm* ltm = localtime(&now);
public:
	int day = ltm->tm_mday;
	int month = ltm->tm_mon + 1;
	int year = ltm->tm_year + 1900;
};

class addFunc {
protected:
	//////////////////////////////////////////////////////////////
	/// ProcessCenter's methods
	//////////////////////////////////////////////////////////////
	static float getPercentsByType(unsigned int type) {//and deposit's method
		if (type == 1) { return 0.03; }
		else if (type == 2) { return 0.032; }
		else if (type == 3) { return 0.034; }
		else if (type == 4) { return 0.036; }
		else if (type == 5) { return 0.038; }
		else if (type == 6) { return 0.04; }
		else if (type == 7) { return 0.042; }
		else if (type == 8) { return 0.044; }
		else if (type == 9) { return 0.046; }
		else if (type == 10) { return 0.048; }
		else if (type == 11) { return 0.05; }
		else if (type == 12) { return 0.052; }
		else if (type == 13) { return 0.054; }
		else if (type == 14) { return 0.056; }
		else if (type == 15) { return 0.058; }
		else if (type == 16) { return 0.06; }
		else if (type == 17) { return 0.062; }
		else if (type == 18) { return 0.064; }
		else if (type == 19) { return 0.066; }
		else if (type == 20) { return 0.068; }
		else { return 0; }
	}
	static std::string getPercentsHoldTimeByTypeInString(unsigned int type) {//and ProcessCenter's method
		if (type == 1 || type == 6 || type == 11 || type == 16) { return "3 months"; }
		else if (type == 2 || type == 7 || type == 12 || type == 17) { return "6 months"; }
		else if (type == 3 || type == 8 || type == 13 || type == 18) { return "1 year"; }
		else if (type == 4 || type == 9 || type == 14 || type == 19) { return "2 years"; }
		else if (type == 5 || type == 10 || type == 15 || type == 20) { return "3 years"; }
		else { return "error"; }
	}
	//////////////////////////////////////////////////////////////
	/// Users's methods
	//////////////////////////////////////////////////////////////

	Date transformLineToDate(std::string line, Date date, int &i) {
		date.day = int(line[i] - 48);
		if (line[i + 1] >= char(48) && line[i + 1] <= char(57)) {
			i++;
			date.day *= 10;
			date.day += int(line[i] - 48);
			i += 2;
		}
		else { i += 2; }
		date.month = int(line[i] - 48);
		if (line[i + 1] >= char(48) && line[i + 1] <= char(57)) {
			i++;
			date.month *= 10;
			date.month += int(line[i] - 48);
			i += 2;
		}
		else { i += 2; }
		date.year = (int(line[i] - 48) * 1000) + (int(line[i + 1] - 48) * 100) + (int(line[i + 2] - 48) * 10) + int(line[i + 3] - 48);
		i += 5;
		return date;
	}

	Date TodayToDate() {
		Date date;
		TodayDate today;
		date.day = today.day;
		date.month = today.month;
		date.year = today.year;
		return date;
	}

	//////////////////////////////////////////////////////////////
	/// ProcessCenter's methods
	//////////////////////////////////////////////////////////////
	
protected:
	virtual void countSymbolsForDepositTable(int id, int& x) {
		int lenUsersLog, lenFamNameSec_name, lenDeposit;

	}

	virtual void clearCin() {
		//clear cin
		if (char(std::cin.peek()) == '\n')
			std::cin.ignore();
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	}

	virtual void adminMenu(int &choose) {
		while (choose < 1 || choose > 5) {
			system("cls");
			std::cout
				<< violet
				<< "<<<< [ ADMIN'S MENU ] >>>>" << std::endl
				<< "1) " << std::endl
				<< "2) " << std::endl
				<< "3) " << std::endl
				<< "4) " << std::endl
				<< "5) " << std::endl
				<< "else - EXIT" << std::endl
				<< white
				<< std::endl;
			std::cin >> choose;
			if (choose == 1) {
				//Users::
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

	virtual unsigned int countTypeBySummAndTime(unsigned long long sum, unsigned int typeTime) {
		unsigned int type;
		if (sum < 100000) { type = typeTime; }
		else if (sum < 500000) { type = 5 + typeTime; }
		else if (sum < 1000000) { type = 10 + typeTime; }
		else if (sum > 1000000) { type = 15 + typeTime; }
		else { type = 1; }
		return type;
	}

	virtual void additionalInfo() {
		system("cls");
		std::cout
			<< violet
			<< "<[    Program devoloped by esthete014    ]>" << std::endl
			<< "<[ GitHub: https://github.com/esthete014 ]>" << std::endl
			<< "<[            copyright 2022             ]>" << std::endl
			<< white;
		system("pause");
	}


	virtual void MAKSDEBIL() {
		system("cls");
		std::cout
			<< red
			<< "|||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl
			<< "|||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl
			<< "||||||||||||||||   MAKS DEBIL)))   ||||||||||||||||" << std::endl
			<< "|||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl
			<< "|||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl << white;
		system("pause");
	}
};