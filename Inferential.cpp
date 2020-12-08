#include <iostream>
#include "MAD.h"
#include "mean.h"
#include "Inferential.h"
#include <math.h>
#include "stanDevi.h"
using namespace std;

double Cov(double* arrayX, double* arrayY, int arraySize ){
    double meanX = mean(arrayX, arraySize);
    double meanY = mean(arrayY, arraySize);
    double total = 0;
    for (int i = 0;i<arraySize;i++){
        double thiscov = (arrayX[i] - meanX)*(arrayY[i]-meanY);

        total += thiscov;

    }
    return total/(arraySize -1);
}


double Corr(double* arrayX, double* arrayY, int arraySize ){

    double totalX = 0;
    double totalY = 0;
    double productXY = 0;
    double totalYSquare = 0;
    double totalXSquare = 0;
    for (int i = 0 ;i<arraySize;i++){
        double thisX = arrayX[i];
        double thisY = arrayY[i];

        totalX+=thisX;
        totalY += thisY;
        productXY += thisX * thisY;
        totalXSquare += thisX*thisX;
        totalYSquare += thisY*thisY;
    }
    double numerator = - totalX*totalY + arraySize*productXY;
    double denominatorSquare = (arraySize*totalXSquare - totalX*totalX)*(arraySize*totalYSquare - totalY*totalY);
    double denominator = sqrt(denominatorSquare);
    return numerator/denominator;
}

double *LinearRegression (double *arrayX, double *arrayY, int arraySize){
    static double ParameterPoint[2];
    double meanX = mean(arrayX,arraySize);
    double meanY = mean(arrayY, arraySize);
    double stdevX = stanDevi(arrayX,arraySize);
    double stdevY = stanDevi(arrayY,arraySize);
    double corr = Corr(arrayX,arrayY,arraySize);


    double slope = corr*stdevY/stdevX;
    double bias = meanY - slope*meanX;

    ParameterPoint[0] = slope;
    ParameterPoint[1] = bias;
    return ParameterPoint;


}





