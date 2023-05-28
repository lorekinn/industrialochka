#include "mathe.h"
#include <stdexcept>

float Division(float num, float den) {
	if (den == 0) {
		throw std::runtime_error("Math error");
	}
	return (num / den);
}
