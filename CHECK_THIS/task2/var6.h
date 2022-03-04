#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include "Menu.h"
#pragma warning(suppress : 4996)
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Menu;



class Matrix {

	friend Menu;

protected:
    vector<vector<int> > matrix;
    vector<vector<int> > mtr1;
    vector<vector<int> > mtr2;
    vector<vector<int> > mtr3;
    int N = 0;
    int M = 0;
    int maxlenline = 1;
    
	/*vector<vector<matrix> > n;
	n.push_back(vector<matrix>());*/
    /*void ZapisMatrix(string line, int hod) {
        int n;
        n = line.size();
        if (maxlenline < n) {
            maxlenline = n;
        }
        vector<int> temp;
        temp.push_back(0);
        for (int i = 0; i <= hod; i++) {
            int mesto = 0;
            if (i == hod) {
                for (int j = 0; j < n; j++) {
                    if (j + 1 != n) {
                        if (line[j] != ' ') {
                            temp[mesto] = (temp[mesto] * 10) + SopostavlenieStrInt(line, j);
                        }
                        if (line[j] == ' ') {
                            mesto++;
                        }
                    }
                }
                matrix.push_back(temp);
            }
        }
        
    }*/
    vector<char> Cifri = { '0', '1', '2' , '3', '4', '5' , '6' , '7' , '8' , '9' };

