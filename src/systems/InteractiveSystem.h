//
// Created by Vasyl.
//

#ifndef LEMMINGS_INPUTSYSTEM_H
#define LEMMINGS_INPUTSYSTEM_H

#include <entityx/System.h>
#include "SDL_Rect.h"


typedef void (*InputCallbackFN)(
        entityx::Entity,
        entityx::EntityManager &,
        entityx::EventManager &);

class InteractiveSystem : public entityx::System<InteractiveSystem> {
public:
    InteractiveSystem() { }
    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
};


#endif //LEMMINGS_INPUTSYSTEM_H
