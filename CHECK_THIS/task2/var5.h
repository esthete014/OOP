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

#include <vector>
#include <string>
#include "Color.h"

class Menu;

class Hex {
protected:
	friend Menu;



	//string pathn;
	string path3 = ".txt";
	vector<int> c;
	vector<char> pathn;
	int todel = 0;
	//int hexznak = 1;
	void p() {
		for (int i = 0; i < 10; i++) {
			pathn.push_back(char(i + 48));
		}
	}
	vector<char> CifriB = { '0', '1', '2' , '3', '4', '5' , '6' , '7' , '8' , '9' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' };
	vector<char> CifriS = { 'a' , 'b' , 'c' , 'd' , 'e' , 'f' };
	//Hex();

	void SostavlenieChisla(string str, Hex &num) {
		for (int i = 0; i < str.size(); i++) {
			//if (i == 0) {
				num.c.push_back(0);
			//}
			for (int j = 0; j < CifriB.size(); j++) {
				if (str[i] == CifriB[j]) {
					num.c[c.size() - 1] *= 10;
					num.c[c.size() - 1] += j;
				}
			}
			for (int j = 0; j < CifriS.size(); j++) {
				if (str[i] == CifriS[j]) {
					num.c[c.size() - 1] *= 10;
					num.c[c.size()-1] += j + 10;
				}
			}
			/*if (str[i + 1] == ' ') {
				num.c.push_back(0);
			}*/
		}
	}

	void ChtenieChisla(string str, Hex& num) {
		for (int i = 0; i < str.size(); i++) {
			if (i == 0) {
				num.c.push_back(0);
			}
			for (int j = 0; j < CifriB.size(); j++) {
				if (str[i] == CifriB[j]) {
					num.c[c.size() - 1] *= 10;
					num.c[c.size() - 1] += j;
				}
			}
			for (int j = 0; j < CifriS.size(); j++) {
				if (str[i] == CifriS[j]) {
					num.c[c.size() - 1] *= 10;
					num.c[c.size() - 1] += j + 10;
				}
			}
			if (str[i + 1] == ' ') {
				num.c.push_back(0);
			}
		}
	}

	void CreateNewNumber(Hex &num, int nomer, vector<string> PATH, int PATHN, string str) {
		SostavlenieChisla(str, num);
		VivodSBukvami(num, nomer);
		//num.VivodChislom(num);
		SozdanieFile(num, nomer, PATH, PATHN);
	}

	void CreateNewRandNumber(Hex& num, int nomer, vector<string> PATH, int PATHN) {
		int len = 1 + rand() % 6;
		for (int i = 0; i < len; i++) {
			int r = rand() % 16;
			num.c.push_back(r);
		}
		VivodSBukvami(num, nomer);
		SozdanieFile(num, nomer, PATH, PATHN);
	}

	void SozdanieFile(Hex num, int nomer, vector<string> PATH, int PATHN) {
		string path1 = PATH[PATHN];
		//for (int i = 0; i < 101; i++) {
			//pathn.push_back(char(i + 48));
		p();
		string path = path1 + pathn[nomer / 10] + pathn[nomer % 10] + path3;
		ofstream out;
		out.open(path);
		if (out.is_open()) {
			for (int i = 0; i < num.c.size(); i++) {
				out << num.c[i];
				if (i != num.c.size() - 1) {
					out << " ";
				}
			}
			out << endl;
		}
		out.close();
		//cout << "End of program" << endl;
	}

	void VivodSBukvami(Hex& num, int nomer) {
		p();
		cout << yellow << "HEX " << pathn[nomer / 10] << pathn[nomer % 10] << " | " << white;
		for (int i = 0; i < num.c.size(); i++) {
			cout << CifriB[num.c[i]] << " ";
		}
		cout << yellow << "|" << white << endl;
	}

	void VivodChislom(Hex &num) {
		cout << yellow << "|" << white << endl;
		for (int i = 0; i < num.c.size(); i++) {
			cout << num.c[i] << " ";
		}
	}

	void AddOrSubtractHEX(Hex obj1, Hex obj2, Hex& obj3, int nomer1, int nomer2, int nomer3, int znak, vector<string> PATH, int PATHN) {
		/*int y = 0;
		if (obj1.hexznak == 1 && obj2.hexznak == 1 && znak == 1) {
			y = 1;
		}
		if (obj1.hexznak == 2 && obj2.hexznak == 2 && znak == 1) {
			y = 1;
			obj3.hexznak = 2;
		}
		if (obj1.hexznak == 1 && obj2.hexznak == 2 && znak == 1) {
			y = 2;
		}
		if (obj1.hexznak == 2 && obj2.hexznak == 1 && znak == 1) {
			y = 2;
		}
		if (obj1.hexznak == 1 && obj2.hexznak == 1 && znak == 2) {
			y = 2;
		}
		if (obj1.hexznak == 1 && obj2.hexznak == 2 && znak == 2) {
			y = 1;
			znak = 1;
		}
		if (obj1.hexznak == 2 && obj2.hexznak == 1 && znak == 2) {
			y = 2;
			obj3.hexznak = 2;
		}
		if (obj1.hexznak == 2 && obj2.hexznak == 2 && znak == 2) {
			y = 2;
			obj2.hexznak = 1;
			znak = 1;
		}*/
		if (znak == 1) {
			if (obj1.c.size() > obj2.c.size()) {
				obj3.c = obj1.c;
				AddHEX(obj3, obj2);
			}
			else {
				obj3.c = obj2.c;
				AddHEX(obj3, obj1);
			}
			VivodSBukvami(obj1, nomer1);
			cout << "  +" << endl;
			VivodSBukvami(obj2, nomer2);
			cout << "  =" << endl;
			VivodSBukvami(obj3, nomer3);
			SozdanieFile(obj3, nomer3, PATH, PATHN);
		}
		/*if (y == 2) {

		}*/
	}

	void AddHEX(Hex& objres, Hex objadd) {
		for (int i = 0; i < objadd.c.size(); i++) {
			objres.c[objres.c.size() - i - 1] += objadd.c[objadd.c.size() - i - 1];
			if (objres.c[objres.c.size() - i - 1] > 15) {
				if (objres.c.size() - i - 1 == 0) {
					auto iter = objres.c.cbegin();
					objres.c.emplace(iter, 0);
				}
				objres.c[objres.c.size() - i - 2] += objres.c[objres.c.size() - i - 1] / 16;
				objres.c[objres.c.size() - i - 1] %= 16;
			}
		}
	}

	void CompareHex(Hex obj1, Hex obj2, int nomer1, int nomer2) {
		if (obj1.c.size() < obj2.c.size()) {
			for (int j = 0; j < obj2.c.size() * 2 + 10; j++) {
				cout << '-';
			}
			cout << endl;
			VivodSBukvami(obj1, nomer1);
			cout << "  <" << endl;
			VivodSBukvami(obj2, nomer2);
			for (int j = 0; j < obj2.c.size() * 2 + 10; j++) {
				cout << '-';
			}
			cout << endl;
		}
		else if (obj1.c.size() > obj2.c.size()) {
			for (int j = 0; j < obj1.c.size() * 2 + 10; j++) {
				cout << '-';
			}
			cout << endl;
			VivodSBukvami(obj1, nomer1);
			cout << "  >" << endl;
			VivodSBukvami(obj2, nomer2);
			for (int j = 0; j < obj1.c.size() * 2 + 10; j++) {
				cout << '-';
			}
			cout << endl;
		}
		else {
			for (int i = 0; i < obj1.c.size(); i++) {
				if (obj1.c[i] < obj2.c[i]) {
					for (int j = 0; j < obj2.c.size() * 2 + 10; j++) {
						cout << '-';
					}
					cout << endl;
					VivodSBukvami(obj1, nomer1);
					cout << "  <" << endl;
					VivodSBukvami(obj2, nomer2);
					for (int j = 0; j < obj2.c.size() * 2 + 10; j++) {
						cout << '-';
					}
					cout << endl;
					break;
				}
				if (obj1.c[i] > obj2.c[i]) {
					for (int j = 0; j < obj1.c.size() * 2 + 10; j++) {
						cout << '-';
					}
					cout << endl;
					VivodSBukvami(obj1, nomer1);
					cout << "  >" << endl;
					VivodSBukvami(obj2, nomer2);
					for (int j = 0; j < obj1.c.size() * 2 + 10; j++) {
						cout << '-';
					}
					cout << endl;
					break;
				}
				if (obj1.c[obj1.c.size() - 1] = obj2.c[obj1.c.size() - 1]) {
					for (int j = 0; j < obj1.c.size() * 2 + 10; j++) {
						cout << '-';
					}
					cout << endl;
					VivodSBukvami(obj1, nomer1);
					cout << "  =" << endl;
					VivodSBukvami(obj2, nomer2);
					for (int j = 0; j < obj1.c.size() * 2 + 10; j++) {
						cout << '-';
					}
					cout << endl;
				}
			}
		}
	}

	void DeleteHEX(Hex &obj, vector<string> PATH, int PATHN, int hod) {
		if (obj.todel == 1) {
			obj.c.resize(0);
			obj.todel = 0;
			//obj.hexznak = 1;
			p();
			string path1 = PATH[PATHN];
			string pathdel = path1 + pathn[hod / 10] + pathn[hod % 10] + path3;
			if (remove(pathdel.c_str()) != 0) {
				cout << pathdel << green << " NONE" << white << endl;
			}
			else {
				cout << pathdel << red << " DELETED" << white << endl;
			}
		}
	}
};