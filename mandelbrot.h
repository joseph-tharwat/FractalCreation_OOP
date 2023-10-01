
#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <iostream>
using namespace std;

class mandelbrot
{
public:
    static const uint32_t MAX_ITERATIONS = 1000;
public:
    mandelbrot();
    static int getIterations(double x, double y);
    ~mandelbrot();
};


#endif