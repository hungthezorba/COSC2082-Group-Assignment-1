//
// Created by Enterprise on 11/6/2020.
//

#include<iostream>
#include"median.h"

using namespace std;

void swap(double *xp, double *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void deepcopy(double source[], double target[], int len) {
    for (int i = 0; i < len; i++) {
        target[i] = source[i];
    }
}

void bubbleSort(double array[], int arraySize)
{
    int i, j;
    for (i = 0; i < arraySize-1; i++)

        // Last i elements are already in place
        for (j = 0; j < arraySize-i-1; j++)
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
}
double findMedian(double array[],int size)
{
    // First we sort the array
    double *newarr = new double [size];
    deepcopy(array, newarr, size);
    bubbleSort(newarr, size);
    // check for even case
    if (size % 2 != 0) {
        double returnVal = (double)newarr[size / 2];
        delete newarr;
        return returnVal;
    }

    double returnVal = (double)(newarr[(size - 1) / 2] + newarr[size / 2]) / 2.0;
    delete newarr;

    return returnVal;
}

