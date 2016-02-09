//
// Created by Vasyl
//

#include "SDL2/SDL_image.h"
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
            [this](entityx::Entity pEntity,
                   RenderC &pRenderC,
                   PositionC &pPositionC) {
                _cachedSource.x = pRenderC.sX;
                _cachedSource.y = pRenderC.sY;

                _cachedDest.x = int(pPositionC.x) - pRenderC.anchor.x;
                _cachedDest.y = int(pPositionC.y) - pRenderC.anchor.y;

                _cachedDest.w = _cachedSource.w = pRenderC.w;
                _cachedDest.h = _cachedSource.h = pRenderC.h;

                SDL_RenderCopy(_renderer,
                               pRenderC.texture,
                               &_cachedSource, &_cachedDest);
            });
    SDL_RenderPresent(_renderer);
}

void RenderSystem::configure(entityx::EntityManager &entities, entityx::EventManager &events) {
    events.subscribe < ex::ComponentAddedEvent < AssetC >> (*this);
}

void RenderSystem::receive(const ex::ComponentAddedEvent <AssetC> &event) {
    auto entity = event.entity;
    auto assetC = event.component.get();
    auto texture = toTexture(assetC->id, _renderer);

    entity.assign<RenderC>(texture);
}

SDL_Texture *RenderSystem::toTexture(const char *pId, SDL_Renderer *pRenderer) {
    SDL_Surface *surface = IMG_Load(pId);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
