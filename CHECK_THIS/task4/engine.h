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

	////////////////////////////////////////////////
	// menu1
	////////////////////////////////////////////////
	void DeleteAll(string path) {
		fstream ifile(path, ios_base::out);
		s.clear();
		cout
			<< red
			<< "===============" << endl
			<< "[ ALL DELETED ]" << endl
			<< "===============" << endl
			<< white << endl;
	}

	////////////////////////////////////////////////
	// menu3
	////////////////////////////////////////////////
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
	void VivodByNumber(vector<int> temp) {
		for (int i = 0; i < temp.size(); i++) {
			cout
				<< yellow << "----------------------------" << endl
				<< "Date: " << s[temp[i]].date.day << "." << s[temp[i]].date.month << "." << s[temp[i]].date.year << white << endl
				<< yellow << "Time: " << white << s[temp[i]].time.hours << ":" << s[temp[i]].time.min << ":" << s[temp[i]].time.sec << endl
				<< yellow << "Steps: " << white << s[temp[i]].shagi << endl
				<< yellow << "GIGIZASHAGI: " << white << s[temp[i]].GIGIZASHAGI << endl
				<< yellow << "----------------------------" << white << endl;
		}
	}
	void VivodBestSteps(int bestSteps, int bestStepsNumber) {
		cout
			<< yellow
			<< "   [ YOUR RECORD: " << bestSteps << " ]" << endl
			<< yellow << "----------------------------" << endl
			<< "Date: " << white << s[bestStepsNumber].date.day << "." << s[bestStepsNumber].date.month << "." << s[bestStepsNumber].date.year << endl
			<< yellow << "Time: " << white << s[bestStepsNumber].time.hours << ":" << s[bestStepsNumber].time.min << ":" << s[bestStepsNumber].time.sec << endl
			<< yellow << "GIGIZASHAGI: " << white << s[bestStepsNumber].GIGIZASHAGI << endl
			<< yellow << "----------------------------" << white << endl;
	}

	////////////////////////////////////////////////
	// menu2
	////////////////////////////////////////////////
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
		cout << yellow << "Steps: " << white << endl << "	";
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
			for (int i = 0; i < s.size(); i++) {
				outfile
					<< s[i].date.day << "." << s[i].date.month << "." << s[i].date.year << "/"
					<< s[i].time.hours << ":" << s[i].time.min << ":" << s[i].time.sec << "/"
					<< s[i].shagi << "/"
					<< s[i].len << "/"
					<< s[i].GIGIZASHAGI
					<< endl;
			}
		}
		outfile.close();
	}

	////////////////////////////////////////////////
	// menu4
	////////////////////////////////////////////////
	void FindStepsBy() {
		cout
			<< blue << "How you want to do it?" << white << endl
			<< "1 - by date" << endl
			<< "2 - by best steps in month" << endl
			<< "3 - by best steps of all time" << endl
			<< "4 - by date's interval" << endl
			<< "5 - the mean of month" << endl
			<< "6 - the mean of all time" << endl;
		int choose = 0;
		while (choose < 1 || choose > 6) {
			cin >> choose;
		}
		system("cls");
		if (choose == 1) { FindStepsByDate(); }
		if (choose == 2) { FindStepsByBestStepsInMonth(); }
		if (choose == 3) { FindStepsByBestSteps(); }
		if (choose == 4) { FindStepsByDateInterval(); }
		if (choose == 5) { FindStepsByMeanStepsInMonth(); }
		if (choose == 6) { FindStepsByMeanStepsOfAll(); }
	}
	void FindStepsByDate() {
		Date date;
		cout << yellow << "Date: " << white << endl;
		cout << "	day: ";
		cin >> date.day;
		cout << "	month: ";
		cin >> date.month;
		cout << "	year: ";
		cin >> date.year;
		vector<int> temp;
		for (int i = 0; i < s.size(); i++) {
			if (date.day == s[i].date.day && date.month == s[i].date.month && date.year == s[i].date.year) { temp.push_back(i); }
		}
		VivodByNumber(temp);
	}
	void FindStepsByBestStepsInMonth() {
		cout << yellow << "Enter the month:" << white << endl;
		int month = 0;
		int bestSteps = 0, bestStepsN = 0;
		while (month < 1 || month > 12) {
			cin >> month;
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i].shagi > bestSteps && s[i].date.month == month) { bestSteps = s[i].shagi; bestStepsN = i; }
		}
		VivodBestSteps(bestSteps, bestStepsN);
	}
	void FindStepsByBestSteps() {
		int bestSteps = 0, bestStepsN = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i].shagi > bestSteps) { bestSteps = s[i].shagi; bestStepsN = i; }
		}
		VivodBestSteps(bestSteps, bestStepsN);
	}
	void FindStepsByDateInterval() {
		Date date1, date2;
		cout << yellow << "Begin of date's interval: " << white << endl;
		cout << "	day: ";
		cin >> date1.day;
		cout << "	month: ";
		cin >> date1.month;
		cout << "	year: ";
		cin >> date1.year;
		cout << yellow << "End of date's interval: " << white << endl;
		cout << "	day: ";
		cin >> date2.day;
		cout << "	month: ";
		cin >> date2.month;
		cout << "	year: ";
		cin >> date2.year;
		vector<int> temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i].date.year == date1.year || s[i].date.year == date2.year) {
				if (s[i].date.month == date1.month || s[i].date.month == date2.month) {
					if (s[i].date.day >= date1.day && s[i].date.day <= date2.day){ temp.push_back(i); }
				}
				else if(s[i].date.month > date1.month && s[i].date.month < date2.month) { temp.push_back(i); }
			}
			else if(s[i].date.year > date1.year && s[i].date.year < date2.year) { temp.push_back(i); }
		}
		system("cls");
		cout
			<< yellow
			<< "[ " << date1.day << "." << date1.month << "." << date1.year
			<< "  -->  "
			 << date2.day << "." << date2.month << "." << date2.year << " ]"
			<< white << endl;
		VivodByNumber(temp);
	}
	void FindStepsByMeanStepsInMonth() {
		cout << yellow << "Enter the month:" << white << endl;
		int month = 0;
		int meanValue = 0;
		int r = 0;
		while (month < 1 || month > 12) {
			cin >> month;
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i].date.month == month) {
				meanValue += s[i].shagi;
				r++;
			}
		}
		meanValue /= r;
		system("cls");
		cout << yellow << "[  MEAN VALUE(of month number:" << month << "): " << meanValue << "  ]" << white << endl;
	}
	void FindStepsByMeanStepsOfAll() {
		int meanValue = 0;
		int r = 0;
		for (int i = 0; i < s.size(); i++) {
			meanValue += s[i].shagi;
			r++;
		}
		meanValue /= r;
		cout << yellow << "[  MEAN VALUE(of all time): " << meanValue << "  ]" << white << endl;
	}

	////////////////////////////////////////////////
	// menu5
	////////////////////////////////////////////////
	void BeginningOfEnteries() {
		Date date;
		Time time;
		int numberBegining = 0;
		date.day = 31, date.month = 12, date.year = 3000;
		for (int i = 0; i < s.size(); i++) {
			if (s[i].date.year == date.year) {
				if (s[i].date.month == date.month) {
					if (s[i].date.day == date.day) {
						if (s[i].time.hours == time.hours) {
							if (s[i].time.min == time.min) {
								if (s[i].time.sec <= time.sec) {
									SaveDateAndTime(date, s[i].date, time, s[i].time);
								}
							}
							else if (s[i].time.min < time.min) { SaveDateAndTime(date, s[i].date, time, s[i].time); }
						}
						else if (s[i].time.hours < time.hours) { SaveDateAndTime(date, s[i].date, time, s[i].time); }
					}
					else if (s[i].date.day < date.day) { SaveDateAndTime(date, s[i].date, time, s[i].time); }
				}
				else if (s[i].date.month < date.month) { SaveDateAndTime(date, s[i].date, time, s[i].time); }
			}
			else if (s[i].date.year < date.year) { SaveDateAndTime(date, s[i].date, time, s[i].time); }
		}
		cout
			<< yellow << "Begining of entries: " << endl
			<< "Date: " << white
			<< date.day << "." << date.month << "." << date.year << endl
			<< yellow
			<< "Time: " << white
			<< time.hours << ":" << time.min << ":" << time.sec << endl;
	}
	void SaveDateAndTime(Date &date, Date d, Time &time, Time t) {
		date.day = d.day;
		date.month = d.month;
		date.year = d.year;
		time.hours = t.hours;
		time.min = t.min;
		time.sec = t.sec;
	}
};