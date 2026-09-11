#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string>
#include "C:\Users\Owner\Desktop\Headers\gnuplot-iostream"
using namespace std;

double modulo(double a, double b)
{
    int i = a / b;
    return a - i * b;
}

string int_to_bin(int n) {
    int quot = 0;
    int rem = 0;

    string rem_str = "";
    string bin = "";

    while (n != 0)
    {
        quot = n/2;
        rem = n % 2;

        if (rem == 1)
        {
           rem_str = "1";
        } else rem_str = "0";

        bin = rem_str + bin;
        n = quot;
    }
    
    return bin;
}

int sum_prod() {
    double a,b,c = 0.0;

    cout << "A = ";
    cin >> a; 
    cout << "B = ";
    cin >> b;
    cout << "C = ";
    cin >> c;

    cout << "Sum = " << a + b + c << "\nProduct = " << a*b*c;

    return 0;
}

int double_to_bin() {
    double dec = 0.0;
    int sigfig = 0;
    double frac = 0;
    string dec_str = "";
    string frac_str = "";

    cout << "Decimal: ";
    cin >> dec;

    if(dec >= 1000000000) {
        cout << "You're gonna be here a while. \n";
    }

    double n = dec;
    while (modulo(n, 1) != 0){
        n = n * 10;
        sigfig++;
    }

    frac = modulo(dec, 1);
    // frac = int(frac_double);

    //cout <<"\n Modulo: " << modulo(dec, 1) << "\n Sig Figs:" << sigfig << "\n DFrac: " << frac_double << "\n IFrac: " << frac;


    dec_str = int_to_bin(dec);

    int i = 0;
    while((frac != 0) || (i >= 100)){
        frac = frac * 2;
        if(frac >= 1) {
            frac_str = frac_str + "1";
        }else frac_str = frac_str + "0";
        frac = modulo(frac, 1);
        i ++;
    }
    
    cout << "\nBinary Form: "  << dec_str + "." + frac_str;
    return 0;
}

int bin_to_double() {
    string binary = "";
    char c_sux = '.';
    double decimal = 0;

    cout << "Binary Number: ";
    cin >> binary;

    int dp = 0;

    bool torf = false;
    for(dp = 0; (dp < binary.length())&&(torf == false); dp++){
        if (binary[dp+1] == '.'){
            binary.erase(dp+1, 1);
            torf = true; 
        }
    }

    if (torf == false) {
        dp = binary.length();
    }
    
    int i = 0;
    while(i <= binary.length()) {
        if (binary[i] == '1') {
            decimal +=  pow(2,(dp - (i+1)));
        }
        
        i++;
    }
    cout << "\nDecimal Form: " << decimal;
    return 0;
}

int delays(){
    int arr_length = 10;
    int delays[arr_length] = {4, 10, 12, 55, 22, 15, 8, 7, 9, 8};
    
    double sum = 0;
    for(int i = 0; i < arr_length; i++){
        sum += delays[i];
    }

    double avg = sum/arr_length;
    cout << avg;

}


int main() {
    // delays();
    // /*
    int choice = 0;
    cout << "Which function would you like to run? \n1. Sum & Product of 3 Doubles \n2. Convert a double to a binary number \n3. Convert a binary number to a double \n";
    cin >> choice;
    switch(choice){
        case 1:
            sum_prod();
            break;
        case 2:
            double_to_bin();
            break;
        case 3:
            bin_to_double();
            break;
        case 4:
            delays();
            break;
        default: 
            cout << "Invalid Choice. Please run again.";
    }
    // */
    return 0;
}