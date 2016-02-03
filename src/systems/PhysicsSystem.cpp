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

    for (entityx::Entity ground : entities.entities_with_components<SurfaceC>()) {
        SDL_Surface *surface = ground.component<SurfaceC>().get()->surface;
        for (entityx::Entity unit : entities
                .entities_with_components<PhysicsC, PositionC>()) {
            positionC = unit.component<PositionC>().get();
            positionC->y += _gravitySpeed * dt;
            auto pixel = getSurfacePixel(
                surface, (int)positionC->x, (int)positionC->y);
            if (pixel > 0) {
                while (pixel != 0) {
                    positionC->y -= 1;
                    pixel = getSurfacePixel(
                        surface, (int)positionC->x, (int)positionC->y);
                }
                if (!unit.has_component<GroundedC>()) {
                    unit.assign<GroundedC>();
                }
            } else {
                if (unit.has_component<GroundedC>()) {
                    unit.remove<GroundedC>();
                }
            }
        }
    }

}

PhysicsSystem::PhysicsSystem() {
    _gravitySpeed = 9.8;
}


