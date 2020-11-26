#include <iostream>
#include "MAD.h"
#include "mean.h"
#include "Inferential.h"
#include <math.h>
#include "stanDevi.h"
using namespace std;

double Cov(int* valueX, int* valueY, int size ){
    float meanX = mean(valueX,size);
    float meanY = mean(valueY, size);
    double total = 0;
    for (int i = 0;i<size;i++){
        double thiscov = (valueX[i] - meanX)*(valueY[i]-meanY);
        total += thiscov;

    return total/(size -1);
    }
}


double Corr(int* valueX, int* valueY, int size ){
    int totalX = 0;
    int totalY = 0;
    int productXY = 0;
    int totalYSquare = 0;
    int totalXSquare = 0;
    for (int i = 0 ;i<size;i++){
        int thisX = valueX[i];
        int thisY = valueY[i];
        totalX+=thisX;
        totalY += thisY;
        productXY += thisX * thisY;
        totalXSquare += thisX*thisX;
        totalYSquare += thisY*thisY;
    }
    int numerator = - totalX*totalY + size*productXY;
    int denominatorSquare = (size*totalXSquare - totalX*totalX)*(size*totalYSquare - totalY*totalY);
    double denominator = sqrt(denominatorSquare);
    return numerator/denominator;
}

double *LinearRegression (int *Xarray, int *Yarray, int size){
    static double ParameterPoint[2];
    float meanX = mean(Xarray,size);
    float meanY = mean(Yarray, size);
    double stdevX = stanDevi(Xarray,size);
    double stdevY = stanDevi(Yarray,size);
    double corr = Corr(Xarray,Yarray,size);

    double slope = corr*stdevY/stdevX;
    double bias = meanY - slope*meanX;

    ParameterPoint[0] = slope;
    ParameterPoint[1] = bias;
    return ParameterPoint;


}





