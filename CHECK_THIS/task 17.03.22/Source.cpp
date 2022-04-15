#include <iostream>
#include <cmath>

//files
#include "Point.h"
#include "Menu.h"
#include "Triangle.h"

/* Задание: дописать пропущенные методы, выделить функции, классы,
заменить часть функций перегрузкой операторов.


ЦЕЛЬ: main() должен стать хорошо читаемой структрутой, чтобы было понятно, что происходит во всей программе (без комментариев),
но при этом помещался бы на одном экране.


! В main() вносить свои изменения структуры программы запрещено. Только заменять действия на аналоги, реализованные в
функциях или с использованием классов. СТРУКТУРА ДОЛЖНА ОСТАТЬСЯ ИСХОДНОЙ.


На гитхабе должно появиться 4 коммита:
0. дописал методы
1. выделил функции
2. выделил классы и применил принципы ООП
3. заменил часть функций операторами
То есть по окончании каждого этапа делайте коммит.


Подсказки:
0. Возможные классы, которые проглядыываются в программе:
- класс МЕНЮ (объединяет функции, относящиеся к меню взаимодействия с пользователем),
- класс ТОЧКА (для хранения координат)
- класс ТРЕУГОЛЬНИК (в конструкторах должны отображаться все способы задания треугольника).


1. Функции:
- различные функции меню (показать меню 1 уровня, показать меню 2 уровня и т.д.),
- функции ввода и проверки корректности данных,
- функции различных действий над треугольником: проверка на существование, подсчёт площади и т.д.
Указание. На этапе создания классов предполагается, что объект класса создаётся не в данной функции, а после неё.
Не лепите ввод данных и конструктор в один метод. Функции ввода данных - функции МЕНЮ, а создание объекта (точки, например) -
функции соответствующего класса.


Пример допустимой реализации:
Через 3 метода:
1) метод ввода значений (метод класса меню) - inputSides
2) метод ввода треугльника (метод класса треугольник) -inputTriangle

Далее используется перечисление - enum Type {bySides, byBaseAndHeight, byPointsCoords};

Triangle tr1;
tr1.inputTriangle(bySides);
void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     Triange temp(side1, side2, side3);    // тут создаётся треугольник с указанными полями
     this = temp;
     break;
   // ...
  }
}

или

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     this->side1 = side1;                  // тут изменяется уже существующий треугольник, заполнение указанными полями
     this->side2 = side2;
     this->side3 = side3;
     break;
   // ...
  }
}
*/

enum Type { bySides, byBaseAndHeight, byPointsCoords };
class Point;


void Menu1(bool &back_flag, int &user_choosen) {
    back_flag = false;
    std::cout << "Ways to define a triangle:" << std::endl
        << "0) exit" << std::endl
        << "1) by three sides," << std::endl
        << "2) by base and height," << std::endl
        << "3) by three points" << std::endl
        << "Input: ";
    std::cin >> user_choosen;
}
void Menu1_1(Type &_inputType, int &AB, int &BC, int &AC) {
    _inputType = bySides;
    while (1) {
        std::cout << "Input 3 side of triangle (between space): ";
        std::cin >> AB >> BC >> AC;
        if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
            std::cout << "Input error: triangle dont exist" << std::endl;
            std::cout << "Try again" << std::endl;
            continue;
        }
        break;
    }
}

void Menu1_2(Type &_inputType, int &AB, int &h) {
    _inputType = byBaseAndHeight;
    std::cout << "Input base of triangle: ";
    std::cin >> AB;
    std::cout << "Input height of triangle: ";
    std::cin >> h;
}

void Menu1_3(Type &_inputType, int* A, int* B, int* C) {
    _inputType = byPointsCoords;
    std::cout << "Input 1st point's coordinates (between space): ";
    std::cin >> A[0] >> A[1];
    std::cout << "Input 2nd point's coordinates (between space): ";
    std::cin >> B[0] >> B[1];
    std::cout << "Input 3rd point's coordinates (between space): ";
    std::cin >> C[0] >> C[1];
}


void Menu2(int &user_choosen) {
    std::cout << "Methods:" << std::endl << "1) get square, " << std::endl
        << "2) get perimeter, " << std::endl
        << "3) get type of triangle," << std::endl
        << "4) compare with another triangle by square," << std::endl
        << "5) back to first menu," << std::endl
        << "0) exit," << std::endl
        << "Input: ";
    std::cin >> user_choosen;
}

