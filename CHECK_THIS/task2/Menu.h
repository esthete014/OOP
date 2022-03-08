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

//biblioteki
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)

//files
#include "var5.h"
#include "var6.h"

class Hex;
class Matrix;













class Menu {
	friend Hex;
	friend Matrix;
	vector<string> users;
public:
	

	void menu1() {
		Hex users[100];
		int user = 0;
		users[user];
		int pvihod = 0;
		
		while (true) {
			int newhex = 0;
			cout
				<< "do you want to create new hex?"
				<< "\n"
				<< "(1 - yes)"
				<< endl;
			cin >> newhex;
			if (newhex == 1) {
				users[user].NachaloCreateNewNumber(users[user]);
				user++;
			}

			//for (int i = 0; users[i] != 0; i++) {

			//}












			int d = 0;
			cout
				<< "what do you want to do?"
				<< "\n"
				<< "1 - "
				<< "\n"
				<< "2 - "
				<< "\n"
				<< "3 - "
				<< endl;
			cin >> d;









			cout << "do u want to close programm?\n(1 - vihod)\n" << endl;
			cin >> pvihod; cout << endl;
			if (pvihod == 1) {
				cout << "programm stoped" << endl;
				break;
			}

		}
		

		












		//ofstream out;			// поток для записи
		//out.open("D:\\c++/oop/hex.txt"); // окрываем файл для записи
		//if (out.is_open())
		//{
		//	out << "awwdds" << endl;
		//}
		//cout << "End of program" << endl;
		







		
		

	}//end of menu1

