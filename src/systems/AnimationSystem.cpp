//
// Created by Vasyl.
//

#include "AnimationSystem.h"
#include "../components/AnimationC.h"
#include "../components/RenderC.h"

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
            renderC->sX = aC->fX + aC->fW * aC->currentFrame;
            renderC->sX = aC->fX + aC->fW * aC->currentFrame;
            renderC->w = aC->fW;
            renderC->h = aC->fH;
            renderC->anchor.x = 6;
            renderC->anchor.y = 20;

            aC->timeSinceLastFrame = 0;
        }
    }

}
