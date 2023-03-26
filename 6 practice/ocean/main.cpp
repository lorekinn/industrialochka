#include "bay.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	ocean oc;
	cout << "Введите название, расположение, глубину, площадь океана: " << endl;
	cin >> oc;

	string o, sn;
	int g, p, l;
	cout << "Введите название океана, название моря, глубину, площадь, длину береговой линии: " << endl;
	cin >> o >> sn >> g >> p >> l;
	sea s(o, sn, g, p, l);

	bay zal;
	cout << "Введите океан, море, название залива, его протяженность и высоту: " << endl;
	cin >> zal;

	cout << oc;
	cout << s;
	cout << zal;
}
