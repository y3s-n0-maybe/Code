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


double RelAbsError(double approx, double val){
    double err = fabs((approx - val)/val);
    return err;
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
            err = RelAbsError(n, sin(n));
        }
        n -= step;
        err = RelAbsError(n, sin(n));
        step *= .1;
    }

    cout << "Small angle approximation breaks down at " << n << " radians\n";

    cout << "A second order Taylor approximation of sin returns an error of " ;
    cout << RelAbsError(SinApprox(n), sin(n))*100;
    cout << "\% at " << n << " radians\n";


    n = 0.01;
    err = 0;
    step = 0.01;
    while(step >= limit){
        while(err < 0.01){
            n += step;
            err = RelAbsError(SinApprox(n), sin(n));
        }
        n -= step;
        err = RelAbsError(SinApprox(n), sin(n));
        step *= .1;
    }

    cout << "Second order Taylor approximation of sin breaks down at " << n << " radians\n";
}



int main()
{
    SmallAngleApproxError();
    
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