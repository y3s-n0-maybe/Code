#include <iostream>
#include <math.h>
#include <fstream>
#include <bits/stdc++.h>
#include "C:\Users\Owner\Desktop\Code\Second Year\Comp Phys\C++\gnuplot.cxx"
using namespace std;
string file_dir = "C:/Users/Owner/Desktop/Code/Second Year/Comp Phys/C++/Assignment 3/data1.dat";
ifstream infile(file_dir);

double CalculateB(double x[], double y[], int n){
    double sx = accumulate(x, x + n, 0);

    double sqx, sxy, sy = 0;

    for(int i = 0; i < n; i++){
        sy += y[i];
        sxy += x[i] * y[i];
        sqx += x[i] * x[i];
    }

    double b = (n * sxy - sx * sy) / (n * sqx - sx * sx);
    return b;
}


void best_fit_line(){
    if(infile.good()){
        cout << "\nFile read succesfully, good to go! \n";
    }
    else {
        cout << "\nFile not read succesfully. Check if file_dir is correct";
        return;
    } 

    int n = 21;
    double x[n];
    double y[n];
    double d, v;

    int i = 0;
    while(infile >> d >> v){
        x[i] = d;
        y[i] = v;
        i++;
    }   

    double b = CalculateB(x, y, n);
    double sy = 0;
    
    for(int i = 0; i < n; i++){
        sy += y[i];
    }

    double ym = sy / n;
    double xm = accumulate(x, x + n, 0) / n;

    double a = ym - (b * xm);

    double y_2[n] = {};
    for(int i = 0; i < n; i++){
        y_2[i] = a + b * x[i];
    }

    gnuplot_two_functions("Voltage vs Distance", "lp", "Voltage", "Distance", x, y, n, "data1.dat", x, y_2, n, "best fit");
}

int main(){
    best_fit_line();
}