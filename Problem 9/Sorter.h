
#ifndef SORTER_H
#define SORTER_H

class Sorter {
public:
    Sorter();
    virtual void Sort(int* arr, int size) = 0;
};

#endif // SORTER_H