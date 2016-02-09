//
// Created by Vasyl.
//

#ifndef LEMMINGS_SPAWNSYSTEM_H
#define LEMMINGS_SPAWNSYSTEM_H

#include "entityx/System.h"

class SpawnSystem : public entityx::System<SpawnSystem> {


public:
    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
private:
    void createLemming(entityx::EntityManager &entities);
};


#endif //LEMMINGS_SPAWNSYSTEM_H
