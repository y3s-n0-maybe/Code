#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <algorithm>
#include "gnuplot.cxx"
#include <fstream>
using namespace std;
string file_dir = "C:/Users/Owner/Desktop/Code/Second Year/Comp Phys/Junk Drawer/dice.dat";
// ^^ will need to be changed if running on different machine
std::ifstream infile(file_dir);

double modulo(double a, double b)
{
    int i = a / b;
    return a - i * b;
}

double mean(double arr[], int length){
    double sum = 0;
    for(int i = 0; i < length; i++){
        sum += arr[i];
    }

    double avg = sum/length;
    return avg;
}

double stdev(double arr[], int length){
    double avg = mean(arr, length);
    double dev_sum = 0;
    for(int i = 0; i < length; i++){
        dev_sum += pow((arr[i] - avg), 2);
    }

    double stand_dev = pow(dev_sum / (length - 1), .5);
    return stand_dev;
}

double median(double arr[], int length){
    std::sort(arr, arr+length);

    int len = length/2;
    double med;

    if(length % 2 == 0){
        med = (arr[len] + arr[len - 1])/2;
    }else if (length % 2 == 1)
    {
        med = arr[len];
    }

    return med;
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

void sum_prod() {
    double a,b,c = 0.0;

    cout << "A = ";
    cin >> a; 
    cout << "B = ";
    cin >> b;
    cout << "C = ";
    cin >> c;

    cout << "\nSum = " << a + b + c << "\nProduct = " << a*b*c << "\n";
}

void double_to_bin() {
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
    
    cout << "\nBinary Form: "  << dec_str + "." + frac_str << "\n";
}

void bin_to_double() {
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
    cout << "\nDecimal Form: " << decimal << "\n";
}

void delays(){
    int arr_length = 10;
    double delays[arr_length] = {4, 10, 12, 55, 22, 15, 8, 7, 9, 8};
    int i = 0;

    double avg = mean(delays, arr_length);

    double stand_dev = stdev(delays, arr_length);

    cout << "\nMean: " << avg << "\nStandard Deviation: " << stand_dev << "\n";

    double day[arr_length] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    gnuplot_one_function ("220 Delays","linespoints", "Day", "minutes delayed", day, delays, arr_length);
}

void dice_calc(){
    if(infile.good()){
        cout << "\nFile read succesfully, good to go!";
    }
    else {
        cout << "\nFile not read succesfully. Check if file_dir is correct";
        return;
    } 

    int len = 40;
    double exp[len];
    double res[len];
    double a, b;

    int i = 0;
    while(infile >> a >> b){
        exp[i] = a;
        res[i] = b;
        i++;
    }

    string s;

    cout << "\nMean: " << mean(res, len) << "\nMedian: " << median(res, len) << "\nStandard Deviation: " << stdev(res, len) << "\n";
}


int main() {
    int choice = 0;

    while(choice != 6){
        choice = 0;
        
        cout << "\nWhich function would you like to run? \n";
        cout << "1. Sum & Product of 3 Doubles \n";
        cout << "2. Convert a double to a binary number \n";
        cout << "3. Convert a binary number to a double \n";
        cout << "4. Calculate mean & stdev of delays \n";
        cout << "5. Calculate mean, median, & stdev of 2d6 rolls\n";
        cout << "6. End Program\n";

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
            case 5:
                dice_calc();
                break;
            case 6:
                cout << "\nThank you! Stopping program.\n";
                return 0;
            default: 
                cout << "\nInvalid Choice.\n";
        }
    }

}