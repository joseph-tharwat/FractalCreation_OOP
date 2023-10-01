//To compile
//g++ *.cpp

#include <iostream>
#include "fractalCreator.h"
#include "RGB.h"

using namespace std;

int main()
{
    RGB rgb1(10,20,30);
    RGB rgb2(20,30,40);
    RGB rgb3 = rgb2 - rgb1;
    cout<<(int)rgb1.red<<","<<(int)rgb1.green<<","<<(int)rgb1.blue<<endl;
    cout<<(int)rgb2.red<<","<<(int)rgb2.green<<","<<(int)rgb2.blue<<endl;
    cout<<(int)rgb3.red<<","<<(int)rgb3.green<<","<<(int)rgb3.blue<<endl;

    const int32_t width = 800;
    const int32_t height = 600;
    
    fractalCreator my_fractal(width, height);
    
    my_fractal.addZoom(zoom(295, 202, 0.1));
    // my_fractal.addZoom(zoom(312, 304, 0.1));

    my_fractal.run("test.bmp");

    cout<<"Done"<<endl;

    return 0;
}