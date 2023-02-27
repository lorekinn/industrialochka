#include "equation.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	equation arr[2];
	double a, b, c, x;
	for (int i = 0; i < 1; i++) {
		cout << "Введите коэффициенты a, b, c для уравнения:" << endl;
		cin >> a >> b >> c;
		arr[i].set(a, b, c);
		cout << "Решение уравнения:" << endl;
		arr[i].find_X();
		cout << "\nВведите X, чтобы вычислить значение квадратного многочлена:" << endl;
		cin >> x;
		cout << "Значение: " << arr[i].find_Y(x) << endl;
	}
}
