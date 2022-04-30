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
#include "additionalFunctions.h"
using namespace std;
class Users;






class Deposit : private addFunc{
	friend Users;

	std::string namesOfDeposit;
	Date dateOfDeposit;
	unsigned long long sumOfDeposit;
	unsigned int typeOfDeposit;
	unsigned long percentsOfDeposit;

	
	Deposit CareAdminDeposit() {
		Deposit dep;
		dep.namesOfDeposit = "ADMIN'S DEPOSIT";
		Date dateAdminDep;
		dep.dateOfDeposit = dateAdminDep;
		dep.sumOfDeposit = 111111111;
		dep.typeOfDeposit = 1;
		dep.percentsOfDeposit = 14;
		return dep;
	}


	void enterNewDeposit(std::string name, Date date, unsigned long long summ, int type, unsigned long percent) {
		namesOfDeposit = name;
		dateOfDeposit = date;
		sumOfDeposit = summ;
		typeOfDeposit = type;
		percentsOfDeposit = percent;
	}


	virtual double getPercentsHoldTimeByType(unsigned int type) {
		if (type == 1 || type == 6 || type == 11 || type == 16) { return 90; }
		else if (type == 2 || type == 7 || type == 12 || type == 17) { return 180; }
		else if (type == 3 || type == 8 || type == 13 || type == 18) { return 365; }
		else if (type == 4 || type == 9 || type == 14 || type == 19) { return 730; }
		else if (type == 5 || type == 10 || type == 15 || type == 20) { return 1095; }
		else { return 0; }
	}
	virtual long countPercents(Deposit& getdep) {
		Deposit dep = *this;
		long percents = 0;
		int index = dep.namesOfDeposit.size() - 1;
		Date today = TodayToDate();
		long double time = 0;
		time += today.day + (today.month * 30) + ((today.year - 2000) * 365);
		time -= dep.dateOfDeposit.day + (dep.dateOfDeposit.month * 30) + ((dep.dateOfDeposit.year - 2000) * 365);
		if (time < getPercentsHoldTimeByType(dep.typeOfDeposit)) {
			percents = dep.sumOfDeposit * getPercentsByType(dep.typeOfDeposit) * (time / 365);
		}
		else {
			percents = dep.sumOfDeposit * getPercentsByType(dep.typeOfDeposit) * (getPercentsHoldTimeByType(dep.typeOfDeposit) / 365);
		}
		if (percents > 0) {
			return percents;
		}
		else { return 0; }
	}

	bool isDepositHoldComplete() {
		Deposit dep = *this;
		Date today = TodayToDate();
		long double time = 0;
		time += today.day + (today.month * 30) + ((today.year - 2022) * 365);
		time -= dep.dateOfDeposit.day + (dep.dateOfDeposit.month * 30) + ((dep.dateOfDeposit.year - 2022) * 365);
		if (time < getPercentsHoldTimeByType(dep.typeOfDeposit)) {
			return false;
		}
		else {
			return true;
		}
	}
};
