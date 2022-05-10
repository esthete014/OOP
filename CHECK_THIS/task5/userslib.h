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
#include <iostream>
#include <string>
#include <vector>
#include "Deposit.h"
#include "user.h"
#include "additionalFunctions.h"
#include <fstream>
#include <ctime>
using namespace std;
class Deposit;
class USER;


class Users : private addFunc {

	TodayDate today;
	std::vector<USER> users;

protected:
	Users() {
		careAdmin();
		checkFiles();
	}
private:

	void careAdmin() {
		USER admin;
		admin.usersLog = "admin";
		admin.passWords = "admin";
		admin.FamNameSec_name = "I'M ADMIN";
		admin.wallet = 999999;
		Deposit adminDep;
		admin.deposits.push_back(adminDep.CareAdminDeposit());
		users.push_back(admin);
	}

	void checkFiles() {
		
		std::string line;
		std::fstream ifile("users.txt", std::ios_base::in);
		ifile.open("users.txt");
		if (!ifile.is_open()) {
			std::fstream ifile("users.txt", std::ios_base::out);
		}
		ifile.close();
		ifile.open("users.txt");
		if (ifile.is_open()) {
			while (getline(ifile, line)) {
				readFromFile(line);
			}
		}
		ifile.close();
		
		//std::string line;
		std::fstream infile("deposits.txt", std::ios_base::in);
		infile.open("deposits.txt");
		if (!infile.is_open()) {
			std::fstream infile("deposits.txt", std::ios_base::out);
		}
		infile.close();
		infile.open("deposits.txt");
		if (infile.is_open()) {
			int round = 1;
			while (getline(infile, line)) {
				std::vector<Deposit> tempDeposit;
				if (line[0] != char(45)) {
					readFromFileDeposits(line, tempDeposit);
					users[round].deposits = tempDeposit;
				}
				else {
					tempDeposit.clear();
					users[round].deposits = tempDeposit;
				}
				round++;
			}
		}
		infile.close();
	}

	void readFromFile(std::string line) {//tut mojno ubrat' temps
		USER user;
		std::string tempLog;
		std::string tempPin;
		std::string tempFNSn;
		int tempWallet = 0;
		int i = 0;
		while (line[i] != char(47)) {
			tempLog += line[i];
			i++;
		}
		user.usersLog = tempLog;
		i++;
		while (line[i] != char(47)) {
			tempPin += line[i];
			i++;
		}
		user.passWords = tempPin;
		if (i + 1 != line.size()) {
			i++;
			while (line[i] != char(47)) {
				tempFNSn += line[i];
				i++;
			}
			user.FamNameSec_name = tempFNSn;
		}
		if (i + 1 != line.size()) {
			i++;
			while (line[i] != char(47)) {
				tempWallet *= 10;
				tempWallet += int(line[i] - 48);
				i++;
			}
			user.wallet = tempWallet;
		}
		users.push_back(user);
	}


	void readFromFileDeposits(std::string line, std::vector<Deposit> &dep) {
		int i = 0, index = 0;
		while (line[i] != char(124)) {
			Date date;
			Deposit tempDep;
			date = transformLineToDate(line, date, i);
			tempDep.dateOfDeposit = date;


			int tempType = 0;
			while (line[i] != char(47)) {
				tempType *= 10;
				tempType += int(line[i]) - 48;
				i++;
			}
			tempDep.typeOfDeposit = tempType;


			i++;
			std::string tempName;
			while (line[i] != char(47)) {
				tempName += line[i];
				i++;
			}
			tempDep.namesOfDeposit = tempName;


			i++;
			long long tempSumm = 0;
			while (line[i] != char(47)) {
				tempSumm *= 10;
				tempSumm += int(line[i]) - 48;
				i++;
			}
			tempDep.sumOfDeposit = tempSumm;


			tempDep.percentsOfDeposit = tempDep.countPercents(tempDep);
			dep.push_back(tempDep);
			i++;
			index++;
		}
		if (line[0] == char(124)) {
			std::vector<Deposit> tempDepVec;
			dep = tempDepVec;
		}
	}



