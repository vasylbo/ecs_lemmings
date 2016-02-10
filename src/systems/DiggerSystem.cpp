//
// Created by Vasyl.
//

#include "DiggerSystem.h"
#include "../components/PositionC.h"
#include "../components/DiggerC.h"
#include "../components/SurfaceC.h"
#include "../components/RenderC.h"
#include "../components/GroundedC.h"

void DiggerSystem::update(entityx::EntityManager &entities,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt) {
    SDL_Surface*surface;
    RenderC *renderC;
    PositionC *positionC;
    DiggerC *diggerC;
    int x;
    int y;

    for (entityx::Entity world : entities
            .entities_with_components<SurfaceC, RenderC>()) {
        surface = world.component<SurfaceC>().get()->surface;
        renderC = world.component<RenderC>().get();

        bool dirty = false;

        SDL_LockSurface(surface);

        Uint8* pixels = (Uint8*) surface->pixels;
        for (entityx::Entity entity : entities
                .entities_with_components<PositionC, DiggerC, GroundedC>()) {
            positionC = entity.component<PositionC>().get();
            diggerC = entity.component<DiggerC>().get();

            diggerC->timeFromLastDig += dt * 1000;

            if (diggerC->timeFromLastDig > diggerC->diggerInterval) {
                x = (int) positionC->x;
                y = (int) positionC->y;

                for (int i = x - 7; i < x + 9; i++) {
                    for (int j = y; j < y + diggerC->diggerSpeed; j++) {
                        int pos = (j * surface->pitch) + i;
                        pixels[pos] = 0;
                    }
                }

                diggerC->timeFromLastDig = 0;
                dirty = true;
            }
        }
        SDL_UnlockSurface(surface);
        if (dirty) {
            renderC->texture =
                    SDL_CreateTextureFromSurface(_renderer, surface);
        }
    }
}

