//
// Created by Hung Nguyen on 26/04/19.
//

#include <iostream>
#include "firstQuartile.h"
#include "median.h"

using namespace std;

double findFirstQuartile(double array[], int arrSize) {
    double *lowerHalf = new double[arrSize/2]; // declare a array contains lower half in data
    double firstQuartile;
    double *newArr = new double[arrSize];
    for (int j = 0;j<arrSize;j++){
        newArr[j] = array[j];
    }
    bubbleSort(newArr,arrSize);

    for (int i = 0; i < arrSize/2; i++) {
        lowerHalf[i] = newArr[i]; //
    }

    firstQuartile = findMedian(lowerHalf, arrSize/2);
    delete newArr;
    delete lowerHalf;
    return firstQuartile;
}
