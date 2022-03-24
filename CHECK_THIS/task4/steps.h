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
#include "engine.h"

class engine;

struct Date
{
	int day = 12, month = 3, year = 2000;
};
struct Time
{
	int hours = 0, min = 0, sec = 0;
};

class Steps {
	friend engine;
protected:
	int shagi = 0, GIGIZASHAGI = 0, len = 0;
	Date date;
	Time time;

	Steps() {

	}

	Steps(string &line) {
		int hod = 0;
		for (int i = 0; i < line.size();) {

			if (hod == 0) {
				date.day = int(line[i] - 48) * 10 + int(line[i + 1] - 48);
				date.month = int(line[i + 3] - 48) * 10 + int(line[i + 4] - 48);
				date.year = int(line[i + 6] - 48) * 10 + int(line[i + 7] - 48);
				i += 9;
			}
			if (hod == 1) {
				time.hours = int(line[i] - 48) * 10 + int(line[i + 1] - 48);
				time.min = int(line[i + 3] - 48) * 10 + int(line[i + 4] - 48);
				time.sec = int(line[i + 6] - 48) * 10 + int(line[i + 7] - 48);
				i += 9;
			}
			if (hod == 2) {
				int mesto = i;
				while (line[i] != char(47)) {
					i++;
				}
				for (int k = mesto; k < i; k++) {
					shagi *= 10;
					shagi += int(line[k]) - 48;
				}
				i += 1;
			}
			if (hod == 3) {
				int mesto = i;
				while (line[i] != char(47)) {
					i++;
				}
				for (int k = mesto; k < i; k++) {
					len *= 10;
					len += int(line[k] - 48);
				}
				i += 1;
			}
			if (hod == 3) {
				int mesto = i;
				while (i < line.size()) {
					i++;
				}
				for (int k = mesto; k < i; k++) {
					GIGIZASHAGI *= 10;
					GIGIZASHAGI += int(line[k] - 48);
				}
			}
			hod += 1;
		}
	}

	
};