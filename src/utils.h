//
// Created by Vasyl.
//

#ifndef LEMMINGS_UTILS_H
#define LEMMINGS_UTILS_H


#include <SDL_surface.h>
#include <entityx/Entity.h>

namespace utils {
    unsigned int getSurfacePixel(SDL_Surface *pSurface, double pScale, int pX, int pY);
}

#endif //LEMMINGS_UTILS_H
