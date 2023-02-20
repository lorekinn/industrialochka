#include "triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle(double a1, double b1, double c1) {
	a = a1;
	b = b1;
	c = c1;
}

Triangle::Triangle() {
	a = 0;
	b = 0;
	c = 0;
}

bool Triangle::exst_tr() {
	return ((a + b > c) && (b + c > a) && (a + c > b));
}

void Triangle::set(double a1, double b1, double c1) {
	a = a1;
	b = b1;
	c = c1;
}

void Triangle::show() {
	cout << "1 ńňîđîíŕ: " << a << endl << "2 ńňîđîíŕ: " << b << endl << "3 ńňîđîíŕ: " << c << endl;
}

double Triangle::perimeter() {
	return a + b + c;
}

double Triangle::square() {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
