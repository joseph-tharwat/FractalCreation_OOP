//To compile
//g++ *.cpp

#include <iostream>
#include "fractalCreator.h"
#include "RGB.h"

using namespace std;

int main()
{
    const int32_t width = 800;
    const int32_t height = 600;
    
    fractalCreator my_fractal(width, height);
    
    // my_fractal.addZoom(zoom(295, 202, 0.1));
    // my_fractal.addZoom(zoom(312, 304, 0.1));

    my_fractal.addRange(0.0, RGB(0,0,0));
    my_fractal.addRange(0.3, RGB(255,0,0));
    my_fractal.addRange(0.5, RGB(255,255,0));
    my_fractal.addRange(1.0, RGB(255,255,255));
    
    my_fractal.run("test.bmp");

    cout<<"Done"<<endl;

    return 0;
}