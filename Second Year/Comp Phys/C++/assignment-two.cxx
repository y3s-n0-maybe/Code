#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <algorithm>
#include "gnuplot.cxx"
#include <fstream>
using namespace std;


double Error(double approx, double value, string type){ // future proofing in case we are asked for more errors 
    double error = value- approx;

    if(type.find("abs") != std::string::npos || type.find("ABS") != std::string::npos || type.find("Abs") != std::string::npos){
        error = fabs(error);
    }

    if(type.find("rel") != std::string::npos || type.find("REL") != std::string::npos || type.find("Rel") != std::string::npos){
        error = error / value;
    }

    return error;
}

double SinApprox(double n)
{
    double val = n - ((n*n*n)/6);
    return val;
}

void SmallAngleApproxError(){
    double n = 0.01;
    double err = 0;
    double step = 0.01;
    double limit = pow(10, -7);

    while(step >= limit){
        while(err < 0.01){
            n += step;
            err = Error(n, sin(n), "rel abs");
        }
        n -= step;
        err = Error(n, sin(n), "rel abs");
        step *= .1;
    }

    cout << "Small angle approximation breaks down at " << n << " radians\n";

    cout << "A second order Taylor approximation of sin returns an error of " ;
    cout << Error(SinApprox(n), sin(n), "rel abs")*100;
    cout << "\% at " << n << " radians\n";


    n = 0.01;
    err = 0;
    step = 0.01;
    while(step >= limit){
        while(err < 0.01){
            n += step;
            err = Error(SinApprox(n), sin(n), "rel abs");
        }
        n -= step;
        err = Error(SinApprox(n), sin(n), "rel abs");
        step *= .1;
    }

    cout << "Second order Taylor approximation of sin breaks down at " << n << " radians\n";
}

double fOfx(double x) {
    double y = 1 + (x*x) - x ;
    return y;
}

double fpOfx(double x) {
    double y = (2 * x) - 1;
    return y;
}

double CentralDerivation(double x, double d){
    double dx = fOfx(x + d) - fOfx(x - d);

    double dxdy = dx / (2*d);

    return dxdy;
}

double ForwardDerivation(double x, double d){
    double dx = fOfx(x + d) - fOfx(x);

    double dxdy = dx / d;

    return dxdy;
}

double BackwardDerivation(double x, double d){
    double dx = fOfx(x) - fOfx(x - d);

    double dxdy = dx / d;
    
    return dxdy;
}

void ErrorComparison(double x, double d, string type)
{
    double c_er, f_er, b_er;

    c_er = Error(fpOfx(x), CentralDerivation(x, d), type);
    f_er = Error(fpOfx(x), ForwardDerivation(x, d), type);
    b_er = Error(fpOfx(x), BackwardDerivation(x, d), type);

    cout << "\n Central Approximation Error: " << c_er;
    cout << "\n Forward Approximation Error: " << f_er;
    cout << "\n Backward Approximation Error: " << b_er;
}

void Derivatives() {
    double d = 0.0;
    double n = 0.0;
    
    cout << "For What x? ";
    cin >> n;
    cout << "\nFor what delta x? ";
    cin >> d;

    int choice = 1;

    while (choice != 0){
    cout << "\nWhich Method?\n";
    cout << "0. Quit \n";
    cout << "1. Central Approximation \n";
    cout << "2. Forward Approximation \n";
    cout << "3. Backward Approximation \n";
    cout << "4. Compare Errors\n";
    cin >> choice;

    switch(choice){
        case 0:
            break;
        case 1:
            cout << "Central approximation of F'(x) at x = " << n << " with a dx of " << d << " = ";
            cout << CentralDerivation(n, d);
            break;
        case 2:
            cout << "Forward approximation of F'(x) at x = " << n << " with a dx of " << d << " = ";
            cout <<ForwardDerivation(n, d);
            break;
        case 3:
            cout << "Forward approximation of F'(x) at x = " << n << " with a dx of " << d << " = ";
            cout << BackwardDerivation(n, d);
            break;
        case 4:
            cout << "What kind of error (absolute, relative)? ";
            
            string dummy = "";
            getline(cin, dummy); // need dummy getline to read ghost newline character

            string type = "";
            getline(cin, type);
            ErrorComparison(n, d, type);
            break;
    }}
}

int main()
{
    Derivatives();
    
    /*int choice = 0;

    while(choice != 6){
        choice = 0;
        
        cout << "\nWhich function would you like to run? \n";
        cout << "1. Sum & Product of 3 Doubles \n";
        cout << "2. Convert a double to a binary number \n";
        cout << "3. Convert a binary number to a double \n";
        cout << "4. Calculate mean & stdev of delays \n";
        cout << "5. Calculate mean, median, & stdev of 2d6 rolls\n";
        cout << "6. End Program\n";

        cin >> choice;

        switch(choice){
            case 1:
                sum_prod();
                break;
            case 2:
                double_to_bin();
                break;
            case 3:
                bin_to_double();
                break;
            case 4:
                delays();
                break;
            case 5:
                dice_calc();
                break;
            case 6:
                cout << "\nThank you! Stopping program.\n";
                return 0;
            default: 
                cout << "\nInvalid Choice.\n";
        }
    } */
    return 0;
}