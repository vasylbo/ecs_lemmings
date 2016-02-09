//
// Created by Vasyl
//

#include "PhysicsSystem.h"
#include "../components/SurfaceC.h"
#include "../components/PositionC.h"
#include "../components/PhysicsC.h"
#include "../components/GroundedC.h"
#include "../utils.h"

void PhysicsSystem::update(entityx::EntityManager &entities,
                           entityx::EventManager &events,
                           entityx::TimeDelta dt) {
    PositionC *positionC;
    Uint8 pixel;

    for (entityx::Entity ground : entities.entities_with_components<SurfaceC>()) {
        SurfaceC *surfaceC = ground.component<SurfaceC>().get();
        SDL_Surface *surface = surfaceC->surface;
        for (entityx::Entity unit : entities
                .entities_with_components<PhysicsC, PositionC>()) {
            positionC = unit.component<PositionC>().get();

            pixel = getSurfacePixel(surface,
                            (int) positionC->x,
                            (int) positionC->y + 1);

            // todo: refactor
            if (pixel > 0) {
                while (pixel != 0) {
                    positionC->y -= 1;
                    pixel = getSurfacePixel(
                            surface, (int) positionC->x, (int) positionC->y);
                }
                if (!unit.has_component<GroundedC>()) {
                    unit.assign<GroundedC>();
                }
            } else {
                if (unit.has_component<GroundedC>()) {
                    for (int i = 1; i < surfaceC->maxDrop; i++) {
                        pixel = getSurfacePixel(
                                surface,
                                (int) positionC->x,
                                (int) positionC->y + i);
                        if (pixel == 0) {
                            positionC->y += i;
                            break;
                        }
                    }
                    if (pixel != 0)
                        unit.remove<GroundedC>();
                } else {
                    positionC->y += _gravitySpeed * dt;
                }
            }
        }
    }

}

PhysicsSystem::PhysicsSystem() {
    _gravitySpeed = 9.8;
}


