#include <iostream>
#include <cmath>
#include "type.h"


Type5::Type5(double b1, double c1) {
    B = b1;
    C = c1;
};

void Type5::Get_answer() {
    double x = -C / B;
    std::cout << "x = " << x << std::endl;
};

void Type5::show() {
    std::cout << B << "x + " << C << " = 0" << std::endl;
};

Type6::Type6(double a1, double b1, double c1) {
    A = a1;
    B = b1;
    C = c1;
};

void Type6::Get_answer() {
    double D = B * B - 4 * A * C;
    if (D < 0) {
        std::cout << "No real roots" << std::endl;
    }
    else if (D == 0) {
        double x = -B / (2 * A);
        std::cout << "x = " << x << std::endl;
    }
    else {
        double x1 = (-B + std::sqrt(D)) / (2 * A);
        double x2 = (-B - std::sqrt(D)) / (2 * A);
        std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
    }
};

void Type6::show() {
    std::cout << A << "x^2 + " << B << "x + " << C << " = 0" << std::endl;
};
