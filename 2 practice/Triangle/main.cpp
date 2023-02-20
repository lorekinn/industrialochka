#include <iostream>
#include "triangle.h"
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Triangle arr[3];
	double a, b, c;
	for (int i = 0; i < 3; i++) {
		cout << "Введите 3 стороны для " << i + 1 << "-го треугольника:" << endl;
		cin >> a >> b >> c;
		arr[i].set(a, b, c);
		if (!arr[i].exst_tr()) {
			cout << "Треугольник с такими сторонами не существует, попробуйте снова" << endl;
			i--;
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << "Площадь " << i + 1 << "-го треугольника: " << arr[i].square() << endl;
		cout << "Периметр " << i + 1 << "-го треугольника: " << arr[i].perimeter() << endl;
	}
}
