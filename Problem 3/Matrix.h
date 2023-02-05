

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H
#include <iostream>
using namespace std;
template <class T>

class Matrix {
private:
    T** MAT1;
    int NumberOfRows{}, NumberOfColumns{};
public:
    // Constructor for creating matrix

    [[maybe_unused]] Matrix(int NumberOfRows, int NumberOfColumns, T ArrayOfData[]);
    // Constructor for creating empty matrix
    Matrix(int NumberOfRows, int NumberOfColumns);
    // Copy Of Constructor
    [[maybe_unused]] Matrix(const Matrix<T>& MAT2);
    // Get number of rows
    int GetNumberOfRows();
    // Get number of columns
    int GetNumberOfColumns();
    // Get Data From user
    friend istream& operator>> (istream& input, Matrix<T>& MAT2){
        cout<<"enter number of Rows: ";
        cin >> MAT2.NumberOfRows ;
        cout<<"\n";
        cout<<"enter number of Columns: ";
        cin>> MAT2.NumberOfColumns;
        cout<<"\n";
        MAT2.MAT1 = new T*[MAT2.NumberOfRows];
        for (int i = 0; i < MAT2.NumberOfRows; i++)
            MAT2.MAT1[i] = new T[MAT2.NumberOfColumns];

        for (int i = 0; i < MAT2.NumberOfRows; i++)
            for (int j = 0; j < MAT2.NumberOfColumns; j++) {
                cout << "enter the data of row[" << i+1 << "] and column [" << j+1 << "]: ";
                input >> MAT2.MAT1[i][j];
                cout<<"\n";
            }
        return input;
    };
    // Print Data to user
    friend ostream& operator<< (ostream& output, const Matrix<T>& MAT2){

        for (int i = 0; i < MAT2.NumberOfRows; i++)
        {
            output << "\n";
            for (int j = 0; j < MAT2.NumberOfColumns; j++)
                output << MAT2.MAT1[i][j] << "  ";
        }
        output << "\n\n";

        return output;
    };
    // TO add two matrices
    Matrix<T>operator+(Matrix<T> &MAT2);
    // To subtract two matrices
    Matrix<T>operator-(Matrix<T> &MAT2);
    // To multiply two matrices
    Matrix<T> operator*(Matrix<T> &MAT2);
    // To get transpose of matrix

    static Matrix<T>& Transpose(Matrix<T>& MAT1);
    // destructor
    ~Matrix();

    Matrix() = default;
};


#endif //UNTITLED_MATRIX_H
