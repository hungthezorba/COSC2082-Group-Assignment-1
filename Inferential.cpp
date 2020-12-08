#include <iostream>
#include "MAD.h"
#include "mean.h"
#include "Inferential.h"
#include <math.h>
#include "stanDevi.h"
using namespace std;

double Cov(double* valueX, double* valueY, int arraySize ){
    double meanX = mean(valueX, arraySize);
    double meanY = mean(valueY, arraySize);
    double total = 0;
    for (int i = 0;i<arraySize;i++){
        double thiscov = (valueX[i] - meanX)*(valueY[i]-meanY);
        total += thiscov;

    }
    return total/(arraySize -1);
}


double Corr(double* valueX, double* valueY, int arraySize ){
    double totalX = 0;
    double totalY = 0;
    double productXY = 0;
    double totalYSquare = 0;
    double totalXSquare = 0;
    for (int i = 0 ;i<arraySize;i++){
        double thisX = valueX[i];
        double thisY = valueY[i];
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

double *LinearRegression (double *Xarray, double *Yarray, int arraySize){
    static double ParameterPoint[2];
    double meanX = mean(Xarray,arraySize);
    double meanY = mean(Yarray, arraySize);
    double stdevX = stanDevi(Xarray,arraySize);
    double stdevY = stanDevi(Yarray,arraySize);
    double corr = Corr(Xarray,Yarray,arraySize);

    double slope = corr*stdevY/stdevX;
    double bias = meanY - slope*meanX;

    ParameterPoint[0] = slope;
    ParameterPoint[1] = bias;
    return ParameterPoint;


}





