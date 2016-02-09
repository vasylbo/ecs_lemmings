//
// Created by Vasyl.
//


#ifndef LEMMINGS_BACKC_H
#define LEMMINGS_BACKC_H

#include <entityx/Entity.h>
#include <SDL_surface.h>

struct SurfaceC : public entityx::Component<SurfaceC> {
    SurfaceC() {
    };

    SurfaceC(SDL_Surface *pSurface, int pMaxDrop) :
            surface(pSurface),
            maxDrop(pMaxDrop) {
    };

    SDL_Surface *surface;
    int maxDrop;
};

#endif //LEMMINGS_BACKC_H
