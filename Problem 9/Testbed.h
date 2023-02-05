#ifndef TESTBED_H
#define TESTBED_H

#include <string>
#include "Sorter.h"

using std::string;
class Testbed {
public:
    Testbed();
    int* Generate_Random_List(int min, int max, int size);
    int* Generate_Reverse_Ordered_List(int min, int max, int size);
    double Run_Once(Sorter* sorter, int* data, int size);
    double Run_And_Average(Sorter* sorter, string type, int min, int max, int size, int sets_num);
    void Run_Experiment(Sorter* sorter, string type, int min, int max, int min_val, int max_val, int sets_num, int step);
};

#endif // TESTBED_H