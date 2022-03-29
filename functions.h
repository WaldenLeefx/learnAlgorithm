//
// Created by lee on 2021/12/20.
//

#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H
#include <iostream>
using namespace std;

template<class Ta, class Tb, class Tc>
Ta abc(const Ta& a, const Tb& b, const Tc& c)
{
    return a + b * c;
}
//exercise 1
void swap(int& x, int& y)
{
    int temp = x;
    x=y;
    y=temp;
}
//exercise 2
template<class T>
T count(const T *beg, const T *end)
{
    int n = 0;
    while (beg != end) {
        *beg++;
        n++;
    }
    return n;
}
//exercise 3
template<class T>
void fill(T* a,int start, int end, const T& value)
{//set a[start:end-1]
    for (int i = start; i < end; i++) {
        a[i] = value;
    }
}
//exercise 4
template<class T>
T inner_product(T* a, T* b, int n)
{
    T sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}
//exercise 5
template<class T>
void iota(T* a, int n, const T& val)
{
    for (int i = 0; i < n; ++i) {
        a[i] += val;
    }
}
//exercise 6
template<class T>
bool is_sorted2(const T *beg, const T *end)
{
    int c1=0;
    int c2=0;
    while(beg != end) {
        if (*beg < *beg+1) {
            c1++;
            *beg++;
        }
        if (*beg > *beg+1) {
            c2++;
            *beg++;
        }
    }
    if (c1 == end-beg || c2 == end-beg)
        return true;
    else
        return false;
}
//exercise 7
template<class T>
bool mismatch2(T* a, T* b, int n)
{
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i])
            return i;
    }
    return n;
}
//exercise 11
template<class T>
int count(T a[], int n, const T& val)
{
    if (n<1)
        throw "n must be >= 1";

    int theCount = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == val)
            theCount++;
    return theCount;

}

///make space for a 2d array
template<class T>
bool make2dArray1(T ** &x, int numberOfRows, int numberOfColumns)
{
    try {
        x = new T * [numberOfRows];
        for (int i = 0; i < numberOfRows; i++)
            x[i] = new int [numberOfColumns];
        return true;
    }
    catch (std::bad_alloc) {return false;}
}

template<class T>
void make2dArray2(T ** &x, int numberOfRows, int numberOfColumns)
{
    x = new T * [numberOfRows];
    for (int i = 0; i < numberOfRows; ++i)
        x[i] = new T [numberOfColumns];
}

template<class T>
void delete2dArray(T ** &x, int numberOfRows)
{
    for (int i = 0; i < numberOfRows; i++)
        delete [] x[i];

    delete [] x;
    x = NULL;
}
//exercise 12
template<class T>
bool make2dArray3(T ** &x, int numberOfRows, int rowSize[])
{
    //
    x = new T * [numberOfRows];
    for (int i = 0; i < numberOfRows; ++i)
        x[i] = new T [rowSize[i]];

    return true;
}
template<class T>
bool delete2dArray3(T ** &x, int numberOfRows)
{
    for (int i = 0; i < numberOfRows; ++i)
        delete [] x[i];

    delete [] x;
    x = NULL;
}
//exercise 13
template<class T>
void changeLength1D(T* &a, int oldLength, int newLength)
{
    if (newLength < 0)
        throw "new length must be >= 0.";

    T* temp = new T [newLength]; //new array
    int number = min(oldLength, newLength); //number to copy
    copy(a, a + number, temp);
    delete [] a; //deallocate old memory
    a = temp;
}
//exercise 14
template <class T>
void createSize2D(T ** &ch1, int rows, int cols)
{
    ch1 = new T* [rows];
    for (int i = 0; i < rows; i++)
        ch1[i] = new T [cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ch1[i][j] = 'A'+i+j;
}

template <class T>
void showSize2D(T **ch1, int rows, int cols)
{
    cout << "The Size2DArray = \n{\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << ch1[i][j] << " ";
        cout << endl;
    }
    cout << "}\n";
}

template<class T>
T** changeLength2d(T ** &a, int oldLengthOfRows, int oldSizeCol[], int newLengthOfRows, int newSizeCol[])
{
    //new 2d array
    T ** x;
    //make a row-pointer
    x = new T * [newLengthOfRows];
    //allocate space for every row
    for (int i = 0; i < newLengthOfRows; i++)
        x[i] = new T [newSizeCol[i]];

    for (int i = 0; i < min(oldLengthOfRows, newLengthOfRows); ++i)
        for (int j = 0; j < min(oldSizeCol[i], newSizeCol[i]); ++j)
            x[i][j] = a[i][j];

    //delete 2d array
    for (int i = 0; i < oldLengthOfRows; ++i)
        delete [] a[i];

    delete [] a;
    a = NULL;

    //return new 2d array
    return x;
}
#endif //UNTITLED_FUNCTIONS_H
