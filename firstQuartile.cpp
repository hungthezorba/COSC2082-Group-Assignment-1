//
// Created by Hung Nguyen on 26/04/19.
//

#include <iostream>
#include "firstQuartile.h"
#include "median.h"

using namespace std;

double findFirstQuartile(double array[], int arraySize) {
    double *lowerHalf = new double[arraySize/2]; // declare a array contains lower half in data
    double firstQuartile;
    double *newArr = new double[arraySize];
    for (int j = 0;j<arraySize;j++){
        newArr[j] = array[j];
    }
    bubbleSort(newArr,arraySize);

    for (int i = 0; i < arraySize/2; i++) {
        lowerHalf[i] = newArr[i]; //
    }

    firstQuartile = findMedian(lowerHalf, arraySize/2);
    delete newArr;
    delete lowerHalf;
    return firstQuartile;
}
