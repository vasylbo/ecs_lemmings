//
// Created by Vasyl.
//

#ifndef LEMMINGS_ANIMATIONC_H
#define LEMMINGS_ANIMATIONC_H

#include "entityx/Entity.h"

struct AnimationC : public entityx::Component<AnimationC> {
    AnimationC() {
    };

    AnimationC(const char *pId, int pFrameRate = 15) :
            id(pId),
            frameTime(1000 / pFrameRate),
            timeSinceLastFrame(100000),
            fW(), fH(), fX(), fY(), fCount() {
        fW = 12;
        fH = 20;
        fX = fY = 0;
        fCount = 5;
    };

//    dynamic data
    int frameTime;
    int timeSinceLastFrame;
    int currentFrame;

//    static data
    const char *id;
    int fW, fH;
    int fX, fY;
    int fCount;
};

#endif //LEMMINGS_ANIMATIONC_H
