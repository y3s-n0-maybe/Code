#include <iostream>
#include <math.h>
#include "C:\Users\Owner\Desktop\Code\Second Year\Comp Phys\C++\gnuplot.cxx"
using namespace std;

double true_root = acos(0.25);
double tolerance = pow(10, -8);

double Error(double approx, double value, string type){ // future proofing in case we are asked for more errors 
    double error = value - approx;

    if(type.find("abs") != std::string::npos || type.find("ABS") != std::string::npos || type.find("Abs") != std::string::npos){
        error = fabs(error); // if type contains abs function will return the absolute error
    }

    if(type.find("rel") != std::string::npos || type.find("REL") != std::string::npos || type.find("Rel") != std::string::npos){
        error = (error / value) * 100; // if type contains rel the function will return the relative error
    }

    return error;
}


double Bisection(double (*f)(double), double x_lower, double x_upper, double tolerance, double max_iter){
    double x_mid = (x_lower + x_upper)/2;
    int n = 0;

    while(abs(f(x_mid)) > tolerance && n < max_iter){
        n++;

        if(f(x_lower) * f(x_upper) < 0){
            x_mid = (x_lower + x_upper)/2;
            double prod = f(x_mid) * f(x_upper);
            
            if(prod < 0){
                x_lower = x_mid;
            }
            else if (prod > 0){
                x_upper = x_mid;
            }
            else if(prod = 0){
                break;
            }
        }
        else{
            //cout << "Starting values do not bisect 0";
            break;
        }
    }

    return x_mid;
}

double NewtonRaphson(double (*f)(double), double (*fp)(double), double x, double tolerance, double max_iter){
    double n = 0;

    while((f(x) > tolerance || f(x) < (0-tolerance)) && n <= max_iter){
        n++;
        x = x - (f(x)/fp(x));
    }
    return x;
}

double Secant(double (*f)(double), double x1, double x2, double tolerance, double max_iter){
    double n = 0;

    while((f(x2) > tolerance || f(x2) < (0-tolerance)) && n < max_iter){
        n++;

        double new_x = x2 - ((f(x2) * (x2 - x1)) / (f(x2) - f(x1)));
        x1 = x2;
        x2 = new_x;
    }

    return x2;
}

double fx(double x){
    double y = cos(x) - 0.25;
    return y;
}

double gx(double x){
    double y = (x*x*x) - (6*x*x) - x + 10;
    return y;
}

double fpx(double x){
    double y = - sin(x);
    return y;
}
double gpx(double x){
    double y = (3*x*x) - (12 * x) - 1;
    return y;
}

void Iterate(){
    double true_root = acos(0.25);
    double tolerance = pow(10, -8);
    double roots[3] = {};
    double abs_err[3] = {};
    double rel_err[3] = {};
    double x_a = M_PI_2;

    for(int i = 0; i <= 20; i++){
        roots[0] = Bisection(fx, 0, x_a, tolerance, i);
        roots[1] =  Secant(fx, 0, x_a, tolerance, i);
        roots[2] =  NewtonRaphson(fx, fpx, x_a, tolerance, i);
        
        for(int n = 0; n < 3; n++){
            abs_err[n] = Error(roots[n], true_root, "abs");
            rel_err[n] = Error(roots[n], true_root, "abs rel");
        }

        string speech[3] = {"\nBisection Method: ", "\nSecant Method: ", "\nNewton Ralphson Method: "};

        cout << "\nFor Iteration " << i <<": \n";
        for(int n = 0; n < 3; n++){
            cout << speech[n];
            cout << "Root: " << roots[n] << ", ";
            cout << "Absolute Error: " << abs_err[n] << ", ";
            cout << "Relative Error: " << rel_err[n] << "%";
        }
        cout << "\n";
    }
}

void ErrorComparison(){
    
    double x_a = M_PI_2;

    double roots[3] = {};
    double x_arr[21] = {};
    double err[3] = {};

    double error_quot_bi[21], error_quot_se[21], error_quot_nr[21] = {};
    double eps_zero[3] = {Error(Bisection(fx, 0, x_a, tolerance, 0), true_root, ""), Error(Secant(fx, 0, x_a, tolerance, 0), true_root, ""), Error(NewtonRaphson(fx, fpx, x_a, tolerance, 0), true_root, "")};

    for(int i = 0; i <= 20; i++){
        x_arr[i] = i;

        roots[0] = Bisection(fx, 0, x_a, tolerance, i);
        roots[1] =  Secant(fx, 0, x_a, tolerance, i);
        roots[2] =  NewtonRaphson(fx, fpx, x_a, tolerance, i);
        
        for(int n = 0; n < 3; n++){
            err[n] = Error(roots[n], true_root, "");
        }

        string speech[3] = {"\nBisection Method: ", "\nSecant Method: ", "\nNewton Ralphson Method: "};

        error_quot_bi[i] = log(fabs(err[0] / eps_zero[0]));
        error_quot_se[i] = log(fabs(err[1] / eps_zero[1]));
        error_quot_nr[i] = log(fabs(err[2] / eps_zero[2]));
    }

    gnuplot_one_function("Bisection Method", "linespoints", "Iteration", "Logarithmic Ratio of Errors", x_arr, error_quot_bi, 20);
    gnuplot_one_function("Secant Method", "linespoints", "Iteration", "Logarithmic Ratio of Errors", x_arr, error_quot_se, 20);
    gnuplot_one_function("Newton Raphson Method", "linespoints", "Iteration", "Logarithmic Ratio of Errors", x_arr, error_quot_nr, 20);
}


int main(){

    cout << "-------------------------------------------------------------------------\n";
    cout << "Iteration through various methods of finding a root, from n = 0 to n = 20\n";
    cout << "-------------------------------------------------------------------------\n";

    Iterate();

    cout << "------------------------------------------------------------------\n";
    cout << "Ratio of error @ n and error at 0 iterations, from n = 0 to n = 20\n";
    cout << "------------------------------------------------------------------\n";

   ErrorComparison();

   cout << "\nProgram Complete. Enjoy Reading the console ouput :D";
}