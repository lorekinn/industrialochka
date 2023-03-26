#include "truncated.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите кол-во конусов: " << endl;
	cin >> n;
	cone* arr = new cone[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите координаты центра, радиус основания и высоту " << i + 1 << "-го конуса: " << endl;
		cin >> arr[i];
		cout << arr[i];
		cout << "Объём: " << arr[i].volume() << endl;
		cout << "Площадь поверхности: " << arr[i].area() << endl;
	}
	cout << "Введите кол-во усечённых конусов: " << endl;
	cin >> n;
	frustum* arr1 = new frustum[n];
	double a, b, c, r, r2, h;
	for (int i = 0; i < n; i++) {
		cout << "Введите координаты центра, радиус основания, радиус верхнего основания и высоту " << i + 1 << "-го усечённого конуса: " << endl;
		cin >> arr1[i];
		cout << arr1[i];
		cout << "Объём: " << arr1[i].volume() << endl;
		cout << "Площадь поверхности: " << arr1[i].area() << endl;
	}
}
