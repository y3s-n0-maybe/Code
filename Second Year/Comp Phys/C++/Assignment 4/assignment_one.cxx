#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

vector<vector<double>> A = {{13., 10., 1., 3.}, {4., 6., 8., 14.}, {7., 5., 2., 15.}, {9., 12., 16., 11.}};
vector<double> x;
vector<double> B = {111, 118, 114, 163};

int main(){
    for(int i = 0; i < 4; i++){
        double div = A[i][0];
        for(int j = 0; j < 4; j++){
            A[i][j] = A[i][j] / div;
        }
    }

    for(int i = 1; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            A[i][j] = A[i][j] - A[0][j];
        }
    }
    
    cout << A[1][0];

    /*div = 1. / A[1][0];
    for(int i = 1; i < 4; i++){
        A[1][i] = A[1][i] / div;
    }*/

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << A[i][j] << ", ";
        }
        cout << "\n";
    }
}


