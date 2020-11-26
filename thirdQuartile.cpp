// COSC2082 - A1 - Quan Bui

#include <iostream>
#include "thirdQuartile.h"
#include "median.h"

using namespace std;

double findThirdQuartile(int array[], int arrSize) {
  // Declaration
  int upperHalf[arrSize/2]; // An array with the size/2 of the input data
  double thirdQuartile;

  // Populate upper half array with upper half data
  for (int i = arrSize/2 + 1; i < arrSize; i++) {
    for (int j = 0; j < arrSize/2; j++) {
      upperHalf[j] = array[i];
    }
  }

  // Calculate third quartile with Median of upper half data
  thirdQuartile = findMedian(upperHalf, arrSize/2);

  return thirdQuartile;
}
