#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;





class Money
{
	

public:

	int m_rub;
	int m_cent;

	//constructor to create
	Money() {
		m_rub = 0;
		m_cent = 0;
		std::cout << "RUBLES: " << m_rub << std::endl;
		std::cout << "CENTS: " << m_cent << "\n" << std::endl;
	}

	Money(std::string _name, int r, int c) {
		m_rub = r;
		m_cent = c;
		std::cout << "RUBLES: " << m_rub << std::endl;
		std::cout << "CENTS: " << m_cent << "\n" << std::endl;
	};



	//constructor to get
	void toGet()
	{
		int r;
		int c;
		std::cout << "RUBLES: ";
		cin >> r;
		std::cout << "\n" << "CENTS: ";
		cin >> c;
		std::cout << "\n" << std::endl;
		m_rub = r;
		m_cent = c;
	};
	
	//constructor to get cherez scanf
	void vvod(std::string _name){
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
		std::cout << "RUBLES: " << m_rub << "\n" << "CENTS: " << m_cent << std::endl;
	};
	void Print2() {
		std::cout << "Your deposit: " << m_rub << "." << m_cent << std::endl;
	}







	void Work() {

		int vihod = 0;
		std::vector<string> namesofdeposites(0);
		std::vector<int> rubofdeposites(0);
		std::vector<int> centsofdeposites(0);




		while (vihod != 1) {


			int newD = 0;
			std::cout << "do you want to create new deposit?\n (1 - yes)\n"; cin >> newD;
			if (newD == 1) {
				string name;
				std::cout << "write the name of deposit: "; cin >> name;
				int r;
				int c;
				std::cout << "RUBLES: "; cin >> r; cout << std::endl;
				std::cout << "CENTS: "; cin >> c; cout << std::endl;
				Money(name, r, c);
				//add name of deposit to vector
				namesofdeposites.push_back(name);
				rubofdeposites.push_back(r);
				centsofdeposites.push_back(c);
			};



			std::cout
				<< "what do u want to do?\n"
				<< "0 - skip\n"
				<< "1 - to get all deposites's names\n"
				<< "2 - to get all deposites\n"
				<< std::endl;
			int var;
			std::cin >> var;
			if (var == 1) {
				std::cout << "\nall deposites's names:\n" << std::endl;
				for (int i = 0; i < namesofdeposites.size(); i++) {
					std::cout << namesofdeposites[i] << std::endl;
				}
			}if (var == 2) {
				std::cout << "all deposites:\n" << std::endl;
				for (int i = 0; i < namesofdeposites.size(); i++) {
					int a = i + 1;
					std::cout
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
						<< std::endl;
				}
			}
			else {
				continue;
			}




			std::cout << "do u want to exit?\n(1 - vihod)\n" << std::endl;
			std::cin >> vihod; cout << std::endl;
			if (vihod == 1) {
				cout << "programmed stoped" << std::endl;
				break;
			}
			//end of while for work
		}
		//end of void work
	}
	//end of class Money
};
