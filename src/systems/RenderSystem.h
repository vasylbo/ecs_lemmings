//
// Created by Vasyl.
//

#ifndef LEMMINGS_RENDERSYSTEM_H
#define LEMMINGS_RENDERSYSTEM_H

#include <SDL2/SDL_render.h>
#include "entityx/entityx.h"

namespace ex = entityx;

class RenderSystem : public ex::System<RenderSystem> {
public:
    explicit RenderSystem(SDL_Renderer *pRenderer);

    void update(ex::EntityManager &entities,
                ex::EventManager &events,
                ex::TimeDelta dt);

    ~ RenderSystem();
private:
    SDL_Renderer *_renderer;
    SDL_Rect _cachedSource;
    SDL_Rect _cachedDest;
};


#endif //LEMMINGS_RENDERSYSTEM_H
