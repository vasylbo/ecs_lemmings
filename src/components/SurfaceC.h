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

    SurfaceC(SDL_Surface *pSurface, double pScale, int pMaxDrop) :
            surface(pSurface),
            scale(pScale),
            maxDrop(pMaxDrop) {
    };

    SDL_Surface *surface;
    double scale;
    int maxDrop;
};

#endif //LEMMINGS_BACKC_H
