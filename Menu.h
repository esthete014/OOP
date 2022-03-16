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

//libraries
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//files
#include "color.h"
#include "Taylor_series.h"

class TaylorSeries;



class Menu {
	friend TaylorSeries;

public:
	void menu() {
		//podstanovka nomera dlya files
		vector<char> pathn;
		for (int i = 0; i < 10; i++) {
			pathn.push_back(char(i + 48));
		}
		//vibor path with name of files
		vector<string> PATH;
		PATH.push_back("D:\\c++/oop/Taylor_series/Taylor_series");
		PATH.push_back("C:\\Users\\77777\\Desktop\\777\\OOP_2nd_semestr\\Taylor_series");
		cout << green << "You chose HEX variant!" << white << endl;
		cout << "You can choose path or write new" << endl;
		for (int i = 0; i < PATH.size(); i++) {
			cout << i + 1 << " " << PATH[i] << endl;
		}
		int c = -1;
		while (c < 0 || c > PATH.size()) {
			cout
				<< "0 - Write new path"
				<< endl
				<< "1 - " << PATH.size() << " : choose"
				<< endl;
			cin >> c;
		}
		int PATHN = 0;
		if (c == 0) {
			string p;
			cin >> p;
			PATH.push_back(p);
			PATHN = PATH.size() - 1;
		}
		else {
			PATHN = c - 1;
		}
		//inicialisation
		TaylorSeries TS[100];
		//chtenie dlya proverki created files
		for (int i = 0; i < 99; i++) {
			string line;
			ifstream infile;
			string path1 = PATH[PATHN];
			string path3 = ".txt";
			string path = path1 + pathn[i / 10] + pathn[i % 10] + path3;
			infile.open(path);
			if (infile.is_open()) {
				int hod = 0;
				while (getline(infile, line)) {
					//TS[i].ChtenieChisla(line, TS[i]);
				}
				//TS[i].VivodSBukvami(TS[i], i);
				//cout << endl;
			}
			infile.close();
		}
		int flaglimit = 0;
		while (true) {
			/*cout << blue << "<<<<<<<[ MENU ]>>>>>>>" << endl;
			cout << "1 - " << endl;
			cout << "2 - " << endl;
			cout << "3 - " << endl;
			cout << "4 - " << endl;*/
			TaylorSeries first;
			cout << "Enter your x, eps, count" << endl;
			int a = 0;
			double x;
			double eps;
			int count;
			cin >> x;
			cin >> eps;
			cin >> count;

			first.toSolveFunctionsSinElement(x, eps, count, 0);
			system("pause");









		}

	}
};