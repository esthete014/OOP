// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || Copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /

#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "Menu.h"
#include "steps.h"
#include "color.h"
class Menu;
class steps;

struct lenTime
{
	int hours = 0, min = 0, sec = 0;
};

class engine {
	friend Menu;
	friend steps;
protected:
	vector<string> PATH;
	int PATHN;
	vector<Steps> s;


	void ChooseFilePath() {
		PATH.push_back("D:\\c++/oop/steps/file_for_steps");
		PATH.push_back("C:\\Users\\77777\\Desktop\\777\\OOP_2nd_semestr\\steps\\file_for_steps");
		PATH.push_back("file_for_steps.txt");
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
		if (c == 0) {
			cout
				<< "1 - to enter path"
				<< endl
				<< "2 - to enter file's name"
				<< endl;
			int a;
			cin >> a;
			string p;
			cin >> p;
			if (a == 2) {
				p += ".txt";
			}
			PATH.push_back(p);
			PATHN = PATH.size() - 1;
		}
		else {
			PATHN = c - 1;
		}
	}


	void CheckOldFile(string path) {
		string line;
		fstream ifile(path, ios_base::in);
		ifile.open(path);
		if (!ifile.is_open()) {
			fstream ifile(path, ios_base::out);
		}
		ifile.close();
		ifile.open(path);
		if (ifile.is_open()) {
			int hod = 0;
			
			while (getline(ifile, line)) {
				s.push_back(Steps(line));
			}
			for (int i = 0; i < s.size(); i++) {
				VivodSteps(i);
			}
		}
		ifile.close();
	}

	void DeleteAll(string path) {
		fstream ifile(path, ios_base::out);
	}

	void VivodAll(string path) {
		for (int i = 0; i < s.size(); i++) {
			VivodSteps(i);
		}
	}
	
	void VivodSteps(int nomer) {
		cout
			<< yellow << "----------------------------" << endl
			<< "Date: " << white << s[nomer].date.day << "." << s[nomer].date.month << "." << s[nomer].date.year << endl
			<< yellow << "Time: " << white << s[nomer].time.hours << ":" << s[nomer].time.min << ":" << s[nomer].time.sec << endl
			<< yellow << "Steps: " << white << s[nomer].shagi << endl
			<< yellow << "GIGIZASHAGI: " << white << s[nomer].GIGIZASHAGI << endl
			<< yellow << "----------------------------" << white << endl;
	}

	void VvodSteps(string path) {
		s.push_back(Steps());
		lenTime lentime;
		cout << yellow << "Date: " << white << endl;
		cout << "	day: ";
		cin >> s[s.size() - 1].date.day;
		cout << "	month: ";
		cin >> s[s.size() - 1].date.month;
		cout << "	year: ";
		cin >> s[s.size() - 1].date.year;
		cout << yellow << "Time: " << white << endl;
		cout << "	hours: ";
		cin >> s[s.size() - 1].time.hours;
		cout << "	minutes: ";
		cin >> s[s.size() - 1].time.min;
		cout << "	seconds: ";
		cin >> s[s.size() - 1].time.sec;
		cout << yellow << "Steps: " << white << endl;
		cin >> s[s.size() - 1].shagi;
		cout << yellow << "Time's lenth: " << white << endl;
		cout << "	hours: ";
		cin >> lentime.hours;
		cout << "	minutes: ";
		cin >> lentime.min;
		cout << "	seconds: ";
		cin >> lentime.sec;
		s[s.size() - 1].len = lentime.hours * 360 + lentime.min * 60 + lentime.sec;
		s[s.size() - 1].GIGIZASHAGI = s[s.size() - 1].shagi + 10;
		SaveToFile(path);
	}
	
	void SaveToFile(string path) {
		ofstream outfile;
		outfile.open(path);
		if (outfile.is_open()) {
			outfile
				<< s[s.size() - 1].date.day << "." << s[s.size() - 1].date.month << "." << s[s.size() - 1].date.year << "/"
				<< s[s.size() - 1].time.hours << ":" << s[s.size() - 1].time.min << ":" << s[s.size() - 1].time.sec << "/"
				<< s[s.size() - 1].shagi << "/"
				<< s[s.size() - 1].len << "/"
				<< s[s.size() - 1].GIGIZASHAGI;
		}
		outfile.close();
	}
};