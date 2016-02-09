//
// Created by Vasyl.
//

#include "MovementSystem.h"
#include "../components/GroundedC.h"
#include "../components/PositionC.h"
#include "../components/MoveC.h"
#include "../components/SensorC.h"
#include "RenderSystem.h"
#include "../components/RenderC.h"

void MovementSystem::update(entityx::EntityManager &entities,
                            entityx::EventManager &events,
                            entityx::TimeDelta dt) {
    entities.each<GroundedC, PositionC, MoveC, SensorC, RenderC>([dt](
            entityx::Entity pEntity, GroundedC &pGroundedC,
            PositionC &pPositionC, MoveC &pMoveC, SensorC &pSensorC,
            RenderC &pRenderC) {
        if ((pMoveC.speed > 0 && !pSensorC.rightS) ||
                (pMoveC.speed < 0 && !pSensorC.leftS)) {
            pPositionC.x += pMoveC.speed * dt;
        } else {
            pMoveC.speed *= -1;
            pRenderC.flip = pMoveC.speed <= 0;
        }
    });
}

MovementSystem::MovementSystem() {

}
