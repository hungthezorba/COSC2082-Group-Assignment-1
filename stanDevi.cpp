#include <iostream>
#include "variance.h"
#include <cmath>
#include "stanDevi.h"

using namespace std;


double stanDevi(double array[], int arraySize) {


    double variStan = variance(array, arraySize);

    double stanDevi = sqrt(variStan);

    return stanDevi ;

}