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
    double error = value - approx;

    if(type.find("abs") != std::string::npos || type.find("ABS") != std::string::npos || type.find("Abs") != std::string::npos){
        error = fabs(error); // if type contains abs function will return the absolute error
    }

    if(type.find("rel") != std::string::npos || type.find("REL") != std::string::npos || type.find("Rel") != std::string::npos){
        error = error / value; // if type contains rel the function will return the relative error
    }

    return error;
}

double DerivationApprox(double x, double d, double (*func)(double), string method){
    double dx;

    if(method == "central"){
        dx = func(x + d) - func(x - d);
        d *=2;
    }
    if(method == "forward"){
      dx = func(x + d) - func(x);  
    }
    if(method == "backward"){
        dx = func(x) - func(x - d);
    }

    double dxdy = dx / d;

    return dxdy;
}

double PolylogarithmApproximation(double s, double z, double n){ // Polylog of order s, argument z \& steps n; approximation for the polylogarithm (necessary for some integrals)
    double sum = 0;
    for(int k = 1; k <= n; k++){
        sum += (pow(z, k)) / (pow(k, s));
    }
    return sum;
}

double fx(double x) {
    double y = 1 + (x*x) - x ;
    return y;
}

double fpx(double x) {
    double y = (2 * x) - 1;
    return y;
}

double gx(double x){
    double y = (300 * x)/(1 + exp(x));
    return y;
}

double IntegralGx(double x) {
    double y = (300 * (PolylogarithmApproximation(2, -exp(-x), 10))) - (x * log(exp(-x) + 1));
    return y;
}

double EvaluatedIgx(double a, double b){
    double sum = IntegralGx(b) - IntegralGx(a);
    return sum;
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

void ErrorComparison(double x, double d, string type)
{
    double c_er = Error(fpx(x), DerivationApprox(x, d, fx, "central"), type);
    double f_er = Error(fpx(x), DerivationApprox(x, d, fx, "forward"), type);
    double b_er = Error(fpx(x), DerivationApprox(x, d, fx, "backward"), type);

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
            cout << DerivationApprox(n, d, fx, "central");
            break;
        case 2:
            cout << "Forward approximation of F'(x) at x = " << n << " with a dx of " << d << " = ";
            cout << DerivationApprox(n, d, fx, "forward");
            break;
        case 3:
            cout << "Backward approximation of F'(x) at x = " << n << " with a dx of " << d << " = ";
            cout << DerivationApprox(n, d, fx, "backward");
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

double IntegralApproximation(double a, double b, int n, double (*func)(double)){
    double h = (b - a) / n;
    double y = 0;

    for(double i = 0; i <= n; i++){
        y += h * ((func(a + (i * h)) + func(a + ((i+1) * h))) / 2 );
    }
    return y;
}

void Integrals(double a, double b, int n){
        
    cout << "Approx: " << IntegralApproximation(a, b, n, gx) << "\n";
    cout << "Eval: " << EvaluatedIgx(a, b) << "\n";
    cout << "Error: " << Error(IntegralApproximation(a, b, n, gx), EvaluatedIgx(a, b), "absolute, relative") * 100 << "\%";
}

int main()
{

    Integrals(0, 10, 100);

    /*
    int choice = 1;

    while(choice != 0){
        cout << "\nWhich function would you like to run? \n";
        cout << "0. Quit \n";
        cout << "1. Small Angle Approximation \n";
        cout << "2. Derivatives \n";
        cout << "3. Integrals \n";

        cin >> choice;

        switch(choice){
            case 0:
                break;
            case 1:
                SmallAngleApproxError();
                break;
            case 2:
                Derivatives();
                break;
            case 3:
                Integrals();
                break;
            default: 
                cout << "\nInvalid Choice.\n";
        }
    }*/
    return 0;
}