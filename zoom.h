
#ifndef ZOOM_H
#define ZOOM_H


struct zoom 
{
    int x{0};
    int y{0};
    double scale{1};
    zoom(int xx, int yy, double scale_): x(xx), y(yy), scale(scale_){};
};

#endif