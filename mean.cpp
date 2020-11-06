#include <iostream>;
#include "mean.h"
using namespace std;

float mean(int num[], int numberOfData) {

    float sum = 0.0,
            mean;

    for(int i = 0; i < numberOfData; i++)
    {
        sum += num[i];
    }
    mean = sum / numberOfData;

    cout<<"Mean is: " <<mean<<endl;
    return 0;
}
