//
// Created by Enterprise on 11/25/2020.
//

#ifndef INFERENTIAL_H
#define INFERENTIAL_H

double Cov(double* arrayX, double* arrayY, int arraySize, double meanX, double meanY);
double Corr(double* arrayX, double* arrayY, int arraySize );
double *LinearRegression (double meanX, double meanY, double stdevX, double stdevY, double corr);


#endif //UNTITLED_INFERENTIAL_H
