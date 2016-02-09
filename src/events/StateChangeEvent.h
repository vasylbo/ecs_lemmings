//
// Created by Vasyl.
//

#include <entityx/Event.h>
#include <entityx/Entity.h>
#include "../LemmingType.h"

#ifndef LEMMINGS_STATECHANGEEVENT_H
#define LEMMINGS_STATECHANGEEVENT_H


struct StateChangeEvent : public entityx::Event<StateChangeEvent> {
    StateChangeEvent(LemmingType pNewType, entityx::Entity* pEntity) :
            newType(pNewType), entity(pEntity) {}

    LemmingType newType;
    entityx::Entity* entity;
};

#endif //LEMMINGS_STATECHANGEEVENT_H
