
#include "mandelbrot.h"
#include <complex>
mandelbrot::mandelbrot()
{
}

mandelbrot::~mandelbrot()
{
}

int mandelbrot::getIterations(double x, double y)
{
    complex<double> c(x, y);
    complex<double> z = 0;
    uint32_t iterationsCount = 0;
    while(abs(z) <=2 && iterationsCount < MAX_ITERATIONS)
    {
        z = z*z + c;
        iterationsCount++;
    }
    return iterationsCount;
}


// int mandelbrot::getIterations(double x, double y) {

// 	complex<double> z = 0;
// 	complex<double> c(x, y);

// 	int iterations = 0;

// 	while(iterations < MAX_ITERATIONS) {
// 		z = z*z + c;

// 		if(abs(z) > 2) {
// 			break;
// 		}

// 		iterations++;
// 	}

// 	return iterations;
// }

