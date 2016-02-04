//
// Created by Vasyl.
//

#include "StateSystem.h"
#include "../components/LemmingC.h"
#include "../components/GroundedC.h"
#include "../components/AnimationC.h"

void StateSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events,
                         entityx::TimeDelta dt) {
    for (entityx::Entity entity : entities.
            entities_with_components<LemmingC>()) {
        AnimationC* animationC = entity.component<AnimationC>().get();

        if (entity.has_component<GroundedC>()) {
            entity.replace<AnimationC>("idle");
        } else {
            entity.replace<AnimationC>("run");
        }
    }
}

void StateSystem::configure(entityx::EntityManager &entities,
                            entityx::EventManager &events) {
    events.subscribe<entityx::ComponentAddedEvent<GroundedC>>(*this);
    events.subscribe<entityx::ComponentRemovedEvent<GroundedC>>(*this);
}

void StateSystem::receive(const entityx::ComponentAddedEvent<GroundedC>
                          &event) {
    printf("grounded\n");
}

void StateSystem::receive(const entityx::ComponentRemovedEvent<GroundedC>
                          &event) {
    printf("ungrounded\n");
}
