#include "SelectionSort.h"

#include <algorithm>

using std::swap;

SelectionSort::SelectionSort() {
}

void SelectionSort::Sort(int* arr, int size){
    int min;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

