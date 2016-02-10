//
// Created by Vasyl.
//

#include "SpawnSystem.h"
#include "../components/GameC.h"

void SpawnSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events, entityx::TimeDelta dt) {
    entities.each<GameC>(
            [this, &dt, &entities](entityx::Entity pEntity, GameC &pGameC) {
        if (pGameC.lemmingsToCreate > pGameC.lemmingsCreated) {
            pGameC.timeFromLastLemming += dt * 1000;
            if (pGameC.timeFromLastLemming > pGameC.lemmingInterval) {
                pGameC.timeFromLastLemming = 0;

                createLemming(entities);

                ++pGameC.lemmingsCreated;
            }
        }
    });

}
void SpawnSystem::createLemming(entityx::EntityManager &entities) {
    entityx::Entity lemming = _builder->makeLemming(180, 60);
    _builder->makeFalling(lemming);
}

SpawnSystem::SpawnSystem(LemmingBuilder *pLemmingBuilder):
        _builder(pLemmingBuilder) { }
