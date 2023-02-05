#include <iostream>
#include "Testbed.h"
#include "SelectionSort.h"
#include "QuickSort.h"
using std::cout;
using std::endl;
void printArray(int* array, int size) {
    for (int i = 0; i != size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main() {

    SelectionSort obj;
    QuickSort obj1;

    cout << "Selection Sort: ";
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    obj.Sort(arr, 10);
    printArray(arr, 10);

    cout << "Quick Sort: ";
    int arra[10] = {9, -3, 7, 6, 5, 4, 3, 2, 1, 0};
    obj1.Sort(arra, 10);
    printArray(arra, 10);

    cout << endl;

    Testbed tester;

    cout << "Selection Sorter(Random Case):" << endl;
    tester.Run_Experiment(&obj, "random", 1, 1000000, 1000, 10000, 100, 1000);

    cout << endl;

    cout << "Selection Sorter(Reversed Case):" << endl;
    tester.Run_Experiment(&obj, "reverse", 1, 1000000, 1000, 10000, 100, 1000);

    cout << endl;

    cout << "Quick Sorter(Random Case):" << endl;
    tester.Run_Experiment(&obj1, "random", 1, 1000000, 1000, 10000, 100, 1000);

    cout << endl;

    cout << "Quick Sorter(Reversed Case):" << endl;
    tester.Run_Experiment(&obj1, "reverse", 1, 1000000, 1000, 10000, 100, 1000);

    return 0;
}
