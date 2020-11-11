#include <iostream>;
#include "variance.h"
#include <cmath>

using namespace std;

float variance(int num[], int numberOfData) {

    int sum = 0;
    for (int i = 0; i < numberOfData; i++)
        sum += num[i];
    double mean = (double) sum /
                  (double) numberOfData;

    double sumSquareDiff = 0;
    for (int i = 0; i < numberOfData; i++)
        sumSquareDiff += (num[i] - mean) * (num[i] - mean);
    double vari = sumSquareDiff / numberOfData;


    double stanDevi = sqrt(vari);

    cout << "Variance is: " << vari << endl;
    cout << "Standard Deviation is: " << stanDevi << endl;

    return 0;
}

