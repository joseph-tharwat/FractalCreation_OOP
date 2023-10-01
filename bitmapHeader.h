

#ifndef BITMAP_HEADER_H
#define BITMAP_HEADER_H

#include <iostream>
using namespace std;

#pragma pack(push,2)

struct bitmapHeader
{
    char signature[2];//{"BM"}
    uint32_t  fileSize;
    uint32_t reserved{0};
    uint32_t dataOffset;
};

struct bitmapInfoHeader
{
    uint32_t infoHeaderSize{40};
    uint32_t width;
    uint32_t height;
    uint16_t planes{1};
    uint16_t bitPerPixel{24};
    uint32_t compression{0};
    uint32_t imageSize{0};
    uint32_t horizontalResolution{2400};
    uint32_t verticalResolution{2400};
    uint32_t colorUsed{0};
    uint32_t colorImporatant{0};
};

#pragma pack(pop)

#endif