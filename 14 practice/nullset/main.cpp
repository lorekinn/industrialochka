#include <iostream>
#include "Set.h"

int main() {
    try {
        Set mySet;
        int element = 42;
        bool containsElement = mySet.contains(element);
        std::cout << "Contains element " << element << ": " << containsElement << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }
}
