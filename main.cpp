//To compile
//g++ main.cpp bitmap.cpp

#include <iostream>
#include "fractalCreator.h"
using namespace std;

int main()
{
    const int32_t width = 800;
    const int32_t height = 600;
    
    fractalCreator my_fractal(width, height);
    
    my_fractal.addZoom(zoom(width/2, height/2, 4.0/width));
    my_fractal.addZoom(zoom(500, 200, 0.5));

    my_fractal.calculateIterations();
    my_fractal.calculateTotal();
    my_fractal.drawFractal();
    my_fractal.writeBitmap("test.bmp");

    cout<<"Done"<<endl;

    return 0;
}