#include "rational.h"
#include <iostream>

using namespace std;

int nod(int a, int b) {
	if (a != 0 && b != 0) {
		if (a > b) return nod(a - b, b);
		if (a < b) return nod(a, b - a);
	}
	else return a + b;
}

rational::rational() {
	num = 0;
	den = 1;
}

rational::rational(int a, int b) {
	if (b != 0) {
		num = a / nod(a, b);
		den = b / nod(a, b);
	}
	else {
		cout << "Знаменатель равен нулю." << endl;
		return;
	}
}

void rational::set(int a, int b) {
	if (b != 0) {
		if (a > b) a = a % b;
		num = a / nod(a, b);
		den = b / nod(a, b);
	}
	else {
		cout << "Знаменатель равен нулю." << endl;
		return;
	}
}

int rational::get_num() {
	return num;
}

int rational::get_den() {
	return den;
}

void rational::show() {
	cout << num << "/" << den << endl;
}

rational operator+ (rational& r1, rational& r2) {
	rational res;
	res.set(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
	return res;
}

rational operator- (rational& r1, rational& r2) {
	rational res;
	res.set(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
	return res;
}

rational operator++ (rational& r1, int) {
	int tempn = r1.num++;
	int tempd = r1.den;
	rational res;
	res.set(tempn, tempd);
	return res;
}

bool operator== (rational& r1, rational& r2) {
	return (float(r1.num) / float(r1.den)) == (float(r2.num) / float(r2.den));
}

bool operator> (rational& r1, rational& r2) {
	return (float(r1.num) / float(r1.den)) > (float(r2.num) / float(r2.den));
}

bool operator< (rational& r1, rational& r2) {
	return (float(r1.num) / float(r1.den)) < (float(r2.num) / float(r2.den));
}

rational rational::operator= (rational f2) {
	if (this == &f2) {
		return *this;
	}
	num = f2.num;
	den = f2.den;
	return *this;
}
