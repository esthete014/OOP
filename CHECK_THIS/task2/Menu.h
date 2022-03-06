#pragma once

//biblioteki
#include <iostream>
#include <fstream>
#include <string>
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
				NachaloCreateNewNumber(user, users);
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

	//FUNCTIONS for Hex
	void NachaloCreateNewNumber(int user, Hex users[]) {
		user++;
		users[user];
		string str;
		cout << "write hex number: " << endl;
		cin >> str;
		users[user].SostavlenieChisla(str);
		users[user].Vivod(users[user].c);
	}
	/*void operator != (const Hex& users) {
		bool da;
		if ()
	}*/

	void menu2() {
		Matrix matrixs[10];
		int matn = 0;
		int crtmatr = 0;
		int pvihod = 0;
		//cout << "File 'matrix" << strpath << "' created!" << endl;

		while (true) {
			cout << "You chose matrix variant!" << endl;
			cout << "0 - to exit" << endl;
			cout << "1 - to delete old matrix's files?" << endl;
			cout << "2 - to create matrix with file?" << endl;
			cout << "3 - to check all matrix" << endl;
			cout << "4 - to multiply" << endl;
			int deystviye = 0;
			cin >> deystviye;
			if (deystviye == 1) {
				for (int i = 0; i < 10; i++) {
					string path1 = "D:\\c++/oop/matrix/matrix";
					string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
					string path3 = ".txt";
					string path = path1 + pathn[i] + path3;
					matrixs[matn].DeleteMatrixFiles(path.c_str());
					matrixs[i].N = 0;
					matrixs[i].M = 0;
				}
				matn = 0;
			}
			if (deystviye == 2) {
				int n = 0, m = 0;
				cout << "Write N for matrix:" << endl;
				cin >> n;
				cout << "Write M for matrix:" << endl;
				cin >> m;
				matrixs[matn].SozdanieMatrixFile(matrixs[matn], matn, n, m);
				matrixs[matn].Openfile(matrixs[matn], matn);
				matrixs[matn].N = n;
				matrixs[matn].M = m;
				matn++;
			}

			if (deystviye == 3) {
				cout << "\n---------------------------" << endl;
				cout << "|||||||||||||||||||||||||||" << endl;
				for (int i = 0; i < 10; i++) {
					matrixs[i].Openfile(matrixs[i], i);
				}
				cout << "|||||||||||||||||||||||||||" << endl;
				cout << "---------------------------\n" << endl;
			}
			if (deystviye == 4) {
				int mtr1 = 0, mtr2 = 0;
				cout << "Write the first matrix to multiply:" << endl;
				cin >> mtr1;
				cout << "Write the second matrix to multiply:" << endl;
				cin >> mtr2;
				if (matrixs[mtr1].N != 0 && matrixs[mtr2].N != 0 && matrixs[mtr1].M != 0 && matrixs[mtr2].M != 0) {
					if (matrixs[mtr1].N == matrixs[mtr2].N && matrixs[mtr1].M == matrixs[mtr2].M) {
						matrixs[matn].SlojenieMatrix(matrixs[mtr1], mtr1, matrixs[mtr2], mtr2, matrixs[matn + 1], matn, matrixs[mtr1].N);
						matn++;
					}
					else {
						cout << "N and M of matrix doesn't equal" << endl;
					}
				}
				else {
					cout << "ERROR" << endl;
				}
				if (matn == 10) {
					continue;
				}
			}




			if (matn == 10) {
				int limitend = 0;
				cout
					<< "__________________________________________\n"
					<< "[[[[[[[[[[[[  LIMIT EXCEEDED  ]]]]]]]]]]]]\n"
					<< "------------------------------------------\n"
					<< "you can delete all matrix or exit\n"
					<< "1 - to delete and continue\n"
					<< "2 - exit\n"
					<< endl;
				cin >> limitend;
				if (limitend == 1) {
					for (int i = 0; i < 10; i++) {
						string path1 = "D:\\c++/oop/matrix/matrix";
						string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
						string path3 = ".txt";
						string path = path1 + pathn[i] + path3;
						matrixs[matn].DeleteMatrixFiles(path.c_str());
						matrixs[i].N = 0;
						matrixs[i].M = 0;
					}
					matn = 0;
				}
				else {
					break;
				}
			}
			if (deystviye == 0) {
				cout << "programm stoped" << endl;
				break;
			}
		}//end of while true

		

	}//end of menu2
	
};//end of class Menu