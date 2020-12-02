#include <iostream>
#include "MAD.h"
#include "mean.h"
#include "Inferential.h"
#include <math.h>
#include "stanDevi.h"
using namespace std;

double Cov(double* valueX, double* valueY, int size ){
    double meanX = mean(valueX, size);
    double meanY = mean(valueY, size);
    double total = 0;
    for (int i = 0;i<size;i++){
        double thiscov = (valueX[i] - meanX)*(valueY[i]-meanY);
        total += thiscov;

    return total/(size -1);
    }
}


double Corr(double* valueX, double* valueY, int size ){
    double totalX = 0;
    double totalY = 0;
    double productXY = 0;
    double totalYSquare = 0;
    double totalXSquare = 0;
    for (int i = 0 ;i<size;i++){
        double thisX = valueX[i];
        double thisY = valueY[i];
        totalX+=thisX;
        totalY += thisY;
        productXY += thisX * thisY;
        totalXSquare += thisX*thisX;
        totalYSquare += thisY*thisY;
    }
    double numerator = - totalX*totalY + size*productXY;
    double denominatorSquare = (size*totalXSquare - totalX*totalX)*(size*totalYSquare - totalY*totalY);
    double denominator = sqrt(denominatorSquare);
    return numerator/denominator;
}

double *LinearRegression (double *Xarray, double *Yarray, int size){
    static double ParameterPoint[2];
    double meanX = mean(Xarray,size);
    double meanY = mean(Yarray, size);
    double stdevX = stanDevi(Xarray,size);
    double stdevY = stanDevi(Yarray,size);
    double corr = Corr(Xarray,Yarray,size);

    double slope = corr*stdevY/stdevX;
    double bias = meanY - slope*meanX;

    ParameterPoint[0] = slope;
    ParameterPoint[1] = bias;
    return ParameterPoint;


}





