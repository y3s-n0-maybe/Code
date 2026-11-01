#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "matrix.cxx"
using namespace std;

vector<double> vec_x = {0, 0, 0, 0};
vector<double> vec_b = {111, 118, 114, 163};
vector<double> vec_a = {13, 4, 7, 9, 10, 6, 5, 12, 1, 8, 2, 16, 3, 14, 15, 11};
Matrix mat_a(vec_a, 4, 4);

vector<double> GaussianEliminationPrints(Matrix A, vector<double> B){
    A.Add_Column(B);
    A = UpperTriangle(A);
    printf("\nUpper Triangle with B vector\n");
    A.Print();

    B = A.RemoveColumn(4);
    B = UpperSolve(A, B);

    return B;
}

vector<double> ULSolvingPrints(Matrix A, vector<double> B){
    vector<Matrix> result = ULDecomp(A);
    Matrix ut = result[0];
    Matrix lt = result[1];
    printf("\nUpper Triangle Matrix: \n");
    ut.Print();
    printf("\nLower Triangle Matrix: \n");
    lt.Print();

    B = LowerSolve(lt, B);
    B = UpperSolve(ut, B);

    return B;
}

void AssignmentRequirements(){
    vector<double> x = GaussianEliminationPrints(mat_a, vec_b);

    printf("\nSolution Vector (Gaussian): ");
    for(double i : x){
        cout << i << ", ";
    }

    printf("\nDeterminant: %g\n", Determinant(mat_a));

    vec_x = ULSolvingPrints(mat_a, vec_b);

    printf("\nSolution Vector (UL Decomp): ");
    for(double i : vec_x){
        printf("%g, ", i); 
    }


    printf("\nInverse of A: \n");
    Matrix Inv = mat_a.Inverse();
    Inv.Print();
}

int main(){
    AssignmentRequirements();

    return 0;
}