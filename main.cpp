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
#include <iomanip>

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

    double meanX = mean(arrayX, arraySize);
    double medianX = findMedian(arrayX, arraySize);
    double modeX = mode(arrayX, arraySize);
    double varianceX = variance(arrayX, arraySize);
    double stanDeviX = stanDevi(arrayX, arraySize);
    double madX = getMAD(arrayX, arraySize);
    double firstQuartileX = findFirstQuartile(arrayX, arraySize);
    double thirdQuartileX = findThirdQuartile(arrayX, arraySize);

    double meanY = mean(arrayY, arraySize);
    double medianY = findMedian(arrayY, arraySize);
    double modeY = mode(arrayY, arraySize);
    double varianceY = variance(arrayY, arraySize);
    double stanDeviY = stanDevi(arrayY, arraySize);
    double madY = getMAD(arrayY, arraySize);
    double firstQuartileY = findFirstQuartile(arrayY, arraySize);
    double thirdQuartileY = findThirdQuartile(arrayY, arraySize);

    double CorrelXY = Corr(arrayX, arrayY, arraySize);
    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    cout << "- - - - - - - - Descriptive Statistics - - - - - - - -" << endl;
    cout << "mean_x = " << meanX << " - " << "mean_y = " << meanY << endl;
    cout << "median_x = " << medianX << " - " << "median_y = " << medianY << endl;
    cout << "mode_x = " << modeX << " - " << "mode_y = " << modeY << endl;
    cout << "var_x = " << varianceX << " - " << "var_y = " << varianceY << endl;
    cout << "stdev_x = " << stanDeviX << " - " << "stdev_y = " << stanDeviY << endl;
    cout << "mad_x = " << madX << " - " << "mad_y = " << madY << endl;
    cout << "q1_x = " << firstQuartileX << " - " << "q1_y = " << firstQuartileY << endl;
    cout << "q3_x = " << thirdQuartileX << " - " << "q3_y = " << thirdQuartileY << endl;

    cout << "- - - - - - - - Inferential Statistics - - - - - - - -" << endl;
    cout << "cov(x_y) = " << Cov(arrayX, arrayY, arraySize, meanX, meanY) << endl;
    cout << "r(x_y) = " << CorrelXY << endl;
    double *LRegression = LinearRegression(meanX, meanY, stanDeviX, stanDeviY, CorrelXY);
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

