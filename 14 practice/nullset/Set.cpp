#include "Set.h"
#include <stdexcept>

bool Set::contains(int element) const {
    if (set.empty()) {
        throw std::runtime_error("Set is empty");
    }
    return set.find(element) != set.end();
}

void Set::insert(int element) {
    set.insert(element);
}

void Set::remove(int element) {
    set.erase(element);
}
