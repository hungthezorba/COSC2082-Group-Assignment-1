#include <iostream>
#include "variance.h"
#include <cmath>
#include "mean.h"

using namespace std;

double variance(int array[], int arraySize) {

    double meanVari = mean(array, arraySize);

    double sumSquareDiff = 0;
    for (int i = 0; i < arraySize; i++)
        sumSquareDiff += (array[i] - meanVari) * (array[i] - meanVari);
    double vari = sumSquareDiff / (arraySize - 1);

    return vari;

}
