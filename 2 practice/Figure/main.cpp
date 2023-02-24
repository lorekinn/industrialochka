#include "figure.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float x1, x2, x3, x4, y1, y2, y3, y4;
	figure arr[3];
	for (int i = 0; i < 3; i++) {
		cout << "Введите х1-4, y1-4 координаты " << i + 1 << "-го четырехугольника: " << endl;
		cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
		arr[i].set(x1, x2, x3, x4, y1, y2, y3, y4);
		arr[i].show();
	}
}
