#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include "Sorter.h"

class QuickSort : public Sorter {
private:
    int partition(int *arr, int start, int last);
    void Sort(int* arr, int start, int last);

public:
    QuickSort();
    void Sort(int* arr, int size);
};

#endif // QUICKSORTER_H