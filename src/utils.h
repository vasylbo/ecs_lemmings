//
// Created by Vasyl.
//

#ifndef LEMMINGS_UTILS_H
#define LEMMINGS_UTILS_H


#include <SDL_surface.h>
#include <entityx/Entity.h>

namespace utils {
    Uint8 getSurfacePixel(SDL_Surface *pSurface, int pScale, int pX, int pY);
}

#endif //LEMMINGS_UTILS_H
