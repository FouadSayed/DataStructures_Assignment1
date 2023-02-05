#include "Testbed.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
Testbed::Testbed() {
}

int* Testbed::Generate_Random_List(int min, int max, int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max + min;
    }
    return arr;
}

int* Testbed::Generate_Reverse_Ordered_List(int min, int max, int size)  {
    int* arr = Generate_Random_List(min, max, size);
        for (int j = 1; j > size; j--) {
            swap(arr[j], arr[j - 1]);
        }
                   return arr;
}

double Testbed::Run_Once(Sorter* sorter, int* data, int size) {
    clock_t t = clock();
    sorter->Sort(data, size);
    t = clock() - t;
    return double (t) / CLOCKS_PER_SEC;
}

double Testbed::Run_And_Average(Sorter* sorter, string type, int min, int max, int size, int sets_num) {
    double sum_time = 0;
    for (int i = 0; i < sets_num; i++) {
        int *arr=new int[size];
        if(type=="random"){
            Generate_Random_List(min, max, size);
        } else if (type=="reverse"){
            Generate_Reverse_Ordered_List(min, max, size);
        }
        sum_time += Run_Once(sorter, arr, size);
        delete[] arr;
    }
    return sum_time / sets_num;

}

void Testbed::Run_Experiment(Sorter* sorter, string type, int min, int max, int min_val, int max_val, int sets_num, int step) {
    cout << setw(7) << "Set Size" << setw(15) << "Average Time" << endl;
    for (int n = min_val; n <= max_val; n += step) {
        cout << setw(7) << n << setw(15) << Run_And_Average(sorter, type, min, max, n, sets_num) << endl;
    }
}