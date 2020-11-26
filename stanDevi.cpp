#include <iostream>
#include "variance.h"
#include <cmath>
#include "stanDevi.h"

using namespace std;

double stanDevi(int num[], int numberOfData) {


    double variStan = variance(num, numberOfData);

    double stanDevi = sqrt(variStan);

    return stanDevi ;

}