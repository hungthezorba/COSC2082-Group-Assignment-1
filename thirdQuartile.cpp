// COSC2082 - A1 - Quan Bui

#include <iostream>
#include "thirdQuartile.h"
#include "median.h"

using namespace std;

double findThirdQuartile(double array[], int arrSize) {
  // Declaration
  double *upperHalf = new double [arrSize/2]; // An array with the size/2 of the input data
  double thirdQuartile;
  int index = 0;
  double *newArr = new double [arrSize];
  for (int j = 0;j<arrSize;j++){
      newArr[j] = array[j];
  }
  bubbleSort(newArr,arrSize);

  if (arrSize % 2 == 0) {
      for (int i = arrSize/2; i < arrSize; i++) {
          upperHalf[index] = newArr[i]; //
          index++;
      }
  } else {
      for (int i = arrSize/2 + 1; i < arrSize; i++) {
          upperHalf[index] = newArr[i]; //
          index++;
      }
  }
  // Calculate third quartile with Median of upper half data
  thirdQuartile = findMedian(upperHalf, arrSize/2);
  delete newArr;
  delete upperHalf;

  return thirdQuartile;
}
