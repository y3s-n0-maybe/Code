#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "C:\Users\Owner\Desktop\Code\Second Year\Comp Phys\C++\gnuplot.cxx"
using namespace std;

double Error(double approx, double value){ // future proofing in case we are asked for more errors 
    double error = fabs(value - approx)/value;
    return error;
}

double MonteCarloCircle(int throws){
    double randX, randY;
    int hits = 0;

    for (int i = 0; i < throws; i++) {
        randX = rand() / (double) RAND_MAX;
        randY = rand() / (double) RAND_MAX;
        if (randX * randX + randY * randY < 1) {
            hits++;
        }
    }
    double area = hits / (double) throws;
    return area;
}

double PlotError(){
    double y[9];
    double x[9];
    for(int i = 0; i < 9; i++){
        x[i] = i;
        y[i] = log(Error(MonteCarloCircle(pow(10, i))*4, M_PI));
    }

    gnuplot_one_function("Error of Monte Carlo Integration", "linespoints", "Iteration", "Logarithm of Error", x, y, 9);
}

int main() {
    srand(time(NULL));
    double area = MonteCarloCircle(pow(10, 6));

    double pi = 4.0 * area;
    printf("%lf\n", pi);

    PlotError();
}