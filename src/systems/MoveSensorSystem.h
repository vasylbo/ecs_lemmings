//
// Created by Vasyl.
//

#ifndef LEMMINGS_MOVESENSORSYSTEM_H
#define LEMMINGS_MOVESENSORSYSTEM_H

#include <SDL2/SDL_surface.h>
#include "entityx/System.h"
#include "../components/SensorC.h"
#include "../components/PositionC.h"
#include "../components/MoveC.h"
#include "../components/SurfaceC.h"

class MoveSensorSystem : public entityx::System<MoveSensorSystem> {
public:
    MoveSensorSystem() {};

    virtual void update(entityx::EntityManager &entities, entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
private:
    bool checkDirection(SurfaceC *pC, SensorC *pSensorC, PositionC *pPositionC, MoveC *pMoveC, int i);
};


#endif //LEMMINGS_MOVESENSORSYSTEM_H
