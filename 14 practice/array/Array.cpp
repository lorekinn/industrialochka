#include "Array.h"
#include <stdexcept>

Array::Array(int size) : size(size) {
    array = new int[size];
}

int Array::getSize() const {
    return size;
}

int Array::getElement(int index) const {
    if (index < 0 || index >= size) {
        throw std::runtime_error("Invalid index");
    }
    return array[index];
}

void Array::setElement(int index, int value) {
    if (index < 0 || index >= size) {
        throw std::runtime_error("Invalid index");
    }
    array[index] = value;
}
