//
// Created by Vasyl.
//

#include "StateSystem.h"
#include "../components/AnimationC.h"
#include "../components/MoveC.h"
#include "../components/DiggerC.h"
#include "../components/AssetC.h"

void StateSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events,
                         entityx::TimeDelta dt) {
}

void StateSystem::configure(entityx::EntityManager &entities,
                            entityx::EventManager &events) {
    events.subscribe<entityx::ComponentAddedEvent<GroundedC>>(*this);
    events.subscribe<entityx::ComponentRemovedEvent<GroundedC>>(*this);
}

void StateSystem::receive(const entityx::ComponentAddedEvent<GroundedC>
                          &event) {
    entityx::Entity lemming = event.entity;
    _builder->cleanLemming(lemming);
    _builder->makeWalker(lemming);
}

void StateSystem::receive(const entityx::ComponentRemovedEvent<GroundedC>
                          &event) {
    entityx::Entity lemming = event.entity;
    _builder->cleanLemming(lemming);
    _builder->makeFalling(lemming);
}

// void StateSystem::receive(const StateChangeEvent &event) {
//     ex::Entity lemming = event.entity;
//     _builder->cleanLemming(lemming);
//     switch (event.newType) {
//         case LemmingType::DIGGER:
//             _builder->makeDigger(lemming);
//             break;
// 
//         case LemmingType::BUILDER:
//             _builder->makeBuilder(lemming);
//             break;
// 
//         default:
//             break;
//     }
// }

StateSystem::StateSystem(LemmingBuilder *pBuilder):
        _builder(pBuilder) { }
