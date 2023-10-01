
#ifndef FRACTAL_CREATOR_H
#define FRACTAL_CREATOR_H

#include "bitmap.h"
#include "mandelbrot.h"
#include "zoomList.h"
#include "zoom.h"


class fractalCreator
{
private:
    int m_width;
    int m_height;
    bitmap m_image;
    uint32_t *m_histogram;
    uint32_t *m_fractal;
    zoomList m_zoomList;
    uint32_t m_total{0};
public:
    fractalCreator(int width, int height);
    void run(string name);
    void addZoom(zoom z);
    void calculateIterations();
    void calculateTotal();
    void drawFractal();
    void writeBitmap(string name);
    ~fractalCreator();
};




#endif