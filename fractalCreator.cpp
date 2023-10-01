
#include "fractalCreator.h"



fractalCreator::fractalCreator(int width, int height):  m_width(width),
                                                        m_height(height),
                                                        m_image(width, height),
                                                        m_histogram(new uint32_t[mandelbrot::MAX_ITERATIONS]{0}),
                                                        m_fractal(new uint32_t[m_width * m_height]{0}),
                                                        m_zoomList(width, height)
                                                    


{
    //first zoom in the middle
    addZoom(zoom(width/2, height/2, 4.0/width));
}

void fractalCreator::run(string name)
{
    calculateIterations();
    calculateTotalIterations();
    calculateTotalPexilInRange();
    drawFractal();
    writeBitmap(name);
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

void fractalCreator::addRange(double endRange, RGB rgb)
{
    m_rangeIterations.push_back(endRange*mandelbrot::MAX_ITERATIONS);
    m_rangeColor.push_back(rgb);
    m_rangeTotalPexil.push_back(0);
}

void fractalCreator::calculateTotalPexilInRange()
{
    int rangeIndex = 0;
    for(int i = 0; i< mandelbrot::MAX_ITERATIONS; i++)
    {
        int pixelsCount = m_histogram[i];
        if(i >= m_rangeIterations[rangeIndex+1])
        {
            rangeIndex++;
            
        }
        m_rangeTotalPexil[rangeIndex] = m_rangeTotalPexil[rangeIndex] + pixelsCount;
    }
}

void fractalCreator::calculateTotalIterations()
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
			if(color == 0)
			{
				m_image.setPixel(x, y, 0, 100, 20);
			}
			else
			{
				m_image.setPixel(x, y, color, 0, 0);
			}
           
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

