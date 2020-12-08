//
// Created by Enterprise on 11/6/2020.
//
#include<iostream>
#include"MAD.h"
#include "mean.h"
#include<cmath>




double getMeanDistance(int value,double mean){
    if (value-mean>=mean-value){
        return value - mean;
    }
    return mean-value;
}
double getMAD(double array[],int arraySize ){
    double mean_value = mean(array,arraySize);
    double total = 0;
    for(int i =0;i<arraySize;i++){
        total+=getMeanDistance(array[i],mean_value);
    }
    return total/arraySize;
}



