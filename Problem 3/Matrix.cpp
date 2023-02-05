
#include "Matrix.h"


using namespace std;


// Constructor for creating matrix
template <class T>
[[maybe_unused]] Matrix<T>::Matrix(int NumberOfRows, int NumberOfColumns, T ArrayOfData[])
{
    this->NumberOfRows = NumberOfRows;
    this->NumberOfColumns = NumberOfColumns;
    MAT1 = new T*[NumberOfRows];
    for (int i = 0; i < NumberOfRows; i++){
        MAT1[i] = new T[NumberOfColumns];
    }
    for (int i = 0; i < NumberOfRows; i++)
        for (int j = 0; j < NumberOfColumns; j++)
            MAT1[i][j] = ArrayOfData[i * NumberOfColumns + j];
}
// Constructor for creating empty matrix
template <class T>
Matrix<T>::Matrix(int NumberOfRows, int NumberOfColumns)
{
    this->NumberOfRows = NumberOfRows;
    this->NumberOfColumns = NumberOfColumns;
    MAT1 = new T*[NumberOfRows];
    for (int i = 0; i < NumberOfRows; i++)
        MAT1[i] = new T[NumberOfColumns];
}

// Get number of rows
template <class T>
int Matrix<T>::GetNumberOfRows()
{
    return NumberOfRows;
}

// Get number of columns
template <class T>
int Matrix<T>::GetNumberOfColumns()
{
    return NumberOfColumns;
}



template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &MAT2)
{
    Matrix<T> Result(NumberOfRows,NumberOfColumns);

    for (int i = 0; i < NumberOfRows; i++)
        for (int j = 0; j < NumberOfColumns; j++)
            Result.MAT1[i][j] = 0;


    for (int i = 0; i < Result.NumberOfRows; i++)
    {
        for (int j = 0; j < Result.NumberOfColumns; j++)
        {
            Result.MAT1[i][j] = (MAT1[i][j] - MAT2.MAT1[i][j]);
        }
    }
    return Result;
}


template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &MAT2)
{
    Matrix<T> Result(NumberOfRows, NumberOfColumns);

    for (int i = 0; i < NumberOfRows; i++)
        for (int j = 0; j < MAT2.NumberOfColumns; j++)
            Result.MAT1[i][j] = 0;

    for (int i = 0; i < NumberOfRows; i++)
        for (int j = 0; j < MAT2.NumberOfColumns; j++)
            for (int k = 0; k <NumberOfColumns; k++)
            {
                Result.MAT1[i][j] += MAT1[i][k] * MAT2.MAT1[k][j];
            }
    return Result;
}




template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &MAT2) {
    Matrix<T> Result(NumberOfRows, NumberOfColumns);
    for (int i = 0; i < NumberOfRows; i++)
        for (int j = 0; j < NumberOfColumns; j++)
            Result.MAT1[i][j] = 0;

    for (int i = 0; i < Result.NumberOfRows; i++)
    {
        for (int j = 0; j < Result.NumberOfColumns; j++)
        {
            Result.MAT1[i][j] = (MAT1[i][j] + MAT2.MAT1[i][j]);
        }
    }
    return Result;
}

template<class T>
[[maybe_unused]] Matrix<T>::Matrix(const Matrix<T> &MAT2) {
    this->NumberOfColumns = MAT2.NumberOfColumns;
    this->NumberOfRows = MAT2.NumberOfRows;
    this->MAT1 = new T*[NumberOfRows];

    for (int i = 0; i < NumberOfRows; i++)
        this->MAT1[i] = new T[NumberOfColumns];

    for (int i = 0; i < NumberOfRows; i++)
        for (int j = 0; j < NumberOfColumns; j++)
            this->MAT1[i][j] = MAT2.MAT1[i][j];
}

template<class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < NumberOfRows; i++){
        delete [] MAT1[i];
    }
    delete[] MAT1;
    MAT1 = nullptr;
}

template<class T>
Matrix<T> &Matrix<T>::Transpose(Matrix<T> &MAT) {
    Matrix<T> TEMP(MAT.NumberOfRows,MAT.NumberOfColumns);

    for (int i = 0; i < MAT.NumberOfRows; i++)
        for (int j = 0; j < MAT.NumberOfColumns; j++)
            TEMP.MAT1[i][j] = MAT.MAT1[j][i];     //put all values in the rotated matrix

    for (int i = 0; i < MAT.NumberOfRows; i++)
        for (int j = 0; j < MAT.NumberOfColumns; j++)
            MAT.MAT1[i][j] = TEMP.MAT1[i][j];

    return MAT;

}

template class Matrix<int>;