	void createThisDeposit(int id, std::string name, unsigned long long sum, unsigned int type){
		Deposit dep;
		dep.namesOfDeposit = name;
		dep.dateOfDeposit = TodayToDate();
		dep.typeOfDeposit = type;
		dep.sumOfDeposit = sum;
		dep.percentsOfDeposit = dep.countPercents(dep);
		users[id].deposits.push_back(dep);
		users[id].wallet -= sum;
	}




	bool checkEnter(std::string log, std::string pin) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].usersLog == log && users[i].passWords == pin) {
				return true;
			}
		}
		return false;
	}

	bool checkEnterLog(std::string log) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].usersLog == log) {
				return false;
			}
		}
		return true;
	}

	bool createAccount(std::string log, std::string pin) {
		if (checkEnterLog(log)) {
			USER user;
			user.usersLog = log;
			user.passWords = pin;
			user.FamNameSec_name = "";
			std::vector<Deposit> tempDepVec;
			user.deposits = tempDepVec;
			user.wallet = 0;
			users.push_back(user);
			saveToFileLogPin();
			saveToFileDeposit();
			return true;
		}
		else {
			return false;
		}
	}

	void saveToFileLogPin() {
		ofstream outfile;
		outfile.open("users.txt");
		if (outfile.is_open()) {
			for (int i = 1; i < users.size(); i++) {
				outfile
					<< users[i].usersLog
					<< "/"
					<< users[i].passWords
					<< "/"
					<< users[i].FamNameSec_name
					<< "/"
					<< users[i].wallet
					<< "/" << endl;
			}
		}
		outfile.close();
	}

	void saveToFileDeposit() {
		std::ofstream outfile;
		outfile.open("deposits.txt");
		if (outfile.is_open()) {
			for (int i = 1; i < users.size(); i++) {
				if (users[i].deposits.size() != 0) {
					for (int k = 0; k < users[i].deposits.size(); k++) {
						outfile
							<< users[i].deposits[k].dateOfDeposit.day
							<< "."
							<< users[i].deposits[k].dateOfDeposit.month
							<< "."
							<< users[i].deposits[k].dateOfDeposit.year
							<< "/"
							<< users[i].deposits[k].typeOfDeposit
							<< "/"
							<< users[i].deposits[k].namesOfDeposit
							<< "/"
							<< users[i].deposits[k].sumOfDeposit
							<< "/";
					}
					outfile << "|" << endl;
				}
				else {
					outfile << "|" << endl;
				}
			}
		}
		outfile.close();
	}

	int getId(std::string log, std::string pin) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].usersLog == log && users[i].passWords == pin) {
				return i + 1;
			}
		}
		return -1;
	}

	std::vector<unsigned int> withdrawMoney(int id, std::vector<unsigned int> numbersCompleteDep, std::string numbersToWithdraw) {
		std::vector<unsigned int> withdrawNumbers;
		for (int i = 0; i < numbersToWithdraw.size(); i++) {
			unsigned int tempNumber;
			if (numbersToWithdraw[i] >= char(48) && numbersToWithdraw[i] <= char(57)) {
				tempNumber = int(numbersToWithdraw[i] - 48) - 1;
				i++;
				while (numbersToWithdraw[i] >= char(48) && numbersToWithdraw[i] <= char(57)) {
					tempNumber += 1;
					tempNumber *= 10;
					tempNumber += int(numbersToWithdraw[i] - 48) - 1;
					i++;
				}
				for (int j = 0; j < numbersCompleteDep.size(); j++) {
					if (tempNumber == numbersCompleteDep[j]) {
						bool isNumberAlready = false;
						for (int k = 0; k < withdrawNumbers.size(); k++) {
							if (tempNumber == withdrawNumbers[k]) { isNumberAlready = true; }
						}
						if(!isNumberAlready){ withdrawNumbers.push_back(tempNumber); }
					}
				}
			}
		}
		//function to withdraw deposit
		withdrawThisDeposit(id, withdrawNumbers);
		saveToFileDeposit();
		saveToFileLogPin();
		return withdrawNumbers;
	}

	void withdrawThisDeposit(int id, std::vector<unsigned int> withdrawNumbers) {
		for (int i = 0; i < withdrawNumbers.size(); i++) {
			users[id].wallet += users[id].deposits[withdrawNumbers[i]].sumOfDeposit + users[id].deposits[withdrawNumbers[i]].percentsOfDeposit;
			vector<Deposit>::iterator toRemove = users[id].deposits.begin() + withdrawNumbers[i];
			users[id].deposits.erase(toRemove);
		}
	}

	bool CreateDeposit(std::string log, std::string pin, std::string name, unsigned long long sum, int type) {
		if (checkEnter(log, pin)) {
			int id = getId(log, pin) - 1;
			createThisDeposit(id, name, sum, type);
			saveToFileDeposit();
			saveToFileLogPin();
			return true;
		}
		else {
			return false;
		}
	}

	bool changeUserName(int id, std::string userName) {
		if (users[id].FamNameSec_name.size()) {
			users[id].FamNameSec_name = userName;
			saveToFileLogPin();
			return true;
		}
		else {
			users[id].FamNameSec_name = userName;
			saveToFileLogPin();
			return false;
		}
	}

	bool CheckIsSumSmallerWallet(int id, unsigned long long sum) {
		if (users[id].wallet >= sum && sum > 100) { return true; }
		else { return false; }
	}

	unsigned long long TopUpAccount(int id, unsigned long long sumToTopUp) {
		users[id].wallet += sumToTopUp;
		saveToFileLogPin();
		return users[id].wallet;
	}

