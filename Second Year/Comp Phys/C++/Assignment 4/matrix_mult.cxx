#include "matrix.cxx"
#include <stdio.h>
#include <iostream>

int main(){
    Matrix A({13, 4, 7, 9, 10, 6, 5, 12, 1, 8, 2, 16, 3, 14, 15, 11}, 4, 4);
    Matrix ident(4, 4);
    vector<Matrix> why = ULDecomp(A);
    Matrix ut = why[0];
    Matrix lt = why[1];

    Matrix bingus = lt * ut;
    bingus.Print();
}