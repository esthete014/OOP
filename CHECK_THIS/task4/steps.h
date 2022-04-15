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
	int shagi = 0, GIGIZASHAGI = 0, len = 0;
	Date date;
	Time time;

	Steps() {
	}

	Steps(string &line) {
		int hod = 0;
		for (int i = 0; i < line.size();) {

			if (hod == 0) {
				date.day = int(line[i] - 48);
				if (line[i + 1] >= char(48) && line[i + 1] <= char(57)) {
					i++;
					date.day *= 10;
					date.day += int(line[i] - 48);
					i += 2;
				}
				else { i += 2; }
				date.month = int(line[i] - 48);
				if (line[i + 1] >= char(48) && line[i + 1] <= char(57)) {
					i++;
					date.month *= 10;
					date.month += int(line[i] - 48);
					i += 2;
				}
				else { i += 2; }
				date.year = int(line[i] - 48);
				if (line[i + 1] >= char(48) && line[i + 1] <= char(57)) {
					i++;
					date.year *= 10;
					date.year += int(line[i] - 48);
					i += 2;
				}
				else { i += 2; }
			}
			if (hod == 1) {
				time.hours = int(line[i] - 48);
				if (line[i + 1] >= char(48) && line[i + 1] <= char(57) && line[i] < char(51)) {
					i++;
					if ((time.hours == 2 && line[i] < 4) || (time.hours < 2)) {
						time.hours *= 10;
						time.hours += int(line[i] - 48);
					}
					i += 2;
				}
				else { i += 2; }
				time.min = int(line[i] - 48);
				if (line[i + 1] >= char(48) && line[i + 1] <= char(57) && line[i] < char(54)) {
					i++;
					time.min *= 10;
					time.min += int(line[i] - 48);
					i += 2;
				}
				else { i += 2; }
				time.sec = int(line[i] - 48);
				if (line[i + 1] >= char(48) && line[i + 1] <= char(57) && line[i] < char(54)) {
					i++;
					time.sec *= 10;
					time.sec += int(line[i] - 48);
					i += 2;
				}
				else { i += 2; }
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