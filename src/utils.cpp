//
// Created by Vasyl.
//

#include <assert.h>
#include "utils.h"

Uint8 getSurfacePixel(SDL_Surface *pSurface, int x, int y) {
    assert(x >= 0 && y >= 0 && x < pSurface->w && y < pSurface->h);
    assert(pSurface->format->BitsPerPixel == 8);

    Uint8* pixels = (Uint8 *) pSurface->pixels;
    int pos = (y * pSurface->pitch) + x;
    return pixels[pos];
}
