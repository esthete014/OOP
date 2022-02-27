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
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

class Menu;

// || COMPONENTS of Money ||
// -------------------------
// 1)inputKeyboard
// constructor dlya vvoda rubley i centov
// 
// 2)Print1, Print2
// vivod rubley i centov 1vid(dlya vivoda v cikle):"Name# (name) RUBLES: 123 CENTS: 32" 2vid:"deposit: 123.32"
// 
// 3)Calculate
// skladivaet i vichitaet depositi(menu vibora depositov)
// 
// 4)Compare
// sravnivaet depoiti(menu vibora depositov)
// 
// 5)ProverkaCalcComp
// menu vibora deystviya calculat or compare and proverka na vozmojnost' etogo(kolichestva depositov > 2)
// 
// 6)VivodDepositov
// menu vivoda
// 



class Money
{
public:
	friend Menu;

protected:
	
	int m_rub;
	int m_cent;
	vector<string> namesofdeposites;
	vector<int> rubofdeposites;
	vector<int> centsofdeposites;

	//constructor to create(po umolchaniyu)
	Money() {
		m_rub = 0;
		m_cent = 0;
		vector<string> namesofdeposites(0);
		vector<int> rubofdeposites(0);
		vector<int> centsofdeposites(0);
		
	}
	//inicialization
	Money(string _name, int r, int c) {
		if (c >= 100) {
			m_cent = c % 100;
			m_rub = r + (c / 100);
		}
		else {
			m_rub = r;
			m_cent = c;
		}
	};

	//destructor
	~Money() {}


	//constructor to get
	void inputKeyboard()
	{
		int r;
		int c;
		cout << "RUBLES: ";
		cin >> r;
		cout << "\n" << "CENTS: ";
		cin >> c;
		cout << "\n" << endl;
		m_rub = r;
		m_cent = c;
	};
	

	//constructors to print
	// 
	//1vid:"Name# (name) RUBLES: 123 CENTS: 32"
	//2vid:"deposit: 123.32"
	//
	void Print1(vector<string> names, vector<int> rub, vector<int> cents, int hod) {
		cout
			<< "Name"
			<< hod + 1
			<< "    "
			<< names[hod]
			<< "    "
			<< "RUBLES: "
			<< rub[hod]
			<< "    "
			<< "CENTS: "
			<< cents[hod]
			<< endl;
	};
	void Print2(vector<int> rub, vector<int> cents, int hod) {
		cout
			<< "Your deposit: "
			<< rub[hod]
			<< "."
			<< cents[hod]
			<< "\n"
			<< endl;
	}


	//metod calculate
	void Calculate(vector<string> names, vector<int> rub, vector<int> cents, char znak, int dep1, int dep2) {
		enum Znak {
			plus = 43,
			minus = 45
		};
		int resrub, rescent;
		if (znak == plus) {//+
			rescent = cents[dep1 - 1] + cents[dep2 - 1];
			if (rescent >= 100) {
				resrub = rub[dep1 - 1] + rub[dep2 - 1] + (rescent / 100);
				rescent %= 100;
			}
			else {
				resrub = rub[dep1 - 1] + rub[dep2 - 1];
			}
		}
		if (znak == minus) {//-
			rescent = cents[dep1 - 1] - cents[dep2 - 1];
			if (rescent < 0) {
				resrub = rub[dep1 - 1] - rub[dep2 - 1] - 1;
				rescent = 100 + rescent;
			}
			else {
				resrub = rub[dep1 - 1] - rub[dep2 - 1];
			}
		}
		cout
			<< names[dep1 - 1]
			<< " "
			<< znak
			<< " "
			<< names[dep2 - 1]
			<< " = "
			<< resrub
			<< "."
			<< rescent
			<< endl;
	}//end of calculate

	//metod compare
	void Compare(vector<string> names, vector<int> rub, vector<int> cents, int dep1, int dep2) {
		
		if (rub[dep1 - 1] < rub[dep2 - 1]) {
			cout
				<< dep2
				<< ") "
				<< names[dep2 - 1]
				<< " bigger"
				<< endl;
		}
		if (rub[dep1 - 1] > rub[dep2 - 1]) {
			cout
				<< dep1
				<< ") "
				<< names[dep1 - 1]
				<< " bigger"
				<< endl;
		}
		if (rub[dep1 - 1] == rub[dep2 - 1]) {
			if (cents[dep1 - 1] < cents[dep2 - 1]) {
				cout
					<< dep2
					<< ") "
					<< names[dep2 - 1]
					<< " bigger"
					<< endl;
			}
			if (cents[dep1 - 1] > cents[dep2 - 1]) {
				cout
					<< dep1
					<< ") "
					<< names[dep1 - 1]
					<< " bigger"
					<< endl;
			}
			if (cents[dep1 - 1] == cents[dep2 - 1]) {
				cout
					<< names[dep1 - 1]
					<< " = "
					<< names[dep2 - 1]
					<< endl;
			}
		}
	}//end of compare

	//sozdanie deposita
	void Sozdanie(vector<string> &namesofdeposites, vector<int> &rubofdeposites, vector<int> &centsofdeposites, int r, int c, string name) {
		
		Money(name, r, c);
		if (c >= 100) {//eto doljno zamenyat' Money(name, r, c); no ono ne rabotaet((
			r = r + (c / 100);
			c = c % 100;
		}

		//add name of deposit to vector
		namesofdeposites.push_back(name);
		rubofdeposites.push_back(r);
		centsofdeposites.push_back(c);
	}//end of sozdanie deposita

	//vivod depositov
	void VivodDepositov(vector<string>& namesofdeposites, vector<int>& rubofdeposites, vector<int>& centsofdeposites, int var) {
		
		if (var == 1) {
			cout << "\nall deposites's names:\n" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < namesofdeposites.size(); i++) {
				cout << namesofdeposites[i] << endl;
			}
			cout << "========================================" << endl;
		}
		if (var == 2) {
			cout << "all deposites:\n" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < namesofdeposites.size(); i++) {
				int hod = i + 1;
				Print1(namesofdeposites, rubofdeposites, centsofdeposites, i);
			}
			cout << "========================================" << endl;
		}
		cout << endl;
	}//end of vivod depositov

	//proverka na vozmojnost' calculirovat' i sravnivat' depositi
	bool ProverkaCalcComp(vector<string>& namesofdeposites, vector<int>& rubofdeposites, vector<int>& centsofdeposites) {
		bool da;
		if (namesofdeposites.size() > 1) {
			da = true;
		}
		else {
			da = false;
		}
		return(da);
	}//end of proverka na vozmojnost' calculirovat' i sravnivat' depositi
};
