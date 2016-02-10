//
// Created by Vasyl.
//

#ifndef LEMMINGS_SPAWNSYSTEM_H
#define LEMMINGS_SPAWNSYSTEM_H

#include "entityx/System.h"
#include "../LemmingBuilder.h"

class SpawnSystem : public entityx::System<SpawnSystem> {
public:
    SpawnSystem(LemmingBuilder* pLemmingBuilder);
    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
private:
    void createLemming(entityx::EntityManager &entities);
    LemmingBuilder* _builder;
};


#endif //LEMMINGS_SPAWNSYSTEM_H
