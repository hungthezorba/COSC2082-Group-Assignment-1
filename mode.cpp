//
// Created by Hung Nguyen on 26/04/19.
//

#include <iostream>
#include "mode.h"

using namespace std;


double mode(double array[], int arraySize) {
    int maxCount = 0;
    int mode;
    int count;
    for (int i = 0; i < arraySize; i++) {
        count = 0;
        for (int j = 0; j < arraySize; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = array[i];
        }
    }
    return mode;
}