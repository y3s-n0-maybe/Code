#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;


double Error(double approx, double value){ // future proofing in case we are asked for more errors 
    double error = fabs(value - approx)/value;
    return error;
}

double MonteCarloFunction(int throws, double (*func)(double), int xstart, int xrange, int ystart, int yrange){
    double randX, randY, Y;
    int hits = 0;

    for (int i = 0; i < throws; i++) {
        randX = (rand() / (double) RAND_MAX)*(xrange) + xstart;
        Y = func(randX);
        randY = (rand() / (double) RAND_MAX)*(yrange) + ystart;
        if (randY <= Y) {
            hits++;
        }
    }
    double area = ((double) hits / (double) throws) * xrange * yrange;
    return area;
}

double fOfx(double x){
    double y = (300 * x) / (1 + exp(x));
    return y;
}

int main() {
    srand(time(NULL));
    double area = MonteCarloFunction(pow(10, 8), fOfx, 0, 10, 0, 84); // couldn't reliably get below 0.01% error wihtout the program hanging. trapezoidal is more accurate & faster. 
    double error = Error(area, 246.590293505) * 100;

    printf("Value: %lf\nPercentage Error: %g%%", area, error);
}