
#include "zoomList.h"

zoomList::zoomList(int width, int height): m_width(width), m_height(height)
{
  
}

void zoomList::add(zoom z)
{
    m_zoomList.push_back(z);

    /*negative sign here, because the first pexil in bitmap is in the bottom,
    but in the screen coords the first bit is in the above.*/
    m_xCenter = m_xCenter +  (z.x - m_width/2) * m_scale;
    m_xCenter = m_yCenter + -(z.y - m_height/2) * m_scale;

    m_scale = m_scale * z.scale;
}

pair<double, double> zoomList::doZoom(int x, int y)
{
    double xFractal = m_xCenter + (x-m_width/2) * m_scale; 
    double yFractal = m_yCenter + (y-m_height/2) * m_scale;

    return pair<double, double>(xFractal, yFractal);
}



zoomList::~zoomList()
{
    
}