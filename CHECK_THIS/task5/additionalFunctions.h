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



class addFunc {
protected:

	virtual void countSymbolsForDepositTable() {

	}

	virtual Date transformLineToDate(std::string line, Date date, int &i) {
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
		return date;
	}
};