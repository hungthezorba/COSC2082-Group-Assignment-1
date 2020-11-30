//
// Created by Hung Nguyen on 26/04/19.
//

#include <iostream>
#include "mode.h"

using namespace std;


double mode(double array[], int arrSize) {
    int maxCount = 0;
    int mode;
    int count;
    for (int i = 0; i < arrSize; i++) {
        count = 0;
        for (int j = 0; j < arrSize; j++) {
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