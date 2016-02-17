//
// Created by Vasyl.
//

#ifndef LEMMINGS_INPUTSYSTEM_H
#define LEMMINGS_INPUTSYSTEM_H

#include <entityx/System.h>
#include "SDL_Rect.h"


typedef void (*InputCallbackFN)(entityx::Entity, entityx::EventManager &);

class InputSystem : public entityx::System<InputSystem> {
public:
    InputSystem() { }
    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
};


#endif //LEMMINGS_INPUTSYSTEM_H