void Menu2_1(Type& _inputType, int& AB, int& BC, int& AC, float &S, int &h, float &p, int* A, int* B, int* C) {
    if (_inputType == bySides) {
        if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = (AB + BC + AC) * 0.5;
            S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
            std::cout << "Square of triangle: S = " << S << std::endl;
        }
        else {
            std::cout << "Input error: triangle dont exist" << std::endl;
        }
    }
    else if (_inputType == byBaseAndHeight) {
        // your code
        if (h > 0 || AB > 0) {
            S = (h * AB) / 2;
            std::cout << "Square of triangle: S = " << S << std::endl;
        }
        else {
            std::cout << "Input error: triangle dont exist" << std::endl;
        }
    }
    else if (_inputType == byPointsCoords) {
        // your code
        float(AB) = sqrt(pow(abs(B[0] - A[0]), 2) + pow(abs(B[1] - A[1]), 2));
        float(AC) = sqrt(pow(abs(A[0] - C[0]), 2) + pow(abs(A[1] - C[1]), 2));
        float(BC) = sqrt(pow(abs(B[0] - C[0]), 2) + pow(abs(B[1] - C[1]), 2));
        if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = (AB + BC + AC) * 0.5;
            S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
            std::cout << "Square of triangle: S = " << S << std::endl;
        }
        else {
            std::cout << "Input error: triangle dont exist" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

void Menu2_2(Type& _inputType, int& AB, int& BC, int& AC, float& S, int& h, float& p, int* A, int* B, int* C) {
    if (_inputType == bySides) {
        // your code
        if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = AB + AC + BC;
            std::cout << "Perimeter: " << p << std::endl;
        }
        else {
            std::cout << "Input error: triangle dont exist" << std::endl;
        }
    }
    else if (_inputType == byBaseAndHeight) {
        if (h > 0 || AB > 0) {
            p = AB + (sqrt(pow(AB / 2, 2) + pow(h, 2)) * 2);
            std::cout << "Perimeter: " << p << std::endl;
        }
        else {
            std::cout << "Input error: we couldn't find perimeter by your parameters" << std::endl;
        }
    }
    else if (_inputType == byPointsCoords) {
        // your code
        float(AB) = sqrt(pow(abs(B[0] - A[0]), 2) + pow(abs(B[1] - A[1]), 2));
        float(AC) = sqrt(pow(abs(A[0] - C[0]), 2) + pow(abs(A[1] - C[1]), 2));
        float(BC) = sqrt(pow(abs(B[0] - C[0]), 2) + pow(abs(B[1] - C[1]), 2));
        if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = AB + AC + BC;
            std::cout << "Perimeter: " << p << std::endl;
        }
        else {
            std::cout << "Input error: triangle dont exist" << std::endl;
        }
    }
}

