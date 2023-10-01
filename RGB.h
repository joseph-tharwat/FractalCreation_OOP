

#ifndef RGB_H
#define RGB_H

#include <iostream>

class RGB
{
public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
public:
    RGB(uint8_t r, uint8_t g, uint8_t b);

    RGB operator-(RGB second);
    // {
    //     return RGB(this->red - second.red, this->green - second.green, this->blue - second.blue);
    // }

    ~RGB();
};





#endif
