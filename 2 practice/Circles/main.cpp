#include <iostream>
#include "circle.h"
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float x, y, r;
	circle arr[3];
	for (int i = 0; i < 3; i++) {
		cout << "Введите х, у и радиус " << i << "-й окружности: " << endl;
		cin >> x >> y >> r;
		arr[i].set_circle(r, x, y);
	}
	for (int i = 0; i < 3; i++) {
		cout << "Площадь " << i + 1 << "-й окружности: " << endl;
		cout << arr[i].square() << endl;
		cout << "Можно ли вписать в " << i + 1 << "-ю окружность треугольник с длинами сторон 3, 4, 5?" << endl;
		cout << (arr[i].triangle_in(3, 4, 5) ? "Да" : "Нет") << endl;
		cout << "Можно ли описать около " << i + 1 << "-й окружности треугольник с длинами сторон 5, 12, 13?" << endl;
		cout << (arr[i].triangle_around(5, 12, 13) ? "Да" : "Нет") << endl;
		cout << "Пересекается ли " << i + 1 << "-я окржность с  другой (4, 1, 3)?" << endl;
		cout << (arr[i].check_circle(4, 1, 3) ? "Да" : "Нет") << endl;
	}
}