void Menu2_3(Type& _inputType, int& AB, int& BC, int& AC, float& S, int& h, float& p, int* A, int* B, int* C) {
    if (_inputType == bySides) {
        // your code
        if (AB == AC || AB == BC || AC == BC) {
            if (AB == AC && AB == BC && AC == BC) {
                std::cout << "Type(by sides): equilateral" << std::endl;
            }
            else if (AB == AC) {
                std::cout << "Type(by sides): isosceles" << std::endl;
            }
            else if (AB == BC) {
                std::cout << "Type(by sides): isosceles" << std::endl;
            }
            else if (AC == BC) {
                std::cout << "Type(by sides): isosceles" << std::endl;
            }
        }
        else {
            std::cout << "Type(by sides): scalene" << std::endl;
        }
        if (pow(AB, 2) == pow(BC, 2) + pow(AC, 2)) {
            std::cout << "Type(by corners): right triangle" << std::endl;
        }
        else if (pow(BC, 2) == pow(AB, 2) + pow(AC, 2)) {
            std::cout << "Type(by corners): right triangle" << std::endl;
        }
        else if (pow(AC, 2) == pow(BC, 2) + pow(AB, 2)) {
            std::cout << "Type(by corners): right triangle" << std::endl;
        }
        else {
            std::cout << "Type(by corners): scalene" << std::endl;
        }
    }
    else if (_inputType == byBaseAndHeight) {
        // your code
        if (sqrt(pow(AB / 2, 2) + pow(h, 2)) == AB) {
            std::cout << "Type(by sides): equilateral" << std::endl;
        }
        else {
            std::cout << "Type(by sides): isosceles" << std::endl;
        }
    }
    else if (_inputType == byPointsCoords) {
        // your code
        //chtobi normal'no rabotalo, nado float pryam vezde, no s nulyami vvodit' ne udobno
        float(AB);
        float(AC);
        float(BC);
        AB = sqrt(pow(abs(B[0] - A[0]), 2) + pow(abs(B[1] - A[1]), 2));
        AC = sqrt(pow(abs(A[0] - C[0]), 2) + pow(abs(A[1] - C[1]), 2));
        BC = sqrt(pow(abs(B[0] - C[0]), 2) + pow(abs(B[1] - C[1]), 2));
        if (AB == AC || AB == BC || AC == BC) {
            if (AB == AC && AB == BC && AC == BC) {
                std::cout << "Type(by sides): equilateral" << std::endl;
            }
            else {
                std::cout << "Type(by sides): isosceles" << std::endl;
            }
            /*else if (AB == AC) {
                std::cout << "Type(by sides): isosceles" << std::endl;
            }
            else if (AB == BC) {
                std::cout << "Type(by sides): isosceles" << std::endl;
            }
            else if (AC == BC) {
                std::cout << "Type(by sides): isosceles" << std::endl;
            }*/
        }
        //if (AB != AC && AB != BC && AC != BC) {
        else {
            std::cout << "Type(by sides): scalene" << std::endl;
        }
        if (pow(AB, 2) == pow(BC, 2) + pow(AC, 2)) {
            std::cout << "Type(by corners): right triangle" << std::endl;
        }
        else if (pow(BC, 2) == pow(AB, 2) + pow(AC, 2)) {
            std::cout << "Type(by corners): right triangle" << std::endl;
        }
        else if (pow(AC, 2) == pow(BC, 2) + pow(AB, 2)) {
            std::cout << "Type(by corners): right triangle" << std::endl;
        }
        else {
            std::cout << "Type(by corners): scalene" << std::endl;
        }
    }
}

void Menu2_4(Type& _inputType, int &user_choosen, int& AB, int& BC, int& AC, float& S, int& h, float& p, int* A, int* B, int* C) {
    if (_inputType == bySides) {
        if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = (AB + BC + AC) * 0.5;
            S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
            std::cout << "Square of first triangle: S = " << S << std::endl;
        }
    }
    else if (_inputType == byBaseAndHeight) {
        // your code
        if (h > 0 || AB > 0) {
            S = (h * AB) / 2;
            std::cout << "Square of first triangle: S = " << S << std::endl;
        }
    }
    else if (_inputType == byPointsCoords) {
        // your code
        float(AB) = sqrt(pow(abs(B[0] - A[0]), 2) + pow(abs(B[1] - A[1]), 2));
        float(AC) = sqrt(pow(abs(A[0] - C[0]), 2) + pow(abs(A[1] - C[1]), 2));
        float(BC) = sqrt(pow(abs(B[0] - C[0]), 2) + pow(abs(B[1] - C[1]), 2));
        if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = (AB + BC + AC) * 0.5;
            S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
            std::cout << "Square of first triangle: S = " << S << std::endl;
        }
    }
    std::cout << "Ways to define a triangle:" << std::endl
        << "0) exit" << std::endl
        << "1) by three sides," << std::endl
        << "2) by base and height," << std::endl
        << "3) by three points" << std::endl
        << "Input: ";
    std::cin >> user_choosen;
    if (user_choosen == 0) {
        return;
    }
    switch (user_choosen) {
    case 0:
        break;
    case 1:
        _inputType = bySides;
        while (1) {
            std::cout << "Input 3 side of triangle (between space): ";
            std::cin >> AB >> BC >> AC;
            if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
                std::cout << "Input error: triangle dont exist" << std::endl;
                std::cout << "Try again" << std::endl;
                continue;
            }
            p = (AB + BC + AC) * 0.5;
            if (S > sqrt(p * (p - AB) * (p - BC) * (p - AC))) {

            }
            else if (S < sqrt(p * (p - AB) * (p - BC) * (p - AC))) {
                std::cout << "Square of the second triangle is bigger" << std::endl;
            }
            else {
                std::cout << "Squares are equal" << std::endl;
            }
            break;
        }
        break;
    case 2:
        _inputType = byBaseAndHeight;
        std::cout << "Input base of triangle: ";
        std::cin >> AB;
        std::cout << "Input height of triangle: ";
        std::cin >> h;
        if (S > (h * AB) / 2) {
            std::cout << "Square of the first triangle is bigger" << std::endl;
        }
        else if (S < (h * AB) / 2) {
            std::cout << "Square of the second triangle is bigger" << std::endl;
        }
        else {
            std::cout << "Squares are equal" << std::endl;
        }
        break;
    case 3:
        _inputType = byPointsCoords;
        std::cout << "Input 1st point's coordinates (between space): ";
        std::cin >> A[0] >> A[1];
        std::cout << "Input 2nd point's coordinates (between space): ";
        std::cin >> B[0] >> B[1];
        std::cout << "Input 3rd point's coordinates (between space): ";
        std::cin >> C[0] >> C[1];
        float(AB) = sqrt(pow(abs(B[0] - A[0]), 2) + pow(abs(B[1] - A[1]), 2));
        float(AC) = sqrt(pow(abs(A[0] - C[0]), 2) + pow(abs(A[1] - C[1]), 2));
        float(BC) = sqrt(pow(abs(B[0] - C[0]), 2) + pow(abs(B[1] - C[1]), 2));
        if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = (AB + BC + AC) * 0.5;
            if (S > sqrt(p * (p - AB) * (p - BC) * (p - AC))) {
                std::cout << "Square of the first triangle is bigger" << std::endl;
            }
            else if (S = sqrt(p * (p - AB) * (p - BC) * (p - AC))) {
                std::cout << "Squares are equal" << std::endl;
            }
            else {
                std::cout << "Square of the second triangle is bigger" << std::endl;
            }
        }
        break;
        /*default:
            std::cout << "Input error: error in input" << std::endl;*/
    }
}


