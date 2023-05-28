#ifndef ARRAY_H
#define ARRAY_H

class Array {
public:
    Array(int size);

    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);

private:
    int* array;
    int size;
};

#endif
