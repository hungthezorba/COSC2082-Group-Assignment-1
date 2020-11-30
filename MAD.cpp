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
double getMAD(double a[],int n ){
    double mean_value = mean(a,n);
    double total = 0;
    for(int i =0;i<n;i++){
        total+=getMeanDistance(a[i],mean_value);
    }
    return total/n;
}



