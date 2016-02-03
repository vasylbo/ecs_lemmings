//
// Created by Vasyl
//

#include "RenderSystem.h"
#include "../components/RenderC.h"
#include "../components/PositionC.h"

using namespace std;

RenderSystem::RenderSystem(SDL_Renderer *pRenderer) :
        _renderer(pRenderer) { }

RenderSystem::~RenderSystem() {
    _renderer = NULL;
}

void RenderSystem::update(ex::EntityManager &entities,
                          ex::EventManager &events,
                          ex::TimeDelta dt) {
    _cachedSource.x = 0;
    _cachedSource.y = 0;

    SDL_RenderClear(_renderer);
    entities.each<RenderC, PositionC>(
        [this] (entityx::Entity pEntity,
                RenderC &pRenderC,
                PositionC &pPositionC) {
        _cachedDest.x = int(pPositionC.x);
        _cachedDest.y = int(pPositionC.y);

        _cachedDest.w = _cachedSource.w = pRenderC.w;
        _cachedDest.h = _cachedSource.h = pRenderC.h;

        SDL_RenderCopy(_renderer,
                       pRenderC.texture,
                       &_cachedSource, &_cachedDest);
    });
    SDL_RenderPresent(_renderer);
}
