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
    char buff[256] = {};
    in_stream.open(filename);

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

    in_stream.close();
    return line;
}

void read_CSV(double *array_x, double *array_y, char *filename, int array_size) {
    ifstream in_stream;
    char buff[256] = {};

    in_stream.open(filename);
    if (in_stream.fail()) {
        cout << "ERROR: Cannot loading the file" << endl;
        return;
    }

    string dataline; // Initialize a string variable to handling each line in csv
    int comma_index; // Initialize an int variable to store the index of separated comma

    in_stream.getline(buff, sizeof(buff)); // skip the first line

    for (int i = 0; i < array_size; i++) {
        in_stream.getline(buff, sizeof(buff)); // Get the whole line data
        dataline = buff; // assign buff to string type variable
        comma_index = dataline.find(','); // Retrieve the index of comma in the line
        array_x[i] = stof(dataline.substr(0, comma_index)); // Retrieve x value in the line
        array_y[i] = stof(dataline.substr(comma_index + 1)); // Retrieve y value in the line
    }
    in_stream.close();

}

int main(int argc, char *argv[]) {

    // Initialize x, y array to store the value
    int array_size = read_line_csv(argv[1]) - 1; // subtract the header line
    double *x = new double [array_size];
    double *y = new double [array_size];

    read_CSV(x,y,argv[1],array_size);

    cout << "- - - - - - - - Descriptive Statistics - - - - - - - -" << endl;
    cout << "mean_x = " << mean(x, array_size) << " - " << "mean_y = " << mean(y, array_size) << endl;
    cout << "median_x = " << findMedian(x, array_size) << " - " << "median_y = " << findMedian(y, array_size) << endl;
    cout << "mode_x = " << mode(x, array_size) << " - " << "mode_y = " << mode(y, array_size) << endl;
    cout << "var_x = " << variance(x, array_size) << " - " << "var_y = " << variance(y, array_size) << endl;
    cout << "stdev_x = " << stanDevi(x, array_size) << " - " << "stdev_y = " << stanDevi(y, array_size) << endl;
    cout << "mad_x = " << getMAD(x, array_size) << " - " << "mad_y = " << getMAD(y, array_size) << endl;
    cout << "q1_x = " << findFirstQuartile(x, array_size) << " - " << "q1_y = " << findFirstQuartile(y, array_size) << endl;
    cout << "q3_x = " << findThirdQuartile(x, array_size) << " - " << "q3_y = " << findThirdQuartile(y, array_size) << endl;

    cout << "- - - - - - - - Inferential Statistics - - - - - - - -" << endl;
    cout << "cov(x_y) = " << Cov(x, y, array_size) << endl;
    cout << "r(x_y) = " << Corr(x, y, array_size) << endl;
    double *LRegression = LinearRegression(x, y, array_size);
    double slope = LRegression[0];
    double intercept = LRegression[1];
    cout << "y = " << slope << "x + " << intercept << endl;


    cout << "- - - - - - - - Group Information - - - - - - - -" << endl;
    cout << "ASSIGNMENT 1 GROUP 15" << endl;
    cout << "s3804690, s3804690@rmit.edu.vn, Hung, Nguyen";

    delete[] x;
    delete[] y;
    return 0;
}

