//
// Created by Vasyl.
//

#include "AnimationSystem.h"
#include "../components/AssetC.h"

namespace ex = entityx;

void AnimationSystem::update(entityx::EntityManager &entities,
                             entityx::EventManager &events,
                             entityx::TimeDelta dt) {
    AnimationC *aC;
    RenderC *renderC;
    for (ex::Entity entity : entities
            .entities_with_components<AnimationC, RenderC>()) {
        aC = entity.component<AnimationC>().get();
        // remove 1000
        aC->timeSinceLastFrame += dt * 1000;

        if (aC->timeSinceLastFrame > aC->frameTime) {
            // calculate frames to skip if timeSinceLastFrame is too big
            aC->currentFrame = (aC->currentFrame + 1) %
                               aC->fCount;
            renderC = entity.component<RenderC>().get();
            updateAnimation(renderC, aC);
            aC->timeSinceLastFrame = 0;
        }
    }
}

void AnimationSystem::configure(entityx::EntityManager &entities,
                                entityx::EventManager &events) {
    events.subscribe<entityx::ComponentAddedEvent<AnimationC>>(*this);
}

void AnimationSystem::receive(
        const entityx::ComponentAddedEvent<AnimationC> &event) {
    auto entity = event.entity;
    auto animationC = entity.component<AnimationC>().get();

    // will add a render component here
    entity.assign<AssetC>(animationC->id);

    auto renderC = entity.component<RenderC>().get();
    updateAnimation(renderC, animationC);
}

inline void AnimationSystem::updateAnimation(
        RenderC *pRenderC,
        AnimationC *pAnimationC) {
    pRenderC->sX = pAnimationC->fX + pAnimationC->fW * pAnimationC->currentFrame;
    pRenderC->sX = pAnimationC->fX + pAnimationC->fW * pAnimationC->currentFrame;
    pRenderC->w = pAnimationC->fW;
    pRenderC->h = pAnimationC->fH;
    pRenderC->anchor.x = pAnimationC->aX;
    pRenderC->anchor.y = pAnimationC->aY;
}






