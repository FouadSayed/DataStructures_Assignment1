#include "QuickSort.h"

#include <algorithm>

using std::swap;

QuickSort::QuickSort() {
}

int QuickSort::partition(int *arr, int start, int last) {
    int middle = start + (last - start) / 2;
    int pivot = arr[middle];

    swap(arr[middle], arr[start]);

    int i = start + 1, j = last;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot)  { i++; }
        while(i <= j && arr[j] > pivot)   { j--; }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i - 1], arr[start]);
    return i - 1;
}

void QuickSort::Sort(int* arr, int start, int last){
    if (start >= last) {
        return;
    }
    int part = partition(arr, start, last);
    QuickSort::Sort(arr, start, part - 1);
    QuickSort::Sort(arr, part + 1, last);
}

void QuickSort::Sort(int* arr, int size){
    QuickSort::Sort(arr, 0, size - 1);
}

