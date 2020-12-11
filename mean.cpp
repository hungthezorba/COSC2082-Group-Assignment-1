#include <iostream>
#include "mean.h"

using namespace std;


double mean(double array[], int arraySize) {

    double sum = 0.0,
            mean;
// Loop through array to get the sum
    for (int i = 0; i < arraySize; i++) {
        sum += array[i];
    }
    // Divide the sum for the array size to get the average
    mean = sum / arraySize;
    return mean;
}
