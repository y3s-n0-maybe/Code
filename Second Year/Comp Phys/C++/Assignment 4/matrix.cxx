#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

// matrix stuff: 
const double tolerance = pow(10, -10);

class Matrix{
    private:
        int rows;
        int cols;
        vector<double> mat; // changing to 1d array as opposed to 2d, let's see if this fixes all my MANY issues HOLY FORKING SHIRTBALLS IT DID !!!!
    public:
        Matrix(vector<double> matrix, int row_size, int col_size);
        Matrix(int row_size, int col_size);

        int Rows(){
            return rows;
        }
        int Cols(){
            return cols;
        }

        void Add_Column(vector<double> B);
        vector<double> RemoveColumn(int);

        void Add_Row(vector<double>);
        vector<double> GetRow(int);
        vector<double> GetCol(int);

        void SetValue(int i, int j, double value);
        double GetValue(int i, int j);

        void Pivot(int upper_row, int lower_row);
        void LinearCombination(int changed, int unchanged, double n);
        Matrix Inverse();

        bool CheckSquare();
        void Print();

        Matrix operator*(Matrix);
        //Matrix operator+(Matrix);
        double& operator()(int, int);
};

double& Matrix::operator()(int i, int j){
    if(i < 0){
        i = rows + i;
    }
    if(j < 0){
        j = cols + j;
    }
    if(i >= rows){
        printf("Called %dth row when only %d rows exist\n", i, rows);
    }else if (j >= cols){
        printf("Called %dth column when only %d columns exist\n", j, cols);
    }else{
        return mat[i*cols + j];
    }
}

Matrix::Matrix(vector<double> matrix, int row_size, int col_size){
    mat = matrix;
    rows = row_size;
    cols = col_size;
}

Matrix::Matrix(int row_size, int col_size){
    rows = row_size;
    cols = col_size;
    mat.resize(row_size*col_size);

    for (int i = 0; i < rows; i++){ 
        for (int j = 0; j < cols; j++){
            SetValue(i, j, 0);
        }
        SetValue(i, i, 1);
    }
}

double Matrix::GetValue(int i, int j){
    if(i < 0){
        i = rows + i;
    }
    if(j < 0){
        j = cols + j;
    }
    if(i >= rows){
        printf("Called %dth row when only %d rows exist\n", i, rows);
        return NAN;
    }else if (j >= cols){
        printf("Called %dth column when only %d columns exist\n", j, cols);
        return NAN;
    }else{
        return mat[i*cols + j];
    }
    
}

void Matrix::SetValue(int i, int j, double value){
    if(i < 0){
        i = rows + i;
    }
    if(j < 0){
        j = cols + j;
    }
    if(i >= rows){
        printf("Called %dth row when only %d rows exist\n", i, rows);
    }else if (j >= cols){
        printf("Called %dth column when only %d columns exist\n", j, cols);
    }else{
        mat[i*cols + j] = value;
    }
}

void Matrix::Add_Column(vector<double> B){
    if(B.size() != rows){
        printf("\nvector is the wrong size\n");
        return;
    }

    cols++;

    for (int i = 0; i < rows; i++){
        mat.insert(mat.begin() + ((i + 1) * rows) + i, B[i]);
    }
}

vector<double> Matrix::GetCol(int col){
    vector<double> result;
    result.resize(rows);

    for (int i = 0; i < rows; i++){
        result[i] = GetValue(i, col);
    }

    return result;
}

void Matrix::Add_Row(vector<double> A){
    rows++;
    mat.insert(mat.end(), A.begin(), A.end());
}

vector<double> Matrix::GetRow(int row){
    vector<double> result;
    result.resize(cols);

    for (int i = 0; i < cols; i++){
        result[i] = GetValue(row, i);
    }
    
    return result;
}

bool Matrix::CheckSquare(){
    if(rows == cols){
        return true;
    }else{
        return false;
    }
}

void Matrix::LinearCombination(int changed, int unchanged, double n){
    for (int i = 0; i < cols; i++)
    {
        SetValue(changed, i, GetValue(changed, i) + n*GetValue(unchanged, i));
        if (fabs(GetValue(changed, i)) < tolerance)
        {
            SetValue(changed, i, 0);
        }
        
    }
    
}

void Matrix::Print(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%-10g", GetValue(i,j));
        }
    cout << "\n";
    }
}

Matrix UpperTriangle(Matrix A){ 
    double div;

    for (int i = 0; i < A.Rows(); i++){
        for (int n = i+1; n < A.Rows(); n++){
            div = -(A.GetValue(n,i) / A.GetValue(i, i));
            A.LinearCombination(n, i, div);        
        }
    }
    return A;
}

