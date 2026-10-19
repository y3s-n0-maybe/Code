#include <iostream>
#include <math.h>
using namespace std;

double root1 = -1.05439;
double root2 = 6.26269;

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

double fx(double x){
    double y = -pow(x, 4) + (7 * pow(x, 3)) - (5 * pow(x, 2)) + 15;
    return y;
}

double gx(double x){
    double y = -(0.2 * pow(x, 5)) + (1.75 * pow(x, 4)) - ((5. / 3.) * pow(x, 3)) + (15 * x);
    return y; 
}

double integral = gx(root2) - gx(root1);

double Simpsons(double (*f)(double), double start, double finish, int n){
    double h = (finish - start)/ n;
    double sum = f(start) + f(finish);
    double x[n] = {};

    for(int i = 0; i <= n; i++){
        x[i] = start + i*h;
    }

    for(int i = 1; i < n; i += 2){
        sum += 4 * f(x[i]);
    }

    for(int i = 2;  i < n; i += 2){
        sum += 2 * f(x[i]);
    }

    sum *= (h / 3.);
    return sum;
}

double ErrorComparisons(){
    for(int i = 2; i < 6; i++){
        cout << "\nError of Simpsons @ n = " << pow(2, i) << ": ";
        cout << Error(Simpsons(fx, root1, root2, pow(2, i)), integral, "");
    }
}

int main(){
    ErrorComparisons();
}