#include <iostream>
#include <fstream>
#include "mean.h"
#include "median.h"
#include "mode.h"
#include "MAD.h"
#include "firstQuartile.h"
#include "thirdQuartile.h"
#include "variance.h"
#include "stanDevi.h"
#include "Inferential.h"

using namespace std;
int main() {
    ifstream in_stream;
    ofstream out_stream;
    char buff[256] = {};

    in_stream.open("data1.csv");

    if (in_stream.fail()) {
        cout << "ERROR: cannot loading file";
        return -1;
    }
    int line = 0;
    // Looping to determine the size of array base on number of lines
    while(!in_stream.eof()) {
        in_stream.getline(buff, sizeof(buff));
        line++;
    }
    // Reset stream to starting position
    in_stream.clear();
    in_stream.seekg(0);
    // Initialize x, y array to store the value
    int arraySize = line - 1;
    double *arrayX = new double [arraySize];
    double *arrayY = new double [arraySize];
    string dataline; // Initialize a string variable to handling each line in csv
    int comma_index; // Initialize an int variable to store the index of separated comma

    in_stream.getline(buff, sizeof(buff)); // skip the first line

    for (int i = 0; i < arraySize; i++) {
        in_stream.getline(buff, sizeof(buff));
        dataline = buff;
        comma_index = dataline.find(',');
        arrayX[i] = stof(dataline.substr(0, comma_index));
        arrayY[i] = stof(dataline.substr(comma_index + 1));
    }
    cout << x[0] << endl;
    cout << "There are " << line << " lines in the csv file" << endl;
    delete[] arrayX;
    delete[] arrayY;
    return 0;
}

