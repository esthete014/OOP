#include "CProblem.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void CProblem::sort(sortType type) {
  if (type == bubble) {
    BubbleSort BS;
    BS.sort(massive, size);
  }
  else if (type == counting) {
    CountingSort CS;
    CS.sort(massive, size);
  }
  else if (type == quick) {
    QuickSort QS;
    QS.sort(massive, size);
  }
  else if (type == insertion) {
	Insertion CS;
	CS.sort(massive, size);
  }
}

void CProblem::print() {
  for (int i = 0; i < size; i++) {
    std::cout << massive[i] << " ";
  }
}

void readFromFile(int* _masssive) {
	vector<string> PATH;
	int PATHN;
	PATH.push_back("D:\\c++/CLONETWC/sort/file_for_sort");
	PATH.push_back("C:\\Users\\77777\\Desktop\\777\\OOP_2nd_semestr\\steps\\file_for_steps");
	PATH.push_back("file_for_sort.txt");
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
	string line;
	fstream ifile(PATH[PATHN], ios_base::in);
	ifile.open(PATH[PATHN]);
	if (ifile.is_open()) {
		int hod = 0;
		
		while (getline(ifile, line)) {
			int len = 0;
			while (line.size() > len) {
				if (len = 0) {
					_masssive[sizeof(_masssive) / sizeof(_masssive[0]) + 1] = 0;
				}
				_masssive[hod] *= 10;
				_masssive[hod] += int(line[len]) - 48;
				len++;
			}
		}
	}
	ifile.close();
}

sortType chooseProblem() {
	cout
		<< "Choose which sort do you want to use:" << endl
		<< "1) bubble" << endl
		<< "2) counting" << endl
		<< "3) quick" << endl
		<< "4) insertion" << endl;
	sortType var = bubble;
	int temp = 0;
	while (var < 1 && var > 4) {
		cin >> temp;
	}
	var = sortType(temp);
	return var;
}
