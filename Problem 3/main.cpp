#include "MatrixCalculator.cpp"
#include "Matrix.h"
using namespace std;
int main()
{
    MatrixCalculator<int> menu;
    Matrix <int> matrix;
    menu.PrintObject(matrix);
    return 0;
}
