//
// Created by Vasyl.
//

#include "BuilderSystem.h"
#include "../components/SurfaceC.h"
#include "../components/RenderC.h"
#include "../components/PositionC.h"
#include "../components/BuilderC.h"
#include "../components/AnimationC.h"

BuilderSystem::BuilderSystem(SDL_Renderer *pRenderer):_renderer(pRenderer) {}

void BuilderSystem::update(entityx::EntityManager &entities,
                           entityx::EventManager &events,
                           entityx::TimeDelta dt) {
    entityx::Entity surfaceE = (*entities.entities_with_components<SurfaceC>
            ().begin());
    SurfaceC *surfaceC = surfaceE.component<SurfaceC>().get();
    double scale = surfaceC->scale;
    SDL_Surface *surface = surfaceC->surface;
    RenderC *surfaceRenderC = surfaceE.component<RenderC>().get();

    Uint8 *pixels = (Uint8*) surface->pixels;

    Uint8 pixel(120);
    bool dirty = false;
    SDL_LockSurface(surface);

    for (entityx::Entity unit : entities
            .entities_with_components<BuilderC, PositionC>()) {
        AnimationC *animationC = unit.component<AnimationC>().get();
        PositionC *positionC = unit.component<PositionC>().get();
        BuilderC *builderC = unit.component<BuilderC>().get();

        printf("animation frame %d \n", animationC->currentFrame);
        if (animationC->currentFrame == 0 &&
                builderC->lastFrame == animationC->fCount - 1) {
            int x = (int) positionC->x;
            int y = (int) positionC->y;

            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 1; j++) {
                    int buildX = (int) ((x + i) / scale);
                    int buildY = (int) ((y - j) / scale);
                    int pos = (buildY * surface->pitch) + buildX;

                    pixels[pos] = pixel;
                }
            }

            positionC->x += 4;
            positionC->y -= 2;

            dirty = true;
        }

        builderC->lastFrame = animationC->currentFrame;
    }

    SDL_UnlockSurface(surface);
    if (dirty) {
        surfaceRenderC->texture = SDL_CreateTextureFromSurface(
                _renderer, surface);
    }
}



