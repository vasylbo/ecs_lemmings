//
// Created by Vasyl.
//

#ifndef LEMMINGS_DIGGERC_H
#define LEMMINGS_DIGGERC_H

#include <entityx/Entity.h>

struct DiggerC : entityx::Component<DiggerC> {
    DiggerC(int pDiggerSpeed) : diggerSpeed(pDiggerSpeed),
                                diggerInterval(600),
                                timeFromLastDig(0) { }

    // static data
    int diggerSpeed;
    int diggerInterval;

    // dynamic data
    int timeFromLastDig;
};

#endif //LEMMINGS_DIGGERC_H
