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

int read_line_csv(char *filename) {
    ifstream in_stream;
    string dataline;
    in_stream.open(filename);

    if (in_stream.fail()) {
        cout << "ERROR: cannot loading file";
        return -1;
    }
    int line = 0;
    // Looping to determine the size of array base on number of lines
    while(!in_stream.eof()) {
        getline(in_stream, dataline);
        line++;
    }
    // Reset stream to starting position

    in_stream.close();
    return line;
}

void read_CSV(double *arrayX, double *arrayY, char *filename, int arraySize) {
    ifstream in_stream;

    in_stream.open(filename);
    if (in_stream.fail()) {
        cout << "ERROR: Cannot loading the file" << endl;
        return;
    }


    string dataline; // Initialize a string variable to handling each line in csv
    int comma_index; // Initialize an int variable to store the index of separated comma

    getline(in_stream, dataline); // skip the first line

    for (int i = 0; i < arraySize; i++) {
        getline(in_stream, dataline); // skip the first line
        comma_index = dataline.find(','); // Retrieve the index of comma in the line
        arrayX[i] = stof(dataline.substr(0, comma_index)); // Retrieve x value in the line
        arrayY[i] = stof(dataline.substr(comma_index + 1)); // Retrieve y value in the line
    }
    in_stream.close();

}

int main(int argc, char *argv[]) {

    // Initialize x, y array to store the value
    int arraySize = read_line_csv(argv[1]) - 1; // subtract the header line
    double *arrayX = new double [arraySize];
    double *arrayY = new double [arraySize];

    read_CSV(arrayX,arrayY,argv[1],arraySize);

    cout << "- - - - - - - - Descriptive Statistics - - - - - - - -" << endl;
    cout << "mean_x = " << mean(arrayX, arraySize) << " - " << "mean_y = " << mean(arrayY, arraySize) << endl;
    cout << "median_x = " << findMedian(arrayX, arraySize) << " - " << "median_y = " << findMedian(arrayY, arraySize) << endl;
    cout << "mode_x = " << mode(arrayX, arraySize) << " - " << "mode_y = " << mode(arrayY, arraySize) << endl;
    cout << "var_x = " << variance(arrayX, arraySize) << " - " << "var_y = " << variance(arrayY, arraySize) << endl;
    cout << "stdev_x = " << stanDevi(arrayX, arraySize) << " - " << "stdev_y = " << stanDevi(arrayY, arraySize) << endl;
    cout << "mad_x = " << getMAD(arrayX, arraySize) << " - " << "mad_y = " << getMAD(arrayY, arraySize) << endl;
    cout << "q1_x = " << findFirstQuartile(arrayX, arraySize) << " - " << "q1_y = " << findFirstQuartile(arrayY, arraySize) << endl;
    cout << "q3_x = " << findThirdQuartile(arrayX, arraySize) << " - " << "q3_y = " << findThirdQuartile(arrayY, arraySize) << endl;

    cout << "- - - - - - - - Inferential Statistics - - - - - - - -" << endl;
    cout << "cov(x_y) = " << Cov(arrayX, arrayY, arraySize) << endl;
    cout << "r(x_y) = " << Corr(arrayX, arrayY, arraySize) << endl;
    double *LRegression = LinearRegression(arrayX, arrayY, arraySize);
    double slope = LRegression[0];
    double intercept = LRegression[1];
    cout << "y = " << slope << "x + " << intercept << endl;


    cout << "- - - - - - - - Group Information - - - - - - - -" << endl;
    cout << "ASSIGNMENT 1 GROUP 15" << endl;
    cout << "s3804690, s3804690@rmit.edu.vn, Hung, Nguyen" << endl;
    cout << "s3804687, s3804687@rmit.edu.vn, Dat, Ngo" << endl;
    cout << "s3536647, s3536647@rmit.edu.vn, Quan, Bui" << endl;
    cout << "s3777230, s3777230@rmit.edu.vn, Huy, Bui" << endl;


    delete[] arrayX;
    delete[] arrayY;

    return 0;
}

