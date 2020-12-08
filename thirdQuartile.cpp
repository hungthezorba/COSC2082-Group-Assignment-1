// COSC2082 - A1 - Quan Bui

#include <iostream>
#include "thirdQuartile.h"
#include "median.h"

using namespace std;

double findThirdQuartile(double array[], int arraySize) {
  // Declaration
  double *upperHalf = new double [arraySize/2]; // An array with the size/2 of the input data
  double thirdQuartile;
  int index = 0;
  double *newArr = new double [arraySize];
  for (int j = 0;j<arraySize;j++){
      newArr[j] = array[j];
  }
  bubbleSort(newArr,arraySize);

  if (arraySize % 2 == 0) {
      for (int i = arraySize/2; i < arraySize; i++) {
          upperHalf[index] = newArr[i]; //
          index++;
      }
  } else {
      for (int i = arraySize/2 + 1; i < arraySize; i++) {
          upperHalf[index] = newArr[i]; //
          index++;
      }
  }
  // Calculate third quartile with Median of upper half data
  thirdQuartile = findMedian(upperHalf, arraySize/2);
  delete newArr;
  delete upperHalf;

  return thirdQuartile;
}