void Menu3(Type &_inputType, int* A, int* B, int* C, int &AB, int &BC, int &AC, int &h) {
    system("cls");
    std::cout << "Last parameters: ";
    if (_inputType == bySides) {
        std::cout << AB << "x" << BC << "x" << AC << std::endl;
    }
    else if (_inputType == byBaseAndHeight) {
        std::cout << "a = " << AB << ", h = " << h << std::endl;
    }
    else if (_inputType == byPointsCoords) {
        std::cout << "(" << A[0] << ", " << A[1] << ")" << ", ";
        std::cout << "(" << B[0] << ", " << B[1] << ")" << ", ";
        std::cout << "(" << C[0] << ", " << C[1] << ")" << std::endl;
    }
}





int main() {
    int user_choosen;
    int AB, BC, AC;
    int A[2], B[2], C[2];
    int h;
    float p, S;
    bool exit_flag = false, back_flag;

    Type _inputType;

    while (!exit_flag) {
        Menu1(back_flag, user_choosen);
        if (user_choosen == 0) {
            break;
        }

        switch (user_choosen) {
        case 1:
            Menu1_1(_inputType, AB, BC, AC);
            break;
        case 2:
            Menu1_2(_inputType, AB, h);
            break;
        case 3:
            Menu1_3(_inputType, A, B, C);
            break;
        default:
            std::cout << "Input error: error in input" << std::endl;
        }

        while (!back_flag) {
            Menu2(user_choosen);


            switch (user_choosen) {
            case 0:
                exit_flag = true;
                break;
            case 1:
                Menu2_1(_inputType, AB, BC, AC, S, h, p, A, B, C);
                break;
            case 2:
                Menu2_2(_inputType, AB, BC, AC, S, h, p, A, B, C);
                break;
            case 3:
                // your code
                // Types of triangles:
                // equilateral - равносторонний,
                // isosceles - равнобедренный,
                // right triangle - прямоугольный,
                // scalene - произвольный.
                Menu2_3(_inputType, AB, BC, AC, S, h, p, A, B, C);
                break;
            case 4:
                // your code
                Menu2_4(_inputType, user_choosen, AB, BC, AC, S, h, p, A, B, C);
                break;
            case 5:
                back_flag = true;
                break;
            default:
                std::cout << "Input error: error in input" << std::endl;
            }

            if (back_flag || exit_flag) {
                Menu3(_inputType, A, B, C, AB, BC, AC, h);
            }
            break;
        }
    }
    system("cls");
    std::cout << "Goodbay!" << std::endl;
}