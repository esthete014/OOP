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

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include "Menu.h"
#include "Color.h"
#pragma warning(suppress : 4996)
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Menu;



class Matrix {

	friend Menu;

protected:
    vector<vector<int> > matrix;
    vector<int> dominante;
    int N = 0;
    int M = 0;
    int maxlenline = 1;
    
	
    vector<char> Cifri = { '0', '1', '2' , '3', '4', '5' , '6' , '7' , '8' , '9' };

    void SostavlenieChisla(string str, Matrix &obj) {
        vector<int> temp;
        int mesto = 0;
        int n = 0;
        temp.push_back(0);
        this->matrix;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                for (int j = 0; j < Cifri.size(); j++) {
                    if (str[i] == Cifri[j]) {
                        if (i == 0) {
                            temp.push_back(0);
                        }
                        temp.at(mesto) = temp[mesto] * 10 + unsigned int(j);
                        if (str[i + 1] == ' ') {
                            temp.push_back(0);
                        }
                    }
                }
            }
            if (str[i] == ' ') {
                mesto++;
                n++;
            }
        }
        obj.M = n;
        obj.matrix.push_back(temp);
    }

    void VivodMatrix(vector<vector<int> > matrix, string pathname, int n, int m) {//don't use(it's works, but VivodMatrixOBJ better)
        this->matrix;
        cout << "------- | " << pathname << " | -------" << endl;
        cout << "___________________________" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    cout << " | ";
                }
                cout << matrix[i][j] << " ";
                if (j == m - 1) {
                    cout << " | ";
                }
            }
            cout << endl;
        }
        cout << "___________________________" << endl;
    }

    void VivodMatrixOBJ(Matrix obj, int matn) {
        cout << "------- | " << yellow << "Matrix" << matn << white << " | -------" << endl;
        cout << "___________________________" << endl;
        for (int i = 0; i < obj.N; i++) {
            for (int j = 0; j < obj.M; j++) {
                if (j == 0) {
                    cout << " | ";
                }
                int v = obj.matrix[i][j];
                cout << v;
                if (j != obj.M - 1) {
                    cout << ' ';
                }
                if (obj.matrix[i][j] < 100) {
                    cout << ' ';
                    if (obj.matrix[i][j] < 10) {
                        cout << ' ';
                    }
                }
                if (j == obj.M - 1) {
                    cout << " | ";
                }
            }
            cout << endl;
        }
        cout << "___________________________" << endl;
    }

    
    //void Createfile(int n, int m) {//don't use(use SozdanieMatrixFile)
    //    ofstream outfile;
    //    outfile.open("D:\\c++/oop/matrix/matrix";);
    //    if (outfile.is_open())
    //    {
    //        for (int i = 0; i < n; i++) {
    //            for (int j = 0; j < m; j++) {
    //                outfile << rand() % 6 << " ";
    //            }
    //            outfile << endl;
    //        }
    //    }
    //    outfile.close();
    //}
    void DeleteMatrixFiles(const char* pathdel, Matrix& obj) {
        for (int i = 0; i < obj.N; i++) {
            for (int j = 0; j < obj.M; j++) {
                obj.matrix[i][j] = 0;
            }
        }
        obj.matrix.clear();
        obj.matrix.resize(0);
        obj.matrix.shrink_to_fit();
        obj.dominante.clear();
        obj.dominante.resize(0);
        obj.matrix.shrink_to_fit();
        obj.N = 0;
        obj.M = 0;
        if (remove(pathdel) != 0) {
            cout << pathdel << green << " NONE" << white << endl;
        }
        else {
            cout << pathdel << red << " DELETED" << white << endl;
        }
    }
    void SozdanieMatrixFile(Matrix &obj, int nomer, int n, int m, vector<string> PATH, int PATHN) {
        string path1 = PATH[PATHN];//"D:\\c++/oop/matrix/matrix";
        string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        string path3 = ".txt";
        string path = path1 + pathn[nomer] + path3;
        ofstream outfile;
        outfile.open(path);
        if (outfile.is_open())
        {
            for (int i = 0; i < n; i++) {
                vector<int> temp;
                for (int j = 0; j < m; j++) {
                    int r = rand() % 10;
                    outfile << r << " ";
                    temp.push_back(r);
                }
                outfile << endl;
                obj.matrix.push_back(temp);
            }
        }
        obj.N = n;
        obj.M = m;
        outfile.close();
    }

    void ZapisVFile(Matrix obj, int nomer, vector<string> PATH, int PATHN) {
        string path1 = PATH[PATHN];//"D:\\c++/oop/matrix/matrix";
        string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        string path3 = ".txt";
        string path = path1 + pathn[nomer] + path3;
        ofstream outfile;
        outfile.open(path);
        if (outfile.is_open())
        {
            for (int i = 0; i < obj.N; i++) {
                for (int j = 0; j < obj.M; j++) {
                    outfile << obj.matrix[i][j] << " ";
                }
                outfile << endl;
            }
        }
        outfile.close();
    }

    void SlojenieMatrix(Matrix obj1, int nomer1, Matrix obj2, int nomer2, Matrix& obj3, int matn, int N, vector<string> PATH, int PATHN) {
        VivodMatrixOBJ(obj1, nomer1);

        for (int i = 0; i < obj1.N; i++) {
            for (int j = 0; j < obj1.M; j++) {
                obj1.matrix[i][j] += obj2.matrix[i][j];
            }
        }
        obj3.matrix = obj1.matrix;
        obj3.N = obj1.N;
        obj3.M = obj1.M;
        
        ZapisVFile(obj3, matn, PATH, PATHN);

        
        cout << "___________________________" << endl;
        cout << "            +" << endl;
        VivodMatrixOBJ(obj2, nomer2);
        cout << "___________________________" << endl;
        cout << "            =" << endl;
        VivodMatrixOBJ(obj3, matn);
    }

    void TransposeMatrix(Matrix& obj, int nomer, vector<string> PATH, int PATHN) {
        vector<vector<int>> mv;
        for (int i = 0; i < obj.M; ++i) {
            vector<int> temp;
            for (int j = 0; j < obj.N; ++j) {
                temp.push_back(0);
            }
            mv.push_back(temp);
        }
        for (int i = 0; i < obj.M; ++i) {
            for (int j = 0; j < obj.N; ++j) {
                mv[i][j] = obj.matrix[j][i];
            }
        }
        obj.matrix = mv;
        int a = obj.N;
        obj.N = obj.M;
        obj.M = a;
        ZapisVFile(obj, nomer, PATH, PATHN);
        cout << yellow << "        Transposed         " << white << endl;
        VivodMatrixOBJ(obj, nomer);
    }

    void MultiplyMatrix(Matrix obj1, int nomer1, Matrix obj2, int nomer2, Matrix& obj3, int matn, vector<string> PATH, int PATHN) {
        for (int i = 0; i < obj1.N; i++) {
            vector<int> temp;
            for (int j = 0; j < obj2.M; j++) {
                temp.push_back(0);
                for (int k = 0; k < obj1.M; k++) {
                    temp[j] += obj1.matrix[i][k] * obj2.matrix[k][j];
                }
            }
            obj3.matrix.push_back(temp);
        }

        obj3.N = obj1.N;
        obj3.M = obj2.M;
        ZapisVFile(obj3, matn, PATH, PATHN);
        Openfile(obj3, matn, obj1.N, obj2.M, PATH, PATHN);
    }

    void DiagonalDominance(Matrix &obj) {
        cout << "Dominant lines: ";
        int f = 1;
        for (int i = 0; i < obj.N; i++) {
            int s = 0;
            for (int j = 0; j < obj.M; j++) {
                if (i != j) {
                    s += obj.matrix[i][j];
                }
            }
            if (obj.matrix[i][i] > s) {
                obj.dominante.push_back(1);
                cout << i + 1;
                f = 0;
            }
            else {
                obj.dominante.push_back(0);
            }
        }
        if (f == 1) {
            cout << "NONE";
        }
        cout << endl;
    }

    void MultiplyMatrixByNumber(Matrix &obj, int number, int matn) {
        for (int i = 0; i < obj.N; i++) {
            for (int j = 0; j < obj.M; j++) {
                obj.matrix[i][j] *= number;
            }
        }
        VivodMatrixOBJ(obj, matn);
    }

    void Openfile(Matrix &obj, int nomer, int n, int m, vector<string> PATH, int PATHN) {
        string line;
        ifstream infile;
        string str;
        string path1 = PATH[PATHN];// "D:\\c++/oop/matrix/matrix";
        string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        string path3 = ".txt";
        string path = path1 + pathn[nomer] + path3;
        infile.open(path);
        if (infile.is_open()) {
            int hod = 0;
            while (getline(infile, line)) {
                obj.SostavlenieChisla(line, obj);
            }
            string mtrname = "Matrix";
            mtrname += pathn[nomer];
            VivodMatrixOBJ(obj, nomer);
        }
        infile.close();
        
    }
};