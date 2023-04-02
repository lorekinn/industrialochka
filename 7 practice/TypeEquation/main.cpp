#include "typeequation.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    Type1Equation eq1;
    eq1.show();
    eq1.Get_answer();

    Type2Equation eq2(3.2);
    eq2.show();
    eq2.Get_answer();
}
