
#include "bitmap.h"

#include<fstream>

bitmap::bitmap(uint32_t width, uint32_t height): m_width(width),
                                                 m_height(height),
                                                 m_size(width*height*3),
                                                 m_pPixels(new uint8_t[width * height * 3] {0})
{
    
     memset(m_pPixels, 255, m_size);
}

void bitmap::write(string bitmapName)
{
    bitmapHeader header;
    bitmapInfoHeader infoHeader;

    header.signature[0] = 'B';
    header.signature[1] = 'M';

    header.fileSize = sizeof(bitmapHeader) + sizeof(bitmapInfoHeader) + m_size;
    header.dataOffset = sizeof(bitmapHeader) + sizeof(bitmapInfoHeader);


    // infoHeader.bitPerPixel = 24;
    infoHeader.height = m_height;
    infoHeader.width = m_width;
    // infoHeader.verticalResolution = 2400;
    // infoHeader.horizontalResolution = 2400;
    // infoHeader.imageSize = m_size;

    ofstream file;
    file.open(bitmapName, ios::out|ios::binary);
    if(!file)
    {
        cout<<"file can not open"<<endl;
    }

    file.write((char*)&header, sizeof(bitmapHeader));
    file.write((char*)&infoHeader, sizeof(bitmapInfoHeader));
    file.write((char*)m_pPixels, m_size);
    // file.write((char*)m_pPixels.get(), m_size);

    file.close();
    if(!file)
    {
        cout<<"file can not close"<<endl;
    }
}

void bitmap::setPixel(uint32_t x, uint32_t y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint32_t location = (y*m_width*3) + (x*3);
    m_pPixels[location] = blue;
    m_pPixels[location+1] = green;
    m_pPixels[location+2] = red;
}
    


bitmap::~bitmap()
{
}