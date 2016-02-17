//
// Created by Vasyl.
//

#include "utils.h"

Uint8 utils::getSurfacePixel(SDL_Surface *pSurface, int scale, int pX, int pY) {
    pX /= scale;
    pY /= scale;

    assert(pX >= 0 && pY >= 0 && pX < pSurface->w && pY < pSurface->h);
    assert(pSurface->format->BitsPerPixel == 8);

    Uint8 *pixels = (Uint8 *) pSurface->pixels;
    int pos = (pY * pSurface->pitch) + pX;
    return pixels[pos];
}

