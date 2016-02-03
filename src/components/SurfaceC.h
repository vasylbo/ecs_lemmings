//
// Created by Vasyl.
//


#ifndef LEMMINGS_BACKC_H
#define LEMMINGS_BACKC_H

#include <entityx/Entity.h>
#include <SDL2/SDL_surface.h>

struct SurfaceC : public entityx::Component<SurfaceC> {
    SurfaceC() { };

    SurfaceC(SDL_Surface *pSurface) : surface(pSurface) { };

    SDL_Surface *surface;
};

#endif //LEMMINGS_BACKC_H
