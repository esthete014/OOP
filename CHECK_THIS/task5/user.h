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
class Deposit;



class USER {
	friend Users;
	std::string usersLog;
	std::string passWords;
	std::string FamNameSec_name;
	std::vector<Deposit> deposits;
	long long wallet;

	std::string userToString() {
		std::string outPut = "";
		outPut += this->usersLog + "/" + this->passWords + "/" + this->FamNameSec_name + "/" + std::to_string(this->wallet) + "/";// (this->wallet).ToString();
		return outPut;
	}

	bool checkEnter(std::string log, std::string pin) {
		if (this->usersLog == log && this->passWords == pin) {
			return true;
		}
		return false;
	}

	bool checkEnterLog(std::string log) {
		if (this->usersLog == log) {
			return false;
		}
		return false;
	}

	static USER createUSERbyString(std::string line) {
		USER user;//tut mojno ubrat' temps
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
		return user;
	}
};