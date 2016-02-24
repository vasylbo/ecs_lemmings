//
// Created by Vasyl.
//

#ifndef LEMMINGS_ANIMATIONSYSTEM_H
#define LEMMINGS_ANIMATIONSYSTEM_H

#include "entityx/System.h"
#include "../components/AnimationC.h"
#include "../components/RenderC.h"

class AnimationSystem :
        public entityx::System<AnimationSystem>,
        public entityx::Receiver<AnimationSystem> {
public:
    AnimationSystem() {};

    void updateAnimation(RenderC *pRenderC, AnimationC *pAnimationC);
    void receive(const entityx::ComponentAddedEvent<AnimationC> &event);

    virtual void configure(entityx::EntityManager &entities,
                           entityx::EventManager &events) override;
    virtual void update(entityx::EntityManager &entities, entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
};


#endif //LEMMINGS_ANIMATIONSYSTEM_H
