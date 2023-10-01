

#ifndef BITMAP_H
#define BITMAP_H

#include"bitmapHeader.h"
#include <string.h>
#include <iostream>
#include <memory>
using namespace std;

class bitmap
{
private:
    uint32_t m_width;
    uint32_t m_height;
    uint32_t m_size;
    uint8_t* m_pPixels;

public:
    bitmap(uint32_t width, uint32_t hright);
    void setPixel(uint32_t x, uint32_t y, uint8_t red, uint8_t green, uint8_t blue);
    void write(string bitmapName);
    
    ~bitmap();
};


#endif