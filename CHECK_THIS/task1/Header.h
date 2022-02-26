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
	void Print2() {
		cout
			<< "Your deposit: "
			<< m_rub
			<< "."
			<< m_cent
			<< endl;
	}


	//metod calculate
	void Calculate(vector<string> names, vector<int> rub, vector<int> cents) {
		enum Znak{
			plus = 43,
			minus = 45
		};
		cout << "which deposits do u want to calculate" << endl;
		int dep1, dep2;
		cout << "first: " << endl;
		cin >> dep1;
		while (names.size() < dep1 || dep1 <= 0) {
			cout << "this deposit doesn't exist" << endl;
			cin >> dep1;
		}
		cout << "second: " << endl;
		cin >> dep2;
		while (names.size() < dep2 || dep2 <= 0 || dep2 == dep1) {
			if (names.size() < dep2 || dep2 <= 0) {
				cout << "this deposit doesn't exist" << endl;
			}
			if (dep2 == dep1) {
				cout << "this deposit has already been selected already" << endl;
			}
			cin >> dep2;
		}
		cout << "what to do: + or -" << endl;
		char znak = plus;
		cin >> znak;
		while (znak != plus && znak != minus) {
			cout << "write the + or -" << endl;
			cin >> znak;
		}
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
			<< znak
			<< names[dep2 - 1]
			<< " = "
			<< resrub
			<< "."
			<< rescent
			<< endl;
	}//end of calculate

	//metod compare
	void Compare(vector<string> names, vector<int> rub, vector<int> cents) {
		cout << "which deposits do u want to compare" << endl;
		int dep1, dep2;
		cout << "first: " << endl;
		cin >> dep1;
		while (names.size() < dep1 || dep1 <= 0) {
			cout << "this deposit doesn't exist" << endl;
			cin >> dep1;
		}
		cout << "second: " << endl;
		cin >> dep2;
		while (names.size() < dep2 || dep2 <= 0 || dep2 == dep1) {
			if (names.size() < dep2 || dep2 <= 0) {
				cout << "this deposit doesn't exist" << endl;
			}
			if (dep2 == dep1) {
				cout << "this deposit has already been selected already" << endl;
			}
			cin >> dep2;
		}
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
	void Sozdanie(vector<string> &namesofdeposites, vector<int> &rubofdeposites, vector<int> &centsofdeposites) {
		int newD = 0;
		cout << "do you want to create new deposit?\n (1 - yes)\n"; cin >> newD;
		if (newD == 1) {
			string name;
			cout << "write the name of deposit: "; cin >> name;
			int r;
			int c;
			cout << "RUBLES: "; cin >> r; cout << endl;
			cout << "CENTS: "; cin >> c; cout << endl;
			/*if ((cin >> *r); != 1) {//dlya proverki na tip potom dodelayu
				while (fgetc(stdin) != '\n') continue;
			}*/
			Money(name, r, c);
			if (c >= 100) {//eto doljno zamenyat' Money(name, r, c); no ono ne rabotaet((
				r = r + (c / 100);
				c = c % 100;
			}

			//add name of deposit to vector
			namesofdeposites.push_back(name);
			rubofdeposites.push_back(r);
			centsofdeposites.push_back(c);
		};
	}//end of sozdanie deposita

	//vivod depositov
	void VivodDepositov(vector<string>& namesofdeposites, vector<int>& rubofdeposites, vector<int>& centsofdeposites) {
		cout
			<< "what do u want to do?\n"
			<< "0 - skip\n"
			<< "1 - to get all deposites's names\n"
			<< "2 - to get all deposites\n"
			<< endl;
		int var;
		cin >> var;
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
	void ProverkaCalcComp(vector<string>& namesofdeposites, vector<int>& rubofdeposites, vector<int>& centsofdeposites) {
		if (namesofdeposites.size() > 1) {
			cout
				<< "what do u want to do?\n"
				<< "0 - skip\n"
				<< "1 - to calculate\n"
				<< "2 - to compare\n"
				<< endl;
			int var;
			cin >> var;
			if (var == 1) {//calculat
				Calculate(namesofdeposites, rubofdeposites, centsofdeposites);
			}//deystvie s depositami + or -
			if (var == 2) {//compare
				Compare(namesofdeposites, rubofdeposites, centsofdeposites);
			}
		}
	}//end of proverka na vozmojnost' calculirovat' i sravnivat' depositi
};
