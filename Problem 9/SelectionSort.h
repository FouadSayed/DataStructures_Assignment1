#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

#include "Sorter.h"

class SelectionSort : public Sorter {
public:
    SelectionSort();
    void Sort(int* arr, int size);
};

#endif // SELECTIONSORTER_H