    void SostavlenieChisla(string str) {
        vector<int> temp;
        int mesto = 0;
        int n = 0;
        temp.push_back(0);
        this->matrix;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                for (int j = 0; j < Cifri.size(); j++) {
                    if (str[i] == Cifri[j]) {
                        if (temp.size() - 1 < mesto) {
                            temp.push_back(0);
                        }
                        temp.at(mesto) = temp[mesto] * 10 + unsigned int(j);
                    }
                }
            }
            if (str[i] != ' ') {
                mesto++;
                n++;
            }
        }
        if (maxlenline < n) {
            maxlenline = n;
        }
        matrix.push_back(temp);
    }
    vector<int> SostavlenieSTRVector(string str1, string str2, int m) {
        vector<int> temp;
        temp.push_back(0);
        for (int i = 0; i < m; i++) {
            if (str1[i] == ' ') {
                temp.push_back(0);
                i++;
            }
            for (int k = 0; k < Cifri.size(); k++) {
                if (str1[i] == Cifri[k]) {
                    int v = temp.back();
                    temp.back() += v + k;
                    break;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (str2[i] == ' ') {
                i++;
            }
            for (int k = 0; k < Cifri.size(); k++) {
                if (str2[i] == Cifri[k]) {
                    int v = temp.back();
                    temp.back() += v + k;
                    break;
                }
            }
        }
        return temp;
        /*int mesto = 0;
        int n = 0;
        vector<int> temp;
        temp.push_back(0);*/
        /*this->matrix;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                for (int j = 0; j < Cifri.size(); j++) {
                    if (str[i] == Cifri[j]) {
                        if (temp.size() < mesto || temp.size() == 0) {
                            temp.push_back(0);
                        }
                        temp[mesto] = (temp.at(mesto) * 10) + j;
                    }
                }
            }
            if (str[i] != ' ') {
                mesto++;
                n++;
            }
        }
        if (maxlenline < n) {
            maxlenline = n;
        }*/
        //int mesto = 0;
        /*for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == ' ') {
                mesto++;
                temp.push_back(0);
            }
            for (int j = 0; j < Cifri.size(); j++) {
                if (str[i] == Cifri[j]) {
                    temp[mesto] = temp[mesto] * 10 + j;
                }
            }
        }
        return temp;*/
    }
    /*vector<int> SostavlenieVectora(vector<int> mtr1, vector<int> mtr2, int hod) {
        mtr1[hod]
    }*/


    void VivodMatrix(vector<vector<int> > matrix, string pathname) {
        this->matrix;
        cout << "------- | " << pathname << " | -------" << endl;
        cout << "___________________________" << endl;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < maxlenline; j++) {
                if (j == 0) {
                    cout << " | ";
                }
                cout << matrix[i][j] << " ";
                if (j == maxlenline - 1) {
                    cout << " | ";
                }
            }
            cout << endl;
        }
        cout << "___________________________" << endl;
    }

    int SopostavlenieStrInt(string line, int mesto) {
        vector<char> Cifri = { '0', '1', '2' , '3', '4', '5' , '6' , '7' , '8' , '9' };
        for (int j = 0; j < Cifri.size(); j++) {
            if (line[mesto] == Cifri[j]) {
                return j;
            }
        }
    };
    
    void Createfile(int n, int m) {//don't use(use SozdanieMatrixFile)
        ofstream outfile;
        outfile.open("D:\\c++/oop/matrix/matrix1.txt");
        if (outfile.is_open())
        {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    outfile << rand() % 6 << " ";
                }
                outfile << endl;
            }
        }
        outfile.close();
    }
    void DeleteMatrixFiles(const char* pathdel) {
        if (remove(pathdel) != 0) {
            cout << pathdel << " NONE" << endl;
        }
        else {
            cout << pathdel << " DELETED" << endl;
        }
    }
    void SozdanieMatrixFile(Matrix obj, int nomer, int n, int m) {
        string path1 = "D:\\c++/oop/matrix/matrix";
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
                    int r = rand() % 6;
                    outfile << r << " ";
                    temp.push_back(r);
                }
                outfile << endl;
                obj.matrix.push_back(temp);
            }
        }
        outfile.close();
    }
    void SlojenieMatrix(Matrix obj1, int nomer1, Matrix obj2, int nomer2, Matrix obj3, int matn) {
        string path1 = "D:\\c++/oop/matrix/matrix";
        string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        string path3 = ".txt";
        string pathm1 = path1 + pathn[nomer1] + path3;
        string pathm2 = path1 + pathn[nomer2] + path3;
        Openfile(obj1, nomer1);
        cout << "            +" << endl;
        Openfile(obj2, nomer2);
        cout << "            =" << endl;
        //process slojeniya
        //vector<vector<int>> mtr1;
        string mtr1;
        mtr1.clear();
        string line;
        ifstream infile1;
        infile1.open(pathm1);
        if (infile1.is_open()) {
            int hod = 0;
            while (getline(infile1, line)) {
                mtr1 += line;
            }
        }
        infile1.close();
        //vector<vector<int>> mtr2;
        string mtr2;
        mtr2.clear();
        ifstream infile2;
        infile2.open(pathm2);
        if (infile2.is_open()) {
            int hod = 0;
            while (getline(infile2, line)) {
                mtr2 += line;
            }
        }
        infile2.close();
        
        
        vector<vector<int>> mtr3;
        /*for (int i = 0; i < obj1.N; i++) {
            vector<int> temp;
            for (int j = 0; j < obj1.M; j++) {
                temp.push_back(0);
            }
            obj3.matrix.push_back(temp);
        }*/
        for (int i = 0; i < obj1.N; i++) {
            /*int em1 = mtr1[i][j];
            int em2 = mtr2[i][j];
            obj3.matrix[i][j] += em1;
            obj3.matrix[i][j] += em2;*/
            mtr3.push_back(SostavlenieSTRVector(mtr1, mtr2, obj1.M));
        }
        string path = path1 + pathn[matn] + path3;
        ofstream outfile;
        outfile.open(path);
        if (outfile.is_open())
        {
            for (int i = 0; i < obj1.N; i++) {
                for (int j = 0; j < obj1.M; j++) {
                    outfile << mtr3[i][j]  << " ";
                }
                outfile << endl;
            }
        }
        outfile.close();
        obj3.matrix = mtr3;
    }
    void Openfile(Matrix obj, int nomer) {
        string line;
        ifstream infile;
        string str;
        //Matrix obj;
        string path1 = "D:\\c++/oop/matrix/matrix";
        string pathn = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        string path3 = ".txt";
        string path = path1 + pathn[nomer] + path3;
        infile.open(path);
        if (infile.is_open()) {
            int hod = 0;
            while (getline(infile, line)) {
                obj.SostavlenieChisla(line);
            }
        }
        infile.close();
        string mtrname = "Matrix";
        mtrname += pathn[nomer];
        obj.VivodMatrix(obj.matrix, mtrname);
    }
};