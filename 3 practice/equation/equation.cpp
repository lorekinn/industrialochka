#include "equation.h"
#include <cmath>
#include <iostream>

using namespace std;

equation::equation() {
	a = 0;
	b = 0;
	c = 0;
	D = 0;
}

equation::equation(double _a, double _b, double _c) {
	a = _a;
	b = _b;
	c = _c;
	D = b * b - 4 * a * c;
}

void equation::set(double _a, double _b, double _c) {
	a = _a;
	b = _b;
	c = _c;
	D = b * b - 4 * a * c;
}

double equation::find_X() {
	if (D < 0) {
		cout << "Корней нет." << endl;
		return 0;
	}
	if (D == 0) {
		double x = -b / (2 * a);
		cout << "Корень один: " << x << endl;
		return x;
	}
	if (D > 0) {
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		cout << "Корней два, наибольший: " << max(x1, x2) << endl;
		return max(x1, x2);
	}
}

double equation::find_Y(double a1) {
	double s = a1;
	return a * s * s + b * s + c;
}
