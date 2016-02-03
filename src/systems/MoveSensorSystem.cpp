//
// Created by Vasyl.
//

#include <SDL2/SDL_log.h>
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

bool MoveSensorSystem::checkDirection(SurfaceC *pC, SensorC *pSensorC,
                                      PositionC *pPositionC, MoveC *pMoveC, int step) {
    int pixel;
    int testX = (int) pPositionC->x;
    int testY = (int) pPositionC->y - pSensorC->verticalStep - 1;
    for (int i = 0; i < pSensorC->sight; i++) {
        testX += step;

        pixel = getSurfacePixel(pC->surface, testX, testY);

        if (pixel > 0) {
            printf("Can't move\n");
            return true;
        }
    }

    printf("direction move allowed %d\n", step);
    return false;
}
