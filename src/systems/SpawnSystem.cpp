//
// Created by Vasyl.
//

#include "SpawnSystem.h"
#include "../components/GameC.h"
#include "../components/AssetC.h"
#include "../components/LemmingC.h"
#include "../components/AnimationC.h"
#include "../components/MoveC.h"
#include "../components/PhysicsC.h"
#include "../components/PositionC.h"
#include "../components/SensorC.h"
#include "../components/InteractiveC.h"

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
    entityx::Entity lemming = entities.create();

    lemming.assign<AssetC>("walk.png");
    lemming.assign<AnimationC>("idle", 15);
    lemming.assign<LemmingC>();
    lemming.assign<SensorC>(5, 5);
    lemming.assign<MoveC>(15);
    lemming.assign<PhysicsC>();
    lemming.assign<PositionC>(180, 60);
    lemming.assign<InteractiveC>();
}

