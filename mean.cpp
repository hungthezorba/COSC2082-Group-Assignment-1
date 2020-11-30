#include <iostream>
#include "mean.h"

using namespace std;


double mean(double array[], int arraySize) {


    double sum = 0.0,
            mean;

    for (int i = 0; i < arraySize; i++) {
        sum += array[i];
    }
    mean = sum / arraySize;


    return mean;
}
