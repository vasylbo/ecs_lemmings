//
// Created by Vasyl.
//

#ifndef LEMMINGS_PHYSICSSYSTEM_H
#define LEMMINGS_PHYSICSSYSTEM_H

#include <SDL_stdinc.h>
#include <SDL_surface.h>
#include "entityx/entityx.h"

class FallSystem : public entityx::System<FallSystem> {

public:
    FallSystem();
    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
private:
    double _gravitySpeed;
};


#endif //LEMMINGS_PHYSICSSYSTEM_H
