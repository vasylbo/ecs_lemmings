//
// Created by Vasyl.
//

#ifndef LEMMINGS_DIGGERC_H
#define LEMMINGS_DIGGERC_H

#include <entityx/Entity.h>

struct DiggerC : entityx::Component<DiggerC> {
    DiggerC(int pDiggerSpeed, int pDiggerInterval) :
                                diggerSpeed(pDiggerSpeed),
                                diggerInterval(pDiggerInterval),
                                timeFromLastDig(0) { }

    // static data
    int diggerSpeed;
    int diggerInterval;

    // dynamic data
    int timeFromLastDig;
};

#endif //LEMMINGS_DIGGERC_H
