
#include "RGB.h"

RGB::RGB(uint8_t r, uint8_t g, uint8_t b): red(r), green(g), blue(b)
{

}

RGB RGB::operator-(RGB second)
{
   return RGB(this->red - second.red, this->green - second.green, this->blue - second.blue);
}

RGB::~RGB()
{
}