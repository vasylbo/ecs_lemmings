//
// Created by Vasyl.
//

#ifndef LEMMINGS_RENDERCOMPONENT_H
#define LEMMINGS_RENDERCOMPONENT_H

#include <SDL_rect.h>
#include <SDL_render.h>
#include "entityx/Entity.h"

struct RenderC : public entityx::Component<RenderC> {
    RenderC() { };

    RenderC(SDL_Texture *pTexture,
            int pAnchorX,
            int pAnchorY) :
            texture(pTexture),
            w(), h(),
            sX(0), sY(0),
            anchor(),
            flip(false){
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        anchor.x = pAnchorX;
        anchor.y = pAnchorY;
    }

    RenderC(SDL_Texture *pTexture,
            int scale):
            texture(pTexture),
            w(), h(),
            sX(0), sY(0),
            anchor(),
            flip(false) {

        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        w *= scale;
        h *= scale;
        anchor.x = 0;
        anchor.y = 0;
    }

//    remove texture, add id, add textures cache
    SDL_Texture *texture;

    int w, h;
    int sX, sY;
    bool flip;

    SDL_Point anchor;
};

#endif //LEMMINGS_RENDERCOMPONENT_H
