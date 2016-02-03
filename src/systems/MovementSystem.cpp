//
// Created by Vasyl.
//

#include "MovementSystem.h"
#include "../components/GroundedC.h"
#include "../components/PositionC.h"
#include "../components/MoveC.h"
#include "../components/SensorC.h"

void MovementSystem::update(entityx::EntityManager &entities,
                            entityx::EventManager &events,
                            entityx::TimeDelta dt) {
    entities.each<GroundedC, PositionC, MoveC, SensorC>([](
            entityx::Entity pEntity, GroundedC &pGroundedC,
            PositionC &pPositionC, MoveC &pMoveC, SensorC &pSensorC) {
        if ((pMoveC.speed > 0 && !pSensorC.rightS) ||
                (pMoveC.speed < 0 && !pSensorC.leftS)) {
            pPositionC.x += pMoveC.speed;
        } else {
            pMoveC.speed *= -1;
        }
    });
}

MovementSystem::MovementSystem() {

}
