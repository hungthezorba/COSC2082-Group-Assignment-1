//
// Created by Hung Nguyen on 26/04/19.
//

#include <iostream>
#include "firstQuartile.h"
#include "median.h"

using namespace std;

double findFirstQuartile(int array[], int arrSize) {
    int lowerHalf[arrSize/2]; // declare a array contains lower half in data
    double firstQuartile;
    for (int i = 0; i < arrSize/2; i++) {
        lowerHalf[i] = array[i]; //
    }

    firstQuartile = findMedian(lowerHalf, arrSize/2);
    return firstQuartile;
}
