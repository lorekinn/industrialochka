#define _USE_MATH_DEFINES
#include "circle.h"
#include <cmath>

using namespace std;

circle::circle() {
	radius = 0;
	x = 0;
	y = 0;
}

circle::circle(float r, float x_c, float y_c) {
	radius = r;
	x = x_c;
	y = y_c;
}

void circle::set_circle(float r, float x_c, float y_c) {
	radius = r;
	x = x_c;
	y = y_c;
}

float circle::square() {
	return pow(radius, 2) * M_PI;
}

bool circle::triangle_in(float a, float b, float c) {
	double p = (a + b + c) / 2;
	return bool(radius == a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c))));
}

bool circle::triangle_around(float a, float b, float c) {
	double p = (a + b + c) / 2;
	return bool(radius == sqrt(p * (p - a) * (p - b) * (p - c)) / (a + b + c));
}

bool circle::check_circle(float _r, float _x, float _y) {
	return (sqrt(pow((x - _x), 2) + pow(_y - y, 2)) < radius);
}
