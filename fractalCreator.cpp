
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

    if (m_bGotFirstRange)
    {
		m_rangeTotalPexil.push_back(0);
	}

	m_bGotFirstRange = true;
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

int fractalCreator::getRange(int iterations)
{
    int range = 0;
    for(int i =1; i< m_rangeIterations.size(); i++)
    {
        if(m_rangeIterations[i] > iterations )
        {
            break;
        }
        range = i;
    }
    return range;
}

void fractalCreator::drawFractal()
{
    for(int x = 0; x<m_width; x++)
    {
        for(int y = 0; y<m_height; y++)
        {
            uint32_t iterations = m_fractal[y * m_width + x];
            
            RGB startColor(m_rangeColor[getRange(iterations)]);
            RGB endColor(m_rangeColor[getRange(iterations)+1]);
            RGB diffColor = endColor - startColor;
            RGB result(0,0,0);
            int totalPexilInRange = m_rangeTotalPexil[getRange(iterations)];
            int startRange = m_rangeIterations[getRange(iterations)];
            
            if(iterations != mandelbrot::MAX_ITERATIONS)
            {
                int totalPexil = 0;
                for(int i = startRange; i<= iterations; i++)
                {
                    totalPexil = totalPexil + m_histogram[i];
                }
                result.red = startColor.red + diffColor.red * (double)totalPexil/totalPexilInRange;
                result.green = startColor.green + diffColor.green * (double)totalPexil/totalPexilInRange;
                result.blue = startColor.blue + diffColor.blue * (double)totalPexil/totalPexilInRange;
            }
            m_image.setPixel(x, y, result.red, result.green, result.blue);
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

