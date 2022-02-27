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
#include <random>
#include <time.h>
#include <cstdlib>
using namespace std;

class Money;




class Menu{
	
	vector<string> namesofdeposites;
	vector<int> rubofdeposites;
	vector<int> centsofdeposites;


public:
	void menu1() {
		int vihod = 0;
		Money first;
		
		
		while (vihod != 1) {
			int ran;
			cout
				<< "for quick test u can use random"
				<< endl
				<< "do it? (press 1)"
				<< endl;
			cin >> ran; cout << endl;//da, ya znau, chto luchshe bilo bi sdelat' eto na dva raznih if, no ya uje nachal tak
			int newD = 0;
			cout << "do you want to create new deposit?\n (1 - yes)\n";
			if (ran == 1) {
				newD = 1;
			}
			else {
				cin >> newD;
			}
			if (newD == 1) {
				int r;
				int c;
				string name;
				if (ran == 1) {
					r = rand() % 500 + 1;
					c = rand() % 500 + 1;
					name = "RANDOM #" + to_string(rand());
					cout << "write the name of deposit: " << name << endl;
					cout << "RUBLES: " << r << endl;
					cout << "CENTS: " << c << endl;
				}
				else {
					cout << "write the name of deposit: "; cin >> name; cout << endl;
					cout << "RUBLES: "; cin >> r; cout << endl;
					cout << "CENTS: "; cin >> c; cout << endl;
				}
				first.Sozdanie(namesofdeposites, rubofdeposites, centsofdeposites, r, c, name);
				first.Print2(rubofdeposites, centsofdeposites, namesofdeposites.size() - 1);
			}
			int var;
			cout
				<< "what do u want to do?\n"
				<< "0 - skip\n"
				<< "1 - to get all deposites's names\n"
				<< "2 - to get all deposites\n"
				<< endl;
			if (ran == 1) {
				var = 2;
			}
			else {
				cin >> var;
			}
			first.VivodDepositov(namesofdeposites, rubofdeposites, centsofdeposites, var);

			enum Znak {
				plus = 43,
				minus = 45
			};
			char znak = plus;
			/*int dep1;
			int dep2;*/

			if (ran == 1 && first.ProverkaCalcComp(namesofdeposites, rubofdeposites, centsofdeposites) == true) {
				cout
					<< "what do u want to do?\n"
					<< "0 - skip\n"
					<< "1 - to calculate\n"
					<< "2 - to compare\n"
					<< "1 and 2\n"
					<< endl
					<< "calculate(+): 1 and 2\n"
					<< endl;
				
				int dep1 = 1;
				int dep2 = 2;
				first.Calculate(namesofdeposites, rubofdeposites, centsofdeposites, znak, dep1, dep2);
				cout << "compare: 1 and 2\n" << endl;
				first.Compare(namesofdeposites, rubofdeposites, centsofdeposites, dep1, dep2);
			}
			if ( ran != 1 && first.ProverkaCalcComp(namesofdeposites, rubofdeposites, centsofdeposites) == true) {
				cout
					<< "what do u want to do?\n"
					<< "0 - skip\n"
					<< "1 - to calculate\n"
					<< "2 - to compare\n"
					<< endl;
				cin >> var;
				int dep1;
				int dep2;
				if (var == 1) {
					cout << "which deposits do u want to calculate" << endl;
					cout << "first: " << endl;
					cin >> dep1;
					while (namesofdeposites.size() < dep1 || dep1 <= 0) {
						cout << "this deposit doesn't exist" << endl;
						cin >> dep1;
					}
					cout << "second: " << endl;
					cin >> dep2;
					while (namesofdeposites.size() < dep2 || dep2 <= 0 || dep2 == dep1) {
						if (namesofdeposites.size() < dep2 || dep2 <= 0) {
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
				}
				if (var == 2) {
					cout << "which deposits do u want to compare" << endl;
					//int dep1, dep2;
					cout << "first: " << endl;
					cin >> dep1;
					while (namesofdeposites.size() < dep1 || dep1 <= 0) {
						cout << "this deposit doesn't exist" << endl;
						cin >> dep1;
					}
					cout << "second: " << endl;
					cin >> dep2;
					while (namesofdeposites.size() < dep2 || dep2 <= 0 || dep2 == dep1) {
						if (namesofdeposites.size() < dep2 || dep2 <= 0) {
							cout << "this deposit doesn't exist" << endl;
						}
						if (dep2 == dep1) {
							cout << "this deposit has already been selected already" << endl;
						}
						cin >> dep2;
					}
				}
				if (var == 1) {//calculat
					first.Calculate(namesofdeposites, rubofdeposites, centsofdeposites, znak, dep1, dep2);
				}//deystvie s depositami + or -
				if (var == 2) {//compare
					first.Compare(namesofdeposites, rubofdeposites, centsofdeposites, dep1, dep2);
				}
			}
			cout << "do u want to exit?\n(1 - vihod)\n" << endl;
			cin >> vihod; cout << endl;
			if (vihod == 1) {
				cout << "programmed stoped" << endl;
				break;
			}
			//end of while for work
		}
	}
};
