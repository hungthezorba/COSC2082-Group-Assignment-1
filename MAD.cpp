//
// Created by Enterprise on 11/6/2020.
//
#include<iostream>
#include"MAD.h"

double getMeanDistance(int value,double mean){
    if (value-mean>=mean-value){
        return value - mean;
    }
    return mean-value;
}
double getMAD(int a[],double mean,int n ){
    double total = 0;
    for(int i =0;i<n;i++){
        total+=getMeanDistance(a[i],mean);
    }
    return total/n;
}

