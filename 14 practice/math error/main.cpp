#include <iostream>
#include <stdexcept>
#include "mathe.h"

int main() {
	float num, den, result;
	num = 12.5;
	den = 2;
	try {
		result = Division(num, den);
		std::cout << "result: " << result << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}

	num = 12.5;
	den = 0;
	try {
		result = Division(num, den);
		std::cout << "result: " << result << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}


}
