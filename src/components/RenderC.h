//
// Created by Vasyl.
//

#ifndef LEMMINGS_RENDERCOMPONENT_H
#define LEMMINGS_RENDERCOMPONENT_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "entityx/Entity.h"

struct RenderC : public entityx::Component<RenderC> {
    RenderC() { };

    RenderC(SDL_Texture *pTexture) :
            texture(pTexture),
            w(), h() {
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    }

    RenderC(SDL_Texture *pTexture, int pW, int pH) :
            texture(pTexture),
            w(pW), h(pH) {};

    RenderC(SDL_Texture *pTexture, double scale) :
            texture(pTexture),
            w(), h() {
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        w *= scale;
        h *= scale;
    }

//    remove texture, add id, add textures cache
    SDL_Texture *texture;
    int w, h;
};

#endif //LEMMINGS_RENDERCOMPONENT_H
