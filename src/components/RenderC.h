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

    RenderC(SDL_Texture *pTexture,
            int pAnchorX = 0,
            int pAnchorY = 0) :
            texture(pTexture),
            w(), h(),
            sX(0), sY(),
            anchor() {
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        anchor.x = pAnchorX;
        anchor.y = pAnchorY;

    }

//    remove texture, add id, add textures cache
    SDL_Texture *texture;

    int w, h;
    int sX, sY;

    SDL_Point anchor;
};

#endif //LEMMINGS_RENDERCOMPONENT_H
