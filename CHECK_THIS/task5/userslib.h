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
#include "additionalFunctions.h"
#include <fstream>
#include <ctime>
using namespace std;
class Deposit;



class Users : private addFunc {

	TodayDate today;
	std::vector<std::string> usersLog;
	std::vector<std::string> passWords;
	std::vector<std::string> FamNameSec_name;
	std::vector<std::vector<Deposit>> deposits;
	std::vector<long long> wallet;

protected:
	Users() {
		careAdmin();
		checkFiles();
	}
private:

	void careAdmin() {
		usersLog.push_back("admin");
		passWords.push_back("admin");
		FamNameSec_name.push_back("I'M ADMIN");
		wallet.push_back(999999);
		std::vector<Deposit> adminDep;
		Deposit dep;
		adminDep.push_back(dep.CareAdminDeposit());
		deposits.push_back(adminDep);
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
			while (getline(infile, line)) {
				std::vector<Deposit> tempDeposit;
				if (line[0] != char(45)) {
					readFromFileDeposits(line, tempDeposit);
					deposits.push_back(tempDeposit);
				}
				else {
					tempDeposit.clear();
					deposits.push_back(tempDeposit);
				}
			}
		}
		infile.close();
	}

	void readFromFile(std::string line) {//tut mojno ubrat' temps
		std::string tempLog;
		std::string tempPin;
		std::string tempFNSn;
		int tempWallet = 0;
		int i = 0;
		while (line[i] != char(47)) {
			tempLog += line[i];
			i++;
		}
		usersLog.push_back(tempLog);
		i++;
		while (line[i] != char(47)) {
			tempPin += line[i];
			i++;
		}
		passWords.push_back(tempPin);
		if (i + 1 != line.size()) {
			i++;
			while (line[i] != char(47)) {
				tempFNSn += line[i];
				i++;
			}
			FamNameSec_name.push_back(tempFNSn);
		}
		if (i + 1 != line.size()) {
			i++;
			while (line[i] != char(47)) {
				tempWallet *= 10;
				tempWallet += int(line[i] - 48);
				i++;
			}
			wallet.push_back(tempWallet);
		}
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
		deposits[id].push_back(dep);
		wallet[id] -= sum;
	}




	bool checkEnter(std::string log, std::string pin) {
		for (int i = 0; i < usersLog.size(); i++) {
			if (usersLog[i] == log && passWords[i] == pin) {
				return true;
			}
		}
		return false;
	}

	bool checkEnterLog(std::string log) {
		for (int i = 0; i < usersLog.size(); i++) {
			if (usersLog[i] == log) {
				return false;
			}
		}
		return true;
	}

	bool createAccount(std::string log, std::string pin) {
		if (checkEnterLog(log)) {
			usersLog.push_back(log);
			passWords.push_back(pin);
			FamNameSec_name.push_back("");
			std::vector<Deposit> tempDepVec;
			deposits.push_back(tempDepVec);
			wallet.push_back(0);
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
			for (int i = 1; i < usersLog.size(); i++) {
				outfile
					<< usersLog[i]
					<< "/"
					<< passWords[i]
					<< "/"
					<< FamNameSec_name[i]
					<< "/"
					<< wallet[i]
					<< "/" << endl;
			}
		}
		outfile.close();
	}

	void saveToFileDeposit() {
		std::ofstream outfile;
		outfile.open("deposits.txt");
		if (outfile.is_open()) {
			for (int i = 1; i < usersLog.size(); i++) {
				if (deposits[i].size() != 0) {
					for (int k = 0; k < deposits[i].size(); k++) {
						outfile
							<< deposits[i][k].dateOfDeposit.day
							<< "."
							<< deposits[i][k].dateOfDeposit.month
							<< "."
							<< deposits[i][k].dateOfDeposit.year
							<< "/"
							<< deposits[i][k].typeOfDeposit
							<< "/"
							<< deposits[i][k].namesOfDeposit
							<< "/"
							<< deposits[i][k].sumOfDeposit
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
		for (int i = 0; i < usersLog.size(); i++) {
			if (usersLog[i] == log && passWords[i] == pin) {
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
			wallet[id] += deposits[id][withdrawNumbers[i]].sumOfDeposit + deposits[id][withdrawNumbers[i]].percentsOfDeposit;
			vector<Deposit>::iterator toRemove = deposits[id].begin() + withdrawNumbers[i];
			deposits[id].erase(toRemove);
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
		if (FamNameSec_name[id].size()) {
			FamNameSec_name[id] = userName;
			saveToFileLogPin();
			return true;
		}
		else {
			FamNameSec_name[id] = userName;
			saveToFileLogPin();
			return false;
		}
	}

	bool CheckIsSumSmallerWallet(int id, unsigned long long sum) {
		if (wallet[id] >= sum && sum > 100) { return true; }
		else { return false; }
	}

	unsigned long long TopUpAccount(int id, unsigned long long sumToTopUp) {
		wallet[id] += sumToTopUp;
		saveToFileLogPin();
		return wallet[id];
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
		return usersLog[id - 1];
	}
	std::string GetPersonName(int id) {
		return FamNameSec_name[id - 1];
	}
	long long GetUserWallet(int id) {
		return wallet[id - 1];
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
		return deposits[id - 1][number].isDepositHoldComplete();
	}
	unsigned long long pubTopUpAccount(int id, unsigned long long sumToTopUp) {
		return TopUpAccount(id, sumToTopUp);
	}

	//GETTERS FROM DEPOSITS
	int GetCountOfDeposits(int id) {
		return deposits[id - 1].size();
	}

	std::string GetNameOfDeposit(int id, int number) {
		return deposits[id - 1][number].namesOfDeposit;
	}
	Date GetDateOfDeposit(int id, int number) {
		return deposits[id - 1][number].dateOfDeposit;
	}
	unsigned long long GetSumOfDeposit(int id, int number) {
		return deposits[id - 1][number].sumOfDeposit;
	}
	unsigned int GetTypeOfDeposit(int id, int number) {
		return deposits[id - 1][number].typeOfDeposit;
	}
	unsigned long GetPercentsOfDeposit(int id, int number) {
		return deposits[id - 1][number].percentsOfDeposit;
	}
};