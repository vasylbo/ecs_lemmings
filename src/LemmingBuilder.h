//
// Created by Vasyl.
//

#ifndef LEMMINGS_LEMMINGBUILDER_H
#define LEMMINGS_LEMMINGBUILDER_H


#include <entityx/Entity.h>
#include "systems/InteractiveSystem.h"

namespace ex = entityx;

class LemmingBuilder {
public:
    LemmingBuilder(ex::EntityManager *pEntities,
                   ex::EventManager *pEvents);

    ex::Entity makeLemming(int pX, int pY);
    ex::Entity makeFalling(ex::Entity &lemming);
    ex::Entity makeDigger(ex::Entity &lemming);
    ex::Entity makeWalker(ex::Entity &lemming);
    void cleanLemming(ex::Entity &lemming);

    ~LemmingBuilder();

private:
    entityx::EntityManager *_entities;
    entityx::EventManager *_events;
};


#endif //LEMMINGS_LEMMINGBUILDER_H
