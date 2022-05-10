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
};