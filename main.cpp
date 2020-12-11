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

// Function to check if the receive data is numerical value
bool isNumeric(string input) {
    int countDot = 0;
    if (input[0] < '0' || input[0] > '9') {
        if (input[0] != '+' && input[0] != '-') {
            if ( input[0] == '.') {
                countDot++;
            } else {
                return false;
            }
        }
    }

    for (int j = 0; j < input.length(); j++) {
        if (input[j] < '0' || input[j] > '9' ) {
            if (input[j] != '.') {
                return false;
            } else {
                countDot++; //
            }
            if (countDot > 1) {
                return false;
            }

        }
    }
    return true;
}

// Function to get the number of line in the csv file
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

void read_CSV(double *arrayX, double *arrayY, char *filename, int *arraySize) {
    ifstream in_stream;

    in_stream.open(filename);
    if (in_stream.fail()) {
        cout << "ERROR: Cannot loading the file" << endl;
        return;
    }


    string dataline; // Initialize a string variable to handling each line in csv
    int comma_index; // Initialize an int variable to store the index of separated comma

    getline(in_stream, dataline); // skip the first line
    string X;
    string Y;
    int count = 0;
    int index = 0;
    while (count < *arraySize) {
        bool checkX;
        bool checkY;
        getline(in_stream, dataline); // skip the first line
        comma_index = dataline.find(','); // Retrieve the index of comma in the line
        X = dataline.substr(0, comma_index);
        if ( (int) dataline[dataline.length() - 1] == 13 ) { // Some OS system still using the 'CARRIAGE RETURN' so the getline will not ignore the '\r'
            Y = dataline.substr(comma_index + 1, dataline.length() - 1 - (comma_index + 1));
        } else {
            Y = dataline.substr(comma_index + 1);
        }
        // Check if X, Y are values of numerical type
        checkX = isNumeric(X);
        checkY = isNumeric(Y);
        if (checkX && checkY) {
            // If true we convert to double
            arrayX[index] = stod(X);
            arrayY[index] = stod(Y);
            // And increase the index
            index++;
        }
        // If not we skip to next line, the index remain the same
        count++;
    }
    // After all the calculation, the array size now should be the index value
    // So we return the new arraySize
    *arraySize = index;
    in_stream.close();
}

int main(int argc, char *argv[]) {

    // Initialize x, y array to store the value
    int arraySize = read_line_csv(argv[1]) - 1; // subtract the header line
    double *arrayX = new double [arraySize];
    double *arrayY = new double [arraySize];

    read_CSV(arrayX,arrayY,argv[1],&arraySize);
    double meanX = mean(arrayX, arraySize);
    double medianX = findMedian(arrayX, arraySize);
    double varianceX = variance(arrayX, arraySize);
    double stanDeviX = stanDevi(arrayX, arraySize);
    double madX = getMAD(arrayX, arraySize);
    double firstQuartileX = findFirstQuartile(arrayX, arraySize);
    double thirdQuartileX = findThirdQuartile(arrayX, arraySize);

    double meanY = mean(arrayY, arraySize);
    double medianY = findMedian(arrayY, arraySize);
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
    cout << "mode_x = " ;
    findMode(arrayX, arraySize);
    cout << " - " << "mode_y = ";
    findMode(arrayY, arraySize);
    cout << endl;
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
    cout << "ASSIGNMENT 1 GROUP 18" << endl;
    cout << "s3804690, s3804690@rmit.edu.vn, Hung, Nguyen" << endl;
    cout << "s3804687, s3804687@rmit.edu.vn, Dat, Ngo" << endl;
    cout << "s3536647, s3536647@rmit.edu.vn, Quan, Bui" << endl;
    cout << "s3777230, s3777230@rmit.edu.vn, Huy, Bui" << endl;

// Delete the allocate memory in heap to save memory
    delete[] arrayX;
    delete[] arrayY;

    return 0;
}

