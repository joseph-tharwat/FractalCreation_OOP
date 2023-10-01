
#ifndef ZOOM_LIST_H
#define ZOOM_LIST_H

#include "zoom.h"
#include <vector>

using namespace std;

class zoomList
{
private:
    vector<zoom> m_zoomList;
    int m_width;
    int m_height;
    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1};
public:
    zoomList(int width, int height);
    void add(zoom z);
    pair<double, double> doZoom(int x, int y);
    ~zoomList();
};


#endif