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

//todo: even position y on adding to system

void BuilderSystem::update(entityx::EntityManager &entities,
                           entityx::EventManager &events,
                           entityx::TimeDelta dt) {
    entityx::Entity surfaceE = (*entities.entities_with_components<SurfaceC>
            ().begin());
    SurfaceC *surfaceC = surfaceE.component<SurfaceC>().get();
    double scale = surfaceC->scale;
    SDL_Surface *surface = surfaceC->surface;
    RenderC *surfaceRenderC = surfaceE.component<RenderC>().get();

    void *rawPixels;

    int pitch;
    SDL_LockTexture(surfaceRenderC->texture, nullptr, &rawPixels, &pitch);

    unsigned char *pixels = (unsigned char *) rawPixels;


    for (entityx::Entity unit : entities
            .entities_with_components<BuilderC, PositionC>()) {
        AnimationC *animationC = unit.component<AnimationC>().get();
        PositionC *positionC = unit.component<PositionC>().get();
        BuilderC *builderC = unit.component<BuilderC>().get();

        if (animationC->currentFrame == 0 &&
                builderC->lastFrame == animationC->fCount - 1) {
            int x = (int) positionC->x;
            int y = (int) positionC->y;

            for (int i = -1; i < 9; i++) {
                for (int j = -4; j < -3; j++) {
                    int buildX = (int) ((x + i) / scale);
                    int buildY = (int) ((y - j) / scale);
                    int pos = (buildY * surface->pitch) + buildX * 3;

                    pixels[pos] = 247;
                    pixels[++pos] = 214;
                    pixels[++pos] = 214;
                }
            }

            //has to do it pixel perfect
            positionC->x = (int) positionC->x + 4;
            positionC->y = (int) positionC->y - 2;
        }

        builderC->lastFrame = animationC->currentFrame;
    }

    SDL_UnlockTexture(surfaceRenderC->texture);
}



