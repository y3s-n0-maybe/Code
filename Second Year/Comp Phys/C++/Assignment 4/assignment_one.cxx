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




vector<double> Bm = {111, 118, 114, 163};
vector<vector<double>> Am = {{13., 10., 1., 3.}, {4., 6., 8., 14.}, {7., 5., 2., 15.}, {9., 12., 16., 11.}};

void PrintMatrix(vector<vector<double>> x, int rows, int cols){ // made this to print matrices but it only ever works hte first time its called
    for(int i = 0; i < rows; i++){
        cout << "|";
        for(int j = 0; j < cols; j++){
            if(j == cols - 1){
                cout << "| ";
            }
            printf("%-10g", x[i][j]);
        }
        cout << "\n";
    }
}


void GaussianElimination(vector<vector<double>> A, vector<double> B, int rows, int cols){
    for(int i = 0; i < rows; i++){
        A[i].resize(cols);
        A[i][cols] = B[i];
    }
    
    cols ++;

    cout << "\n---------- Matrix ----------\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(j == cols - 1){
                cout << "| ";
            }
            printf("%-10g", A[i][j]);
        }
        cout << "\n";
    }

    double div;

    for(int n = 0; n < rows; n++){
        div = A[n][n]; // diaganol value of n
        for(int i = n; i < cols; i++){
            A[n][i] = A[n][i] / div; // sets row n to have its nth value equal to 1
        }

        for(int i = n+1; i < rows; i ++){
            div = A[i][n]; // holds nth value of ith row
            for(int j = n; j < cols; j++){
                A[i][j] = A[i][j] - div*A[n][j]; 
            }
        }
    }

    cout << "\n---------- Upper Triangle Matrix ----------\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(j == cols - 1){
                cout << "| ";
            }
            printf("%-10g", A[i][j]);
        }
        cout << "\n";
    }

    for(int n = 3; n > 0; n--){
        for(int i = 0; i < n ; i ++){
            div = A[i][n];
            A[i][n] = 0;
            A[i][4] = A[i][4] - div*A[n][4];
        }
    }

    cout << "\n---------- Solved Matrix ----------\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(j == cols - 1){
                cout << "| ";
            }
            printf("%-10g", A[i][j]);
        }
        cout << "\n";
    }
}

int main(){
    GaussianElimination(Am, Bm, 4, 4);
}