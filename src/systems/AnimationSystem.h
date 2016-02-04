//
// Created by Vasyl.
//

#ifndef LEMMINGS_ANIMATIONSYSTEM_H
#define LEMMINGS_ANIMATIONSYSTEM_H

#include "entityx/System.h"

class AnimationSystem : public entityx::System<AnimationSystem> {
public:
    AnimationSystem() {};

    virtual void update(entityx::EntityManager &entities, entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
};


#endif //LEMMINGS_ANIMATIONSYSTEM_H
