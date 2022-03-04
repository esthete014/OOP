#pragma once

#include <vector>
#include <string>

class Menu;

class Hex {
protected:
	friend Menu;

	vector<int> c;


	vector<char> CifriB = { '0', '1', '2' , '3', '4', '5' , '6' , '7' , '8' , '9' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' };
	vector<char> CifriS = { 'a' , 'b' , 'c' , 'd' , 'e' , 'f' };

	void SostavlenieChisla(string str) {
		this->c;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < CifriB.size(); j++) {
				if (str[i] == CifriB[j]) {
					c.push_back(j);
				}
			}
			for (int j = 0; j < CifriS.size(); j++) {
				if (str[i] == CifriS[j]) {
					c.push_back(j + 10);
				}
			}
		}
	}




	void Vivod(vector<int> c) {
		for (int i = 0; i < c.size(); i++) {
			cout << c[i] << " ";
		}
	}
};