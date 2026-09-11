/*
  PY 2105: Introduction in Computational Physics

  Example 1.6: Plot
*/

// Header

#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
using namespace std;
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "gnuplot.cxx"


// Declaration of constants and assigning values

const int number_points = 20; // Numer of Points in plot


// Main program

int main ()
{
  //Declaration of variables	
  double x [number_points]; // Array of x values of plot
  double y [number_points]; // Array of y values of plot

  double x_min; // Minimal x value of plot
  double x_max; // Maximal x value of plot
  double delta_x; // Stepsize
  int nr;

  // Set parameter of plot
  x_min = 0.0;
  x_max = 1.0;
  delta_x = (x_max - x_min) / (number_points-1.0);

  cout << "x_min = " << x_min << ", x_max= " << x_max << ", delta_x = " << delta_x << "\n",

  // Calculate values of a and y array
  nr = 0;
  while (nr < number_points)
    {
      x [nr] = x_min + delta_x * nr;
      y [nr] = x[nr] * x[nr];
      nr = nr + 1;
    }

  // Plot x and y arrays
  cout << "Plot f(x) = x*x!\n";
  gnuplot_one_function ("First plot","linespoints", "x", "y", x, y, number_points);
  
  return 0;
}