vector<Matrix> ULDecomp(Matrix A){ // returns a vector of two matrices, the upper & the lower. 
    Matrix ut = A;
    Matrix lt(ut.Rows(), ut.Cols());

    double div;
    double div_list[(ut.Rows() * (ut.Rows() - 1) )/ 2];

    for (int i = 0; i < ut.Rows(); i++){
        for (int n = i+1; n < ut.Rows(); n++){
            div = -(ut.GetValue(n,i) / ut.GetValue(i, i));
            ut.LinearCombination(n, i, div);
            lt.SetValue(n, i, -div);
        }
    }

    vector<Matrix> result = {ut, lt};
    return result;
}

double Determinant(Matrix A){
    if(A.CheckSquare() == false){
        cout << "Matrix not square";
        return NAN;
    }

    A = UpperTriangle(A);
    
    double sum = 1.;

    for(int n = 0; n < A.Rows(); n++){
        sum *= A.GetValue(n, n);
    }

    return sum;
}

vector<double> UpperSolve(Matrix ut, vector<double> b){
    vector<double> x;
    double val;
    int rows = ut.Rows();
    x.resize(rows);

    for(int i = rows-1; i > -1; i--){
        val = b[i];
        for(int j = i+1; j < rows; j++){
            val -= ut.GetValue(i, j) * x[j];
        }
        x[i] =  val / ut.GetValue(i, i);
    }

    return x;
}

vector<double> LowerSolve(Matrix lt, vector<double> b){
    vector<double> x;
    double val;
    int rows = lt.Rows();
    x.resize(rows);

    for(int i = 0; i < rows; i++){
        val = b[i];
        for(int j = i; j > -1; j--){
            val -= lt.GetValue(i, j) * x[j];
        }
        x[i] =  val / lt.GetValue(i, i);
    }

    return x;
}


void Matrix::Pivot(int upper_row, int lower_row){
    vector<double> upper, lower;
    upper.resize(cols);
    lower.resize(cols);

    for (int i = 0; i < cols; i++)
    {   
        upper[i] = GetValue(upper_row, i);
        lower[i] = GetValue(lower_row, i);

        SetValue(upper_row, i, lower[i]);
        SetValue(lower_row, i, upper[i]);
    }
        
}
vector<double> Matrix::RemoveColumn(int col){
    vector<double> x;
    x.resize(Rows());

    for(int i = Rows()-1; i > -1; i--){
        x[i] = GetValue(col, i);
        mat.erase(mat.begin() + (i*cols + col));
    }

    cols --;

    return x;
}

Matrix Matrix::operator*(Matrix B){ // tested, works :D
    Matrix prod(Rows(), B.Cols());
    if(Rows() == B.Rows()){
        int i,j,k;
        double sum;
        for (i = 0; i < Rows(); i++)
        {
            for (j = 0; j < B.Cols(); j++)
            {
                sum = 0;
                for (k = 0; k < Cols(); k++)
                {
                    sum += GetValue(i, k) * B(k,j);
                }
                if(fabs(sum) > tolerance){
                    prod(i,j) = sum;
                }else{
                    prod(i, j) = 0;
                }
            }
        }
        return prod;
    }
    else{
        printf("Matricies Incompatible");
    }
}

Matrix Matrix::Inverse(){
    
    vector<Matrix> result = ULDecomp(*this);
    Matrix ut = result[0];
    Matrix lt = result[1];

    Matrix Inv(Rows(), Cols());

    vector<double> C;
    C.resize(Rows());

    for(int i = 0; i < Rows(); i++){
        fill(C.begin(), C.end(), 0);
        C[i] = 1;

        vector<double> z = LowerSolve(lt, C);
        vector<double> x = UpperSolve(ut, z);

        for (int j = 0; j < Cols(); j++){
            Inv.SetValue(j, i, x[j]);
        }   
    }
    return Inv;
}

vector<double> ULSolving(Matrix A, vector<double> B){
    vector<Matrix> result = ULDecomp(A);
    Matrix ut = result[0];
    Matrix lt = result[1];

    B = LowerSolve(lt, B);
    B = UpperSolve(ut, B);

    return B;
}

vector<double> GaussianElimination(Matrix A, vector<double> B){
    A.Add_Column(B);
    A = UpperTriangle(A);

    B = A.RemoveColumn(4);
    B = UpperSolve(A, B);

    return B;
}