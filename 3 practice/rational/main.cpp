#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество дробей: " << endl;
	cin >> n;
	int a, b;
	rational* arr = new rational[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите числитель и знаменатель для " << i + 1 << " дроби: " << endl;
		cin >> a >> b;
		arr[i].set(a, b);
		arr[i].show();
	}
	cout << "Сумма первой и второй дробей: " << endl;
	(arr[0] + arr[1]).show();
	cout
		<< "Первая дробь > второй: " << (arr[0] > arr[1]) << endl
		<< "Первая дробь < второй: " << (arr[0] < arr[1]) << endl
		<< "Первая дробь == второй: " << (arr[0] == arr[1]) << endl
		<< "Первая дробь + 1/" << arr[0].get_den() << ": ";
	arr[0]++;
	arr[0].show();
	
	cout << "После присваивания первой дроби к второй, первая стала: " << endl;
	arr[0] = arr[1];
	arr[0].show();
	delete[] arr;
}
