//
// Created by Hung Nguyen on 26/04/19.
//

#include <iostream>
#include "firstQuartile.h"
#include "median.h"

using namespace std;

double findFirstQuartile(int array[], int arrSize) {
    int *lowerHalf = new int[arrSize/2]; // declare a array contains lower half in data
    double firstQuartile;
    int *newArr = new int[arrSize];
    for (int j = 0;j<arrSize;j++){
        newArr[j] = array[j];
    }
    bubbleSort(newArr,arrSize);

    for (int i = 0; i < arrSize/2; i++) {
        lowerHalf[i] = newArr[i]; //
    }
    delete newArr;

    firstQuartile = findMedian(lowerHalf, arrSize/2);
    delete lowerHalf;
    return firstQuartile;
}
