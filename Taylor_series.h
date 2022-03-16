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
#include <vector>
#include <cmath>

class Menu;




class TaylorSeries {
protected:
	friend Menu;
	/*enum functions {
		sin = 0,
		cos = 1,
		XinSecond = 2
	};*/

	vector<double> coefficients;
	int Sin = 0;
	int Cos = 0;
	int XinSecond = 0;

	/*void toSolveFunctionsSinElement(int index) {
		this->coefficients;
		this->Sin;
		Sin = sin(coefficients[index]);
	}*/
	
	void toSolveFunctionsCosElement(int index) {
		this->coefficients;
		this->Cos;
		Cos = cos(coefficients[index]);
	}

	/*void toSolveFunctionsSinElement(int index) {
		this->coefficients;
		this->XinSecond;
		XinSecond = pow(coefficients[index], 2) * (coefficients[index] ;
	}*/
	
	long long Fact(double x) {
		if (x < 0) return 0;
		if (x == 1 || x == 0) return 1;
		return x * Fact(x - 1);
	}

	void toSolveFunctionsSinElement(double x, double eps, int N, int i) {
		double etalon = sin(x), error;
		int count = 0;
		double res = 0;
		for (i = 1; i <= N; i++) {
			res += pow(-1, i + 1) * pow(x, 2 * i - 1) / (long double)Fact(2 * i - 1);
			if (fabs(etalon - res) < eps) break;
		}
		error = fabs(etalon - res);
		count = i - 1;
		cout << etalon << endl << res << endl << error << endl << count << endl;
	}


}; 
