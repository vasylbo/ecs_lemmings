//
// Created by Vasyl.
//

#include "StateSystem.h"
#include "../components/LemmingC.h"
#include "../components/GroundedC.h"
#include "../components/AnimationC.h"
#include "../events/StateChangeEvent.h"
#include "../components/MoveC.h"
#include "../components/DiggerC.h"

void StateSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events,
                         entityx::TimeDelta dt) {
}

void StateSystem::configure(entityx::EntityManager &entities,
                            entityx::EventManager &events) {
    events.subscribe<entityx::ComponentAddedEvent<GroundedC>>(*this);
    events.subscribe<entityx::ComponentRemovedEvent<GroundedC>>(*this);
    events.subscribe<StateChangeEvent>(*this);
}

void StateSystem::receive(const entityx::ComponentAddedEvent<GroundedC>
                          &event) {
//    printf("grounded\n");
}

void StateSystem::receive(const entityx::ComponentRemovedEvent<GroundedC>
                          &event) {
//    printf("ungrounded\n");
}

void StateSystem::receive(const StateChangeEvent &event) {
    switch (event.newType) {
        case LemmingType::DIGGER:
            switchToDigger(event.entity);
            break;

        default:
            break;
    }

}

void StateSystem::switchToDigger(entityx::Entity* entity) {
    if (!entity->has_component<DiggerC>()) {
        entity->remove<MoveC>();
        entity->remove<AnimationC>();
        entity->assign<DiggerC>(5);
    }
}
