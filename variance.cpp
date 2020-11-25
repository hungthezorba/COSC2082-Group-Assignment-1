#include <iostream>
#include "variance.h"
#include <cmath>
#include "mean.h"

using namespace std;

double variance(int num[], int numberOfData) {

    double meanVari = mean(num, numberOfData);

    double sumSquareDiff = 0;
    for (int i = 0; i < numberOfData; i++)
        sumSquareDiff += (num[i] - meanVari) * (num[i] - meanVari);
    double vari = sumSquareDiff / (numberOfData - 1);

    double stanDevi = sqrt(vari);

    return vari;





}

