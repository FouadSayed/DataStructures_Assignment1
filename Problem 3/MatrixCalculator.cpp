#include "Matrix.h"
#include <iostream>
using namespace std;
template<class T>

class MatrixCalculator
{
    public:
        MatrixCalculator()= default;;
        void PrintObject(Matrix<T>& matrix1){
            cout << "Welcome to your Matrix Calculator"<<endl;
            cout << "----------------------------------------"<<endl;
            Matrix <T>matrix2,matrix3;
            int Choose;
            bool exit=false;
            while(!exit)
                {
        cout<<"1- Perform Matrix Addition\n";
        cout<<"2- Perform Matrix Subtraction\n";
        cout<<"3- Perform Matrix Multiplication\n";
        cout<<"4- Matrix Transpose\n";
        cout<<"Enter 0 to Exit\n";
        cin >> Choose;
        switch(Choose)
        {
        case 0:
            exit=true;
            break;
        case 1:
            cout<<"Enter The First Matrix :\n";
            cin>>matrix1;
            cout<<"Enter The Second Matrix :\n";
            cin>>matrix2;
            if(matrix1.GetNumberOfRows()==matrix2.GetNumberOfRows() && matrix1.GetNumberOfColumns()==matrix2.GetNumberOfColumns()){
                cout <<"\nMatrix 1 + Matrix 2 = "<< matrix1 + matrix2<<endl;
            }
            else    cout<<"\nSorry, NumberOfRows and NumberOfColumns of two matrices are not equal\n";
            break;
        case 2:
            cout<<"Enter The First Matrix :\n";
            cin>>matrix1;
            cout<<"Enter The Second Matrix :\n";
            cin>>matrix2;
            if(matrix1.GetNumberOfRows()==matrix2.GetNumberOfRows() && matrix1.GetNumberOfColumns()==matrix2.GetNumberOfColumns()){
                cout <<"\nMatrix 1 - Matrix 2 = "<< matrix1 - matrix2<<endl;
            }
            else    cout<<"\nSorry, NumberOfRows and NumberOfColumns of two matrices are not equal\n";
            break;
        case 3:
            cout<<"Enter The First Matrix :\n";
            cin>>matrix1;
            cout<<"Enter The Second Matrix :\n";
            cin>>matrix2;
            if(matrix1.GetNumberOfColumns()==matrix2.GetNumberOfRows()){
                cout <<"\nMatrix 1 * Matrix 2 = "<< (matrix1*matrix2);
            }
            else    cout<<"\nSorry, Number of NumberOfColumns of Matrix 1 not equal Number of NumberOfRows of Matrix 2\n";
            break;
        case 4:
            cout<<"Enter The Matrix :\n";
            cin>>matrix1;
            cout << "Transposed Matrix : " << endl;
            cout << Matrix<int>::Transpose(matrix1) << endl ;
            break;
        default:
            continue;
        }
    }


};

};
template class MatrixCalculator<int>;





