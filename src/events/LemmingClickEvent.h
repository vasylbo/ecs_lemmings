//
// Created by Vasyl.
//

#include <entityx/Event.h>
#include <entityx/Entity.h>
#include "../LemmingType.h"

#ifndef LEMMINGS_LEMMINGCLICKEVENT_H
#define LEMMINGS_LEMMINGCLICKEVENT_H

struct LemmingClickEvent : public entityx::Event<LemmingClickEvent> {
        LemmingClickEvent(entityx::Entity& pEntity) : entity(pEntity) {}

        entityx::Entity & entity;
};

#endif //LEMMINGS_LEMMINGCLICKEVENT_H
