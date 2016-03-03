//
// Created by Vasyl.
//

#include "utils.h"

unsigned int utils::getSurfacePixel(SDL_Surface *pSurface, double scale, int pX, int pY) {
    pX /= scale;
    pY /= scale;

    assert(pSurface->format->BytesPerPixel == 3);
    assert(pX >= 0 && pY >= 0 && pX < pSurface->w && pY < pSurface->h);

    unsigned char *pixels = (unsigned char *) pSurface->pixels;
    int pos = (pY * pSurface->pitch) + (pX * pSurface->format->BytesPerPixel);

    unsigned char r = pixels[pos];
    unsigned char g = pixels[++pos];
    unsigned char b = pixels[++pos];

    return r << 24 | g << 16 | b << 8;
}

