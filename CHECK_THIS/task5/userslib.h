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
#include <fstream>
using namespace std;
class Deposit;

class Users : private addFunc {

	std::vector<std::string> usersLog;
	std::vector<std::string> passWords;
	std::vector<std::string> FamNameSec_name;
	std::vector<Deposit> deposits;
	std::vector<int> wallet;

protected:
	Users() {
		careAdmin();
		checkFiles();
	}
private:

	void careAdmin() {
		usersLog.push_back("admin");
		passWords.push_back("admin");
		Deposit adminDep;
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
		std::fstream infile("deposites.txt", std::ios_base::in);
		infile.open("deposites.txt");
		if (!infile.is_open()) {
			std::fstream infile("deposites.txt", std::ios_base::out);
		}
		infile.close();
		infile.open("deposites.txt");
		if (infile.is_open()) {
			Deposit dep;
			while (getline(infile, line)) {
				if (line[0] != char(45)) {
					readFromFileDeposits(line, dep);
				}
			}
			deposits.push_back(dep);
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


	void readFromFileDeposits(std::string line, Deposit &dep) {
		int i = 0;
		Date date;
		transformLineToDate(line, date, i);
		dep.dateOfDeposit.push_back(date);


		int tempType = 0;
		while (line[i] != char(47)) {
			tempType *= 10;
			tempType += int(line[i]) - 48;
			i++;
		}
		dep.typeOfDeposit.push_back(tempType);


		i++;
		std::string tempName;
		while (line[i] != char(47)) {
			tempName += line[i];
			i++;
		}
		dep.names.push_back(tempName);


		i++;
		int tempSumm = 0;
		while (line[i] != char(47)) {
			tempSumm *= 10;
			tempSumm += int(line[i]) - 48;
			i++;
		}
		dep.sumOfDeposit.push_back(tempSumm);
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
			saveToFileLogPin();
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
			for (int i = 0; i < usersLog.size(); i++) {
				outfile << usersLog[i] << "/" << passWords[i] << "/" << endl;
			}
		}
		outfile.close();
	}

	void saveToFileDeposit(int n) {
		ofstream outfile;
		outfile.open("deposites.txt");
		if (outfile.is_open()) {
			for (int i = 0; i < usersLog.size(); i++) {
				for (int k = 0; k < deposits[n].dateOfDeposit.size(); k++) {
					outfile
						<< deposits[n].dateOfDeposit[k].day
						<< "."
						<< deposits[n].dateOfDeposit[k].month
						<< "."
						<< deposits[n].dateOfDeposit[k].year
						<< "/"
						<< deposits[n].typeOfDeposit[k]
						<< "/"
						<< deposits[n].names[k]
						<< "/"
						<< deposits[n].sumOfDeposit[k]
						<< endl;
				}
			}
		}
		outfile.close();
	}

	int getId(std::string log, std::string pin) {
		for (int i = 0; i < usersLog.size(); i++) {
			if (usersLog[i] == log && passWords[i] == pin) {
				return i;
			}
		}
		return -1;
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
		return usersLog[id];
	}
	std::string GetPersonName(int id) {
		return FamNameSec_name[id];
	}

	//GETTERS FROM DEPOSITS
	std::string GetNameOfDeposit(int id, int number) {
		return deposits[id].names[number];
	}
	Date GetDateOfDeposit(int id, int number) {
		return deposits[id].dateOfDeposit[number];
	}
	int GetSummOfDeposit(int id, int number) {
		return deposits[id].sumOfDeposit[number];
	}
	int GetTypeOfDeposit(int id, int number) {
		return deposits[id].sumOfDeposit[number];
	}
};