#include <iostream>
#include "Array.h"

int main() {
    try {
        int size = 5;
        Array arr(size);
        int index = 10;
        int value = arr.getElement(index);
        std::cout << "Value at index " << index << ": " << value << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }
}
