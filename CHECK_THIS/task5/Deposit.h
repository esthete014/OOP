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
#include <string>
#include <vector>
using namespace std;
class Users;

struct Date
{
	int day = 19, month = 4, year = 2022;
};

class Deposit {
	friend Users;


	std::vector<std::string> names;
	std::vector<Date> dateOfDeposit;
	std::vector<long long> sumOfDeposit;
	std::vector<int> typeOfDeposit;

	/*Deposit() {
		CareAdminDeposit();
	}*/

	void CareAdminDeposit() {
		names.push_back("ADMIN'S DEPOSIT");
		Date dateAdminDep;
		dateOfDeposit.push_back(dateAdminDep);
		sumOfDeposit.push_back(111111111);
		typeOfDeposit.push_back(1);
	}

	void enterNewDeposit(std::string name, Date date, int summ, int type) {
		names.push_back(name);
		dateOfDeposit.push_back(date);
		sumOfDeposit.push_back(summ);
		typeOfDeposit.push_back(type);
	}


	//GETTERS
	std::string GetNameOfDeposit(int number) {
		return names[number];
	}

	Date GetDateOfDeposit(int number) {
		return dateOfDeposit[number];
	}

	int GetSummOfDeposit(int number) {
		return sumOfDeposit[number];
	}

	int GetTypeOfDeposit(int number) {
		return sumOfDeposit[number];
	}
};