	void menu2() {
		vector<string> PATH;
		PATH.push_back("D:\\c++/oop/matrix/matrix");
		PATH.push_back("C:\\Users\\77777\\Desktop\\777\\OOP_2nd_semestr\\matrix");
		cout << green << "You chose matrix variant!" << white << endl;
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
		Matrix matrixs[10];
		int matn = 0;
		int crtmatr = 0;
		int pvihod = 0;
		int flag = 0;
		for (int i = 0; i < 10; i++) {
			string line;
			ifstream infile;
			string path1 = PATH[PATHN];//"D:\\c++/oop/matrix/matrix";
			string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			string path3 = ".txt";
			string path = path1 + pathn[i] + path3;
			infile.open(path);
			if (infile.is_open()) {
				int hod = 0;
				while (getline(infile, line)) {
					matrixs[i].SostavlenieChisla(line, matrixs[i]);
					matrixs[i].N++;
				}
				matn++;
				string mtrname = "Matrix";
				mtrname += pathn[i];
				matrixs[i].VivodMatrixOBJ(matrixs[i], matn - 1);
			}
			infile.close();
		}
		while (true) {
			int deystviye = 0;
			if (matn < 10) {
				cout << blue << " ______________________ " << endl;
				cout << "|-------[ MENU ]-------|" << endl;
				cout << "0 - to exit" << endl;
				cout << "1 - to delete old matrix's files?" << endl;
				cout << "2 - to create matrix with file?" << endl;
				cout << "3 - to check all matrix" << endl;
				cout << "4 - to addition" << endl;
				cout << "5 - to transpose" << endl;
				cout << "6 - to multiply by matrix" << endl;
				cout << "7 - to check diagonal dominance" << endl;
				cout << "8 - to multiply by number" << white << endl;
				cin >> deystviye;
			}
			else {
				flag = 1;
			}
			if (deystviye == 1) {
				for (int i = 0; i < 10; i++) {
					string path1 = PATH[PATHN];//"D:\\c++/oop/matrix/matrix";
					string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
					string path3 = ".txt";
					string path = path1 + pathn[i] + path3;
					matrixs[i].DeleteMatrixFiles(path.c_str(), matrixs[i]);
				}
				matn = 0;
			}
			if (deystviye == 2) {
				if (matn == 10) {
					flag = 1;
					continue;
				}
				int n = 0, m = 0;
				cout << "Write N for matrix:" << endl;
				cin >> n;
				cout << "Write M for matrix:" << endl;
				cin >> m;
				matrixs[matn].N = n;
				matrixs[matn].M = m;
				matrixs[matn].SozdanieMatrixFile(matrixs[matn], matn, n, m, PATH, PATHN);
				matrixs[matn].Openfile(matrixs[matn], matn, matrixs[matn].N, matrixs[matn].M, PATH, PATHN);
				matn++;
			}

			if (deystviye == 3) {
				cout << yellow << "\n---------------------------" << endl;
				cout << "|||||||||||||||||||||||||||" << white << endl;
				for (int i = 0; i < 10; i++) {
					matrixs[i].Openfile(matrixs[i], i, matrixs[i].N, matrixs[i].M, PATH, PATHN);
				}
				cout << yellow << "|||||||||||||||||||||||||||" << endl;
				cout << "---------------------------\n" << white << endl;
			}
			if (deystviye == 4) {
				if (matn == 10) {
					flag = 1;
					continue;
				}
				int mtr1 = 0, mtr2 = 0;
				cout << "Write the first matrix to addition:" << endl;
				cin >> mtr1;
				cout << "Write the second matrix to addition:" << endl;
				cin >> mtr2;
				if (matrixs[mtr1].N != 0 && matrixs[mtr2].N != 0 && matrixs[mtr1].M != 0 && matrixs[mtr2].M != 0) {
					if (matrixs[mtr1].N == matrixs[mtr2].N && matrixs[mtr1].M == matrixs[mtr2].M) {
						matrixs[matn].SlojenieMatrix(matrixs[mtr1], mtr1, matrixs[mtr2], mtr2, matrixs[matn], matn, matrixs[mtr1].N, PATH, PATHN);
						matn++;
					}
					else {
						cout << red << "N and M of matrix doesn't equal" << white << endl;
					}
				}
				else {
					cout << red << "ERROR" << white << endl;
				}
			}
			if (deystviye == 5) {
				int mtr = -1;
				cout << "Which matrix do you want to transpose: " << endl;
				while (0 > mtr || mtr >= matn) {
					cin >> mtr;
				}
				if (mtr < matn) {
					matrixs[mtr].TransposeMatrix(matrixs[mtr], mtr, PATH, PATHN);
				}
			}
			if (deystviye == 6) {
				if (matn == 10) {
					flag = 1;
					continue;
				}
				int mtr1 = -1, mtr2 = -1;
				cout << "Write the first matrix to multiply:" << endl;
				while (0 > mtr1 || mtr1 >= matn) {
					cin >> mtr1;
				}
				cout << "Write the second matrix to multiply:" << endl;
				while (0 > mtr2 || mtr2 >= matn) {
					cin >> mtr2;
				}
				if (matrixs[mtr1].N != 0 && matrixs[mtr2].N != 0 && matrixs[mtr1].M != 0 && matrixs[mtr2].M != 0) {
					if (matrixs[mtr1].M == matrixs[mtr2].N) {
						matrixs[matn].MultiplyMatrix(matrixs[mtr1], mtr1, matrixs[mtr2], mtr2, matrixs[matn], matn, PATH, PATHN);
						matrixs[matn].N = matrixs[mtr1].N;
						matrixs[matn].M = matrixs[mtr2].M;
						matn++;
					}
					else {
						cout << red << "size of matrixes are invalid" << white << endl;
					}
				}
				else {
					cout << red << "ERROR" << white << endl;
				}
			}
			if (deystviye == 7) {
				int mtr = -1;
				cout << "Which matrix do you want to check for diagonal dominance: " << endl;
				while (0 > mtr || mtr >= matn) {
					cin >> mtr;
				}
				if (matrixs[mtr].N != 0) {
					matrixs[mtr].DiagonalDominance(matrixs[mtr]);
				}
			}
			if (deystviye == 8) {
				int chislo = -1;
				int mtr = -1;
				cout << "Which matrix do you want to multiply by number: " << endl;
				while (0 > mtr || mtr >= matn) {
					cin >> mtr;
				}
				cout << "Write a number: " << endl;
				while (0 > chislo) {
					cin >> chislo;
				}
				matrixs[mtr].MultiplyMatrixByNumber(matrixs[mtr], chislo, mtr);
			}




			if (matn == 10 || flag == 1) {
				int limitend = 0;
				cout
					<< red
					<< "__________________________________________\n"
					<< "[[[[[[[[[[[[  LIMIT EXCEEDED  ]]]]]]]]]]]]\n"
					<< "------------------------------------------\n"
					<< white
					<< "you can delete all matrix or exit\n"
					<< "1 - to delete and continue\n"
					<< "2 - exit\n"
					<< endl;
				cin >> limitend;
				if (limitend == 1) {
					for (int i = 0; i < 10; i++) {
						string path1 = PATH[PATHN];//"D:\\c++/oop/matrix/matrix";
						string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
						string path3 = ".txt";
						string path = path1 + pathn[i] + path3;
						matrixs[i].DeleteMatrixFiles(path.c_str(), matrixs[i]);
					}
					matn = 0;
					flag = 0;
					deystviye = 10;
				}
				else {
					break;
				}
			}
			if (deystviye == 0) {
				cout << red << "programm stoped" << white << endl;
				break;
			}
		}//end of while true
	}//end of menu2
};//end of class Menu