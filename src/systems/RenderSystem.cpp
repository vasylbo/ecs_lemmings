//
// Created by Vasyl
//

#include "SDL_image.h"
#include "RenderSystem.h"
#include "../components/RenderC.h"
#include "../components/PositionC.h"
#include "../components/CameraC.h"
#include "../Constants.h"
#include "../components/LayerC.h"

using namespace std;

RenderSystem::RenderSystem(SDL_Renderer *pRenderer) :
        _renderer(pRenderer) {
//    int pngFlags = IMG_INIT_PNG;
//    IMG_Init(pngFlags);
}

RenderSystem::~RenderSystem() {
    _renderer = NULL;
}

void RenderSystem::update(ex::EntityManager &entities,
                          ex::EventManager &events,
                          ex::TimeDelta dt) {
    _cachedSource.x = 0;
    _cachedSource.y = 0;

    PositionC *cameraPos;
    RenderC *renderC;
    PositionC *positionC;
    SDL_SetRenderDrawColor(_renderer, 0x0, 0x0, 0x0, 0xFF);
    SDL_RenderClear(_renderer);
    for (entityx::Entity cam : entities.entities_with_components<CameraC>()) {
        cameraPos = cam.component<PositionC>().get();
        for (entityx::Entity renderE : entities
                .entities_with_components<RenderC, PositionC,
                        LayerC<constants::GAME_LAYER>>()) {
            renderC = renderE.component<RenderC>().get();
            positionC = renderE.component<PositionC>().get();

            _cachedSource.x = renderC->sX;
            _cachedSource.y = renderC->sY;

            _cachedDest.x = int(positionC->x - cameraPos->x) - renderC->anchor.x;
            _cachedDest.y = int(positionC->y - cameraPos->y) - renderC->anchor.y;

            _cachedDest.w = _cachedSource.w = renderC->w;
            _cachedDest.h = _cachedSource.h = renderC->h;

            if (renderC->flip) {
                SDL_RenderCopyEx(_renderer,
                                 renderC->texture,
                                 &_cachedSource, &_cachedDest,
                                 0, NULL, SDL_FLIP_HORIZONTAL);
            } else {
                SDL_RenderCopy(_renderer,
                               renderC->texture,
                               &_cachedSource, &_cachedDest);
            }
        };
    }
    for (entityx::Entity element : entities.entities_with_components
                   <RenderC, PositionC, LayerC<constants::GUI_LAYER>>()) {
        renderC = element.component<RenderC>().get();
        positionC = element.component<PositionC>().get();

        _cachedSource.x = renderC->sX;
        _cachedSource.y = renderC->sY;

        _cachedDest.x = int(positionC->x) - renderC->anchor.x;
        _cachedDest.y = int(positionC->y) - renderC->anchor.y;

        _cachedDest.w = _cachedSource.w = renderC->w;
        _cachedDest.h = _cachedSource.h = renderC->h;

        SDL_RenderCopy(_renderer,
                       renderC->texture,
                       &_cachedSource,
                       &_cachedDest);

    }

    SDL_RenderPresent(_renderer);
}

void RenderSystem::configure(entityx::EntityManager &entities,
                             entityx::EventManager &events) {
    events.subscribe<ex::ComponentAddedEvent<AssetC>>(*this);
}

void RenderSystem::receive(const ex::ComponentAddedEvent <AssetC> &event) {
    auto entity = event.entity;
    auto assetC = event.component.get();
    auto texture = toTexture(assetC->id, _renderer);

    if (entity.has_component<RenderC>()) {
        entity.remove<RenderC>();
    }
    entity.assign<RenderC>(texture, 0, 0);
}

SDL_Texture *RenderSystem::toTexture(const char *pId, SDL_Renderer *pRenderer) {

    SDL_Surface *surface = IMG_Load(pId);

    if (surface == NULL) {
        printf("%s not loaded, error %s\n", pId, IMG_GetError());
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
