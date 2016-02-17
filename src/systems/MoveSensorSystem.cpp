//
// Created by Vasyl.
//

#include <SDL_log.h>
#include "MoveSensorSystem.h"
#include "../utils.h"
#include "../components/GroundedC.h"

void MoveSensorSystem::update(entityx::EntityManager &entities,
                              entityx::EventManager &events,
                              entityx::TimeDelta dt) {
    SurfaceC *surface;
    SensorC *sensorC;
    PositionC *positionC;
    MoveC *moveC;
    for (entityx::Entity ground : entities.entities_with_components<SurfaceC>()) {
        surface = ground.component<SurfaceC>().get();

        for (entityx::Entity unit : entities
                .entities_with_components<SensorC, PositionC, GroundedC, MoveC>()) {
            sensorC = unit.component<SensorC>().get();
            positionC = unit.component<PositionC>().get();
            moveC = unit.component<MoveC>().get();

            sensorC->rightS = checkDirection(surface, sensorC, positionC, moveC, 1);
            sensorC->leftS  = checkDirection(surface, sensorC, positionC, moveC, -1);
        }
    }
}

// todo: refactor: duplicated vertical step
// with surfaces. moveC no longer needed
bool MoveSensorSystem::checkDirection(SurfaceC *pC, SensorC *pSensorC,
                                      PositionC *pPositionC,
                                      MoveC *pMoveC, int step) {
    int testX = (int) pPositionC->x;
    int testY = (int) pPositionC->y - pSensorC->verticalStep - 1;
    int pixel;

    for (int i = 0; i < pSensorC->sight; i++) {
        testX += step;

        pixel = utils::getSurfacePixel(
                pC->surface,
                pC->scale,
                testX, testY);

        if (pixel > 0) {
            return true;
        }
    }
    return false;
}
