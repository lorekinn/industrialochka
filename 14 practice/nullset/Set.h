#ifndef SET_H
#define SET_H

#include <set>

class Set {
public:
    bool contains(int element) const;

    void insert(int element);

    void remove(int element);

private:
    std::set<int> set;
};

#endif
