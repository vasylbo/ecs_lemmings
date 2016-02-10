//
// Created by Vasyl.
//

#ifndef LEMMINGS_LEMMINGBUILDER_H
#define LEMMINGS_LEMMINGBUILDER_H


#include <entityx/Entity.h>
namespace ex = entityx;

class LemmingBuilder {
public:
    LemmingBuilder(ex::EntityManager *pEntities);
    
    ex::Entity makeLemming(int pX, int pY);
    ex::Entity makeFalling(ex::Entity &lemming);
    ex::Entity makeDigger(ex::Entity &lemming);
    ex::Entity makeWalker(ex::Entity &lemming);
    void cleanLemming(ex::Entity &lemming);

private:
    entityx::EntityManager *_entities;
};


#endif //LEMMINGS_LEMMINGBUILDER_H
