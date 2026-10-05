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

void TwoDoubles() {
    double a, b;
    cout << "Input Two Doubles Please\n";
    cout << "A: ";
    cin >> a;
    cout << "\nB: ";
    cin >> b;

    if(a > b)
    {
        cout << a;
    }else{cout << b;}
}

int Factorial() { // loses accuracy above 12, floating point innacuracy to blame?
    int n;

    cout << "Integer: ";
    cin >> n;

    if(n < 0){
        cout << "Negative Integer";
    }else if (n > 16)
    {
        cout << "Integer Overflow"; // above 16 starts returning negative numbers
    }
    
    
    else{
    int prod = 1;

    for(int i = 2; i <= n; i++)
    {
        prod = prod * i;
    }

    cout << "Factorial of " << n << " is: " << prod;
    }

}

double fOfx(double x) {
    double y = (x*x*x) - (3 * (x*x)) + 3;
    return y;
}

double fpOfx(double x) {
    double y = (3 * x * x) - (6 * x);
    return y;
}

void PlotFunction() {
    double func[11] = {};
    double x[11] = {};

    for(int i = 0.0; i < 11; i++) {
        double n = i - 5.0;
        func[i] = fOfx(n);
        x[i] = n;
    }

    gnuplot_one_function("F(x)", "linespoints", "x", "y", x, func, 11);
    
}

double CentralDerivation(double x){
    double d = 0.01;
    
    double dy = 2*d;
    double dx = fOfx(x + d) - fOfx(x - d);

    double dxdy = dx / dy;
    double error = fpOfx(x) - dxdy;

    cout << "F'(x) @ " << x << " = " << dxdy;
    cout << "\nWith a true error of " << error << "\n";
}

double ForwardDerivation(double x){
    double d = 0.01;
    
    double dx = fOfx(x + d) - fOfx(x);

    double dxdy = dx / d;
    double error = fpOfx(x) - dxdy;

    cout << "F'(x) @ " << x << " = " << dxdy;
    cout << "\nWith a true error of " << error << "\n";
}

double BackwardDerivation(double x){
    double d = 0.01;
    
    double dx = fOfx(x) - fOfx(x - d);

    double dxdy = dx / d;
    double error = fpOfx(x) - dxdy;

    cout << "F'(x) @ " << x << " = " << dxdy;
    cout << "\nWith a true error of " << error << "\n";
}

void ErrorComparison(double x)
{
    double c_er, f_er, b_er;
    double d = 0.01;

    c_er = fpOfx(x) - ((fOfx(x + d) - fOfx(x - d))/(2*d));
    f_er = fpOfx(x) - ((fOfx(x + d) - fOfx(x))/d);
    b_er = fpOfx(x) - ((fOfx(x) - fOfx(x - d))/d);

    cout << "\n Central Approximation Error: " << c_er;
    cout << "\n Forward Approximation Error: " << f_er;
    cout << "\n Backward Approximation Error: " << b_er;


}

void Derivatives() {
    int n = 0;
    cout << "For What x? ";
    cin >> n;

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
            CentralDerivation(n);
            break;
        case 2:
            ForwardDerivation(n);
            break;
        case 3:
            BackwardDerivation(n);
            break;
        case 4:
            ErrorComparison(n);
            break;
    }}
}




int main() {
    int choice = 1;
    int n;
    while(choice != 0){
        cout << "\nWhich program would you like to run?\n";
        cout << "0. Quit\n";
        cout << "1. Bigger of two doubles \n";
        cout << "2. Factorial\n";
        cout << "3. Plot function \n";
        cout << "4. Derivatives & Errors of x \n";
        cin >> choice;

        switch(choice){
            case 0:
                return 0;
            case 1:
                TwoDoubles();
                break;
            case 2: 
                Factorial();
                break;
            case 3:
                PlotFunction();
            case 4: 
                Derivatives();
                break;
        }
    }
}