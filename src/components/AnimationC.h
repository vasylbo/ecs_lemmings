//
// Created by Vasyl.
//

#ifndef LEMMINGS_ANIMATIONC_H
#define LEMMINGS_ANIMATIONC_H

#include "entityx/Entity.h"

struct AnimationC : public entityx::Component<AnimationC> {
    AnimationC() {
    };

    AnimationC(const char *pId, int pFrameRate,
               int pAX, int pAY,
               int pW, int pH, int pFCount) :
            id(pId),
            frameTime(1000 / pFrameRate),
            timeSinceLastFrame(100000),
            aX(pAX), aY(pAY),
            fW(pW), fH(pH),
            fX(0), fY(0), fCount(pFCount) { }

//    dynamic data
    int frameTime;
    int timeSinceLastFrame;
    int currentFrame;

//    static data
    const char *id;
    int fW, fH;
    int fX, fY;
    int fCount;
    int aX, aY;
};

#endif //LEMMINGS_ANIMATIONC_H
