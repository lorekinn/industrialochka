#include <iostream>
#include "my_class.h"
using namespace std;

template <class T> void Swap(T& x, T& y) {
    T z = x;
    x = y;
    y = z;
}
template <class T> void OutXY(T& x, T& y) {
    cout << x << " " << y << "\n";
}

int main() {
    setlocale(LC_ALL, "rus");
    int x = 1;
    int y = 2;
    cout << "Перед обменом (целые)\n";
    OutXY(x, y);
    Swap(x, y);
    cout << "После обмена\n";
    OutXY(x, y);
    float x1 = 1.5;
    float y1 = 5.9;
    cout << "Перед обменом (float)\n";
    OutXY(x1, y1);
    Swap(x1, y1);
    cout << "После обмена\n";
    OutXY(x1, y1);
    My_class t1(1, 1.5), t2(2, 9.9);
    cout << "Перед обменом (классы)\n";
    t1.Out();
    t2.Out();
    Swap(t1, t2);
    cout << "После обмена\n";
    t1.Out();
    t2.Out();
}
