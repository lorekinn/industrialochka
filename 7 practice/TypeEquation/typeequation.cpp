#include "typeequation.h"
#include <iostream>
using namespace std;

void Type1Equation::Get_answer() {
    cout << "Уравнение имеет множество решений" << endl;
}
void Type1Equation::show() {
    cout << "0 = 0" << endl;
}

Type2Equation::Type2Equation(double a1) {
    A = a1;
}
void Type2Equation::Get_answer() {
    cout << "Уравнение имеет единственное решение x = 0" << endl;
}
void Type2Equation::show() {
    cout << A << "x^2 = 0" << endl;
}
