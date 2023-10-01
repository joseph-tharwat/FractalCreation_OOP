
#include "fractalCreator.h"



fractalCreator::fractalCreator(int width, int height):  m_width(width),
                                                        m_height(height),
                                                        m_image(width, height),
                                                        m_histogram(new uint32_t[mandelbrot::MAX_ITERATIONS]{0}),
                                                        m_fractal(new uint32_t[m_width * m_height]{0}),
                                                        m_zoomList(width, height)
                                                    


{
    
    
}

void fractalCreator::addZoom(zoom z)
{
    m_zoomList.add(z);
}

void fractalCreator::calculateIterations()
{
    for(int x =0; x<m_width; x++)
    {
        for(int y=0; y<m_height; y++)
        {
            pair<double, double> coords =  m_zoomList.doZoom(x, y);
            int iterations = mandelbrot::getIterations(coords.first, coords.second);
            
            if(iterations != mandelbrot::MAX_ITERATIONS)
            {
                m_histogram[iterations]++;
            }
            
            m_fractal[y*m_width+x] = iterations;
        }
    }
}

void fractalCreator::calculateTotal()
{
    for(int i = 0; i<mandelbrot::MAX_ITERATIONS; i++)
    {
        m_total = m_total + m_histogram[i];
    }
}

void fractalCreator::drawFractal()
{
    for(int x = 0; x<m_width; x++)
    {
        for(int y = 0; y<m_height; y++)
        {
            uint32_t iterations = m_fractal[y * m_width + x];
            uint8_t color = 0;
            if(iterations != mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;
                for(int i=0; i<= iterations; i++)
                {
                    hue = hue + (double)m_histogram[i]/m_total;
                }
                color = hue*255;
            }
            m_image.setPixel(x, y, 0, color, 0);
        }
    }
}

void fractalCreator::writeBitmap(string name)
{
    m_image.write(name);
}

fractalCreator::~fractalCreator()
{
}

