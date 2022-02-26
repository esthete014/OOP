// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /




//biblioteki or files
#include "Header.h"






int main() {
	
	std::cout << "programm started))\n" << std::endl;
	vector<string> namesofdeposites;
	vector<int> rubofdeposites;
	vector<int> centsofdeposites;
	
	
	
	Money first;
	

	int vihod = 0;

	while (vihod != 1) {
		

		first.Sozdanie(namesofdeposites, rubofdeposites, centsofdeposites);

		first.VivodDepositov(namesofdeposites, rubofdeposites, centsofdeposites);


		first.ProverkaCalcComp(namesofdeposites, rubofdeposites, centsofdeposites);



		cout << "do u want to exit?\n(1 - vihod)\n" << endl;
		cin >> vihod; cout << endl;
		if (vihod == 1) {
			cout << "programmed stoped" << endl;
			break;
		}
		//end of while for work
	}
	return 0;
}
