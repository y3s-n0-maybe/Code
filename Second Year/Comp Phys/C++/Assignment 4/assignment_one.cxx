#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// matrix stuff: 

class Matrix{
    public:
        int rows;
        int cols;
        vector<vector<double>> mat;

        Matrix(vector<vector<double>> matrix, int row_size, int col_size){
            mat = matrix;
            rows = row_size;
            cols = col_size;
        }

        double Address(int i, int j){
            if(i >= rows || i < 0){
                printf("Called %dth row when only %d rows exist", i, rows);
                return 0;
            }else if (j >= cols || j < 0){
                printf("Called %dth column when only %d columns exist", j, cols);
                return 0;
            }else{
                return mat[i][j];
            }
            
        }

        void RowAddition(int changed, int unchanged, double n){
            for (int i = 0; i < cols; i++)
            {
                mat[changed][i] = Address(changed, i) + n*Address(unchanged, i);
            }
            
        }

        void Print(){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    printf("%-15g", mat[i][j]);
                }
            cout << "\n";
            }
        }

        void Add_Column(vector<double> B){
            for(int i = 0; i < rows; i++){
                mat[i].resize(cols);
                mat[i][cols] = B[i];
            }
            cols ++;
        }

        double Determinant();
        void UpperTriangify();

};

void Matrix::UpperTriangify(){
    double div;

    for (int i = 0; i < rows; i++){
        for (int n = i+1; n < rows; n++){
            div = -(Address(n,i) / Address(i, i));
            cout << div << "\n";
            RowAddition(n, i, div);
            Print();
            cout << "\n";
        }
        
    }
    
    
}

double Matrix::Determinant(){
    if(rows != cols){
        cout << "Matrix not square";
        return 0;
    }

    UpperTriangify();
    
    double sum = 1.;

    for(int n = 0; n < rows; n++){
        sum *= Address(n, n);
    }

    return sum;
}

// matrix stuff dones

void GaussianElimination(Matrix A, vector<double> B){
    int rows = A.rows;
    A.Add_Column(B);
    int cols = A.cols;

    cout << "\n---------- Matrix ----------\n";
    A.Print();

    double div;

    A.UpperTriangify();

        for(int n = 0; n < rows; n++){
        div = A.Address(n, n); // diaganol value of n
        for(int i = n; i < cols; i++){
            A.mat[n][i] = A.Address(n, i) / div; // sets row n to have its nth value equal to 1
        }
    }

    cout << "\n---------- Upper Triangle Matrix ----------\n";
    A.Print();

    for(int n = 3; n > 0; n--){
        for(int i = 0; i < n ; i ++){
            div = A.mat[i][n];
            A.mat[i][n] = 0;
            A.mat[i][4] = A.mat[i][4] - div*A.mat[n][4];
        }
    }

    cout << "\n---------- Solved Matrix ----------\n";
    A.Print();
}


int main(){
    vector<double> Bm = {111, 118, 114, 163};
    vector<vector<double>> A_vector = {{13., 10., 1., 3.}, {4., 6., 8., 14.}, {7., 5., 2., 15.}, {9., 12., 16., 11.}};
    Matrix Am(A_vector, 4, 4);

    //GaussianElimination(Am, Bm);
    printf("%g", Am.Determinant());
    return 0;
}