protected:
	bool pubCheckEnter(std::string log, std::string pin) {
		return checkEnter(log, pin);
	}
	bool pubCreateAccount(std::string log, std::string pin) {
		return createAccount(log, pin);
	}
	int pubGetId(std::string log, std::string pin) {
		return getId(log, pin);
	}
	std::string GetLogName(int id) {
		return users[id - 1].usersLog;
	}
	std::string GetPersonName(int id) {
		return users[id - 1].FamNameSec_name;
	}
	long long GetUserWallet(int id) {
		return users[id - 1].wallet;
	}
	std::vector<unsigned int> pubWithdrawMoney(int id, std::vector<unsigned int> numbersCompleteDep, std::string numbersToWithdraw) {
		return withdrawMoney(id - 1, numbersCompleteDep, numbersToWithdraw);
	}
	bool pubCreateDeposit(std::string log, std::string pin, std::string name, unsigned long long sum, int type) {
		return CreateDeposit(log, pin, name, sum, type);
	}
	bool pubChangeUserName(int id, std::string userName) {
		return changeUserName(id - 1, userName);
	}
	bool pubCheckIsSumSmallerWallet(int id, unsigned long long sum) {
		return CheckIsSumSmallerWallet(id - 1, sum);
	}
	bool pubIsDepositHoldComplete(int id, int number) {
		return users[id - 1].deposits[number].isDepositHoldComplete();
	}
	unsigned long long pubTopUpAccount(int id, unsigned long long sumToTopUp) {
		return TopUpAccount(id, sumToTopUp);
	}

	//GETTERS FROM DEPOSITS
	int GetCountOfDeposits(int id) {
		return users[id - 1].deposits.size();
	}

	std::string GetNameOfDeposit(int id, int number) {
		return users[id - 1].deposits[number].namesOfDeposit;
	}
	Date GetDateOfDeposit(int id, int number) {
		return users[id - 1].deposits[number].dateOfDeposit;
	}
	unsigned long long GetSumOfDeposit(int id, int number) {
		return users[id - 1].deposits[number].sumOfDeposit;
	}
	unsigned int GetTypeOfDeposit(int id, int number) {
		return users[id - 1].deposits[number].typeOfDeposit;
	}
	unsigned long GetPercentsOfDeposit(int id, int number) {
		return users[id - 1].deposits[number].percentsOfDeposit;
	}
};