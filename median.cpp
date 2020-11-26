//
// Created by Enterprise on 11/6/2020.
//

#include<iostream>
#include"median.h"

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void deepcopy(int source[], int target[], int len) {
    for (int i = 0; i < len; i++) {
        target[i] = source[i];
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
double findMedian(int a[],int n)
{
    // First we sort the array
    int* newarr = new int[size];
    deepcopy(a, newarr, size);
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

