#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;




class Money
{
	

public:

	int m_rub;
	int m_cent;
	

	//constructor to create(po umolchaniyu)
	Money() {
		m_rub = 0;
		m_cent = 0;
		cout << "RUBLES: " << m_rub << endl;
		cout << "CENTS: " << m_cent << "\n" << endl;
		
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
		cout << _name << endl;
		cout << "RUBLES: " << m_rub << endl;
		cout << "CENTS: " << m_cent << "\n" << endl;
	};

	/*
	~Money() {
		namesofdeposites.clear();
		rubofdeposites.clear();
		centsofdeposites.clear();
	}
	
	void Destructor(vector<string>* names, vector<int>* rub, vector<int>* cents) {
		delete* names;
		delete* rub;
		delete* cents;
	}
	*/

	//constructor to get
	void toGet()
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
	
	//constructor to get cherez scanf(prosto tak napisal)
	void vvod(string _name){
		int r;
		int c;
		printf("write rubles for the first deposit: ");
		scanf_s("%d", &r);
		printf("\n");
		printf("write cents for the first deposit: ");
		scanf_s("%d", &c);
		printf("\n");
		//string name = _name;
		//Money _name;
		//m_rub = r;
		//m_cent = c;
	}
	

	//constructors to print
	// 
	//1vid:"rub: 123 cent: 32"
	//2vid:"deposit: 123.32"
	//
	void Print1() {
		cout << "RUBLES: " << m_rub << "\n" << "CENTS: " << m_cent << endl;
	};
	void Print2() {
		cout << "Your deposit: " << m_rub << "." << m_cent << endl;
	}



	//metod calculate
	void Calculate(vector<string> names, vector<int> rub, vector<int> cents) {
		cout << "which deposits do u want to calculate" << endl;
		int dep1, dep2;
		cout << "first: " << endl;
		cin >> dep1;
		while (sizeof(names) < dep1 || dep1 <= 0) {
			cout << "this deposit doesn't exist" << endl;
			cin >> dep1;
		}
		cout << "second: " << endl;
		cin >> dep2;
		while (sizeof(names) < dep2 || dep2 <= 0) {
			cout << "this deposit doesn't exist" << endl;
			cin >> dep2;
		}
		cout << "what to do: + or -" << endl;
		char znak = 43;
		cin >> znak;
		while (znak != 43 && znak != 45) {
			cout << "write the + or -" << endl;
			cin >> znak;
		}
		int resrub, rescent;
		if (znak == 43) {//+
			rescent = cents[dep1 - 1] + cents[dep2 - 1];
			if (rescent >= 100) {
				resrub = rub[dep1 - 1] + rub[dep2 - 1] + (rescent / 100);
				rescent %= 100;
			}
			else {
				resrub = rub[dep1 - 1] + rub[dep2 - 1];
			}
		}
		if (znak == 45) {//-
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
		while (sizeof(names) < dep1 || dep1 <= 0) {
			cout << "this deposit doesn't exist" << endl;
			cin >> dep1;
		}
		cout << "second: " << endl;
		cin >> dep2;
		while (sizeof(names) < dep2 || dep2 <= 0) {
			cout << "this deposit doesn't exist" << endl;
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













	/*
	//metod destruction
	void Destructor(vector<string> names, vector<int> rub, vector<int> cents) {
		delete& names;
		delete& rub;
		delete& cents;
	}
	*/



	//metod dlya raboti(i reshil chto takim obrazom mojno budet uprostit' konstrukciyu vsey programmi, no mb potom po metodam razobyu)
	void Work() {

		int vihod = 0;
		
		
		vector<string> namesofdeposites(0);
		vector<int> rubofdeposites(0);
		vector<int> centsofdeposites(0);


		while (vihod != 1) {

			//sozdanie deposita
			int newD = 0;
			cout << "do you want to create new deposit?\n (1 - yes)\n"; cin >> newD;
			if (newD == 1) {
				string name;
				cout << "write the name of deposit: "; cin >> name;
				int r;
				int c;
				cout << "RUBLES: "; cin >> r; cout << endl;
				cout << "CENTS: "; cin >> c; cout << endl;
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
				for (int i = 0; i < namesofdeposites.size(); i++) {
					cout << namesofdeposites[i] << endl;
				}
			}if (var == 2) {
				cout << "all deposites:\n" << endl;
				for (int i = 0; i < namesofdeposites.size(); i++) {
					int a = i + 1;
					cout
						<< "name"
						<< a
						<< "   "
						<< namesofdeposites[i]
						<< "   "
						<< "Rub: "
						<< rubofdeposites[i]
						<< "   "
						<< "Cents: "
						<< centsofdeposites[i]
						<< endl;
				}
			}
			else {//ono skipaet deystviya s depositami, mojno ubrat' esli nado
				continue;
			}

			if (sizeof(namesofdeposites) != 1) {
				cout
					<< "what do u want to do?\n"
					<< "0 - skip\n"
					<< "1 - to calculate\n"
					<< "2 - to compare\n"
					<< endl;
				cin >> var;
				if (var == 1) {//calculat
					Calculate(namesofdeposites, rubofdeposites, centsofdeposites);
				}//deystvie s depositami + or -

				if (var == 2) {//compare
					Compare(namesofdeposites, rubofdeposites, centsofdeposites);
				}
			}



			cout << "do u want to exit?\n(1 - vihod)\n" << endl;
			cin >> vihod; cout << endl;
			if (vihod == 1) {
				cout << "programmed stoped" << endl;
				//delete namesofdeposites;
				//delete rubofdeposites;
				//delete centsofdeposites;
				//Destructor(namesofdeposites, rubofdeposites, centsofdeposites);
				break;
			}
			//end of while for work
		}
		//end of void work
	}
	//end of class Money
};
