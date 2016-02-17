//
// Created by Vasyl.
//

#ifndef LEMMINGS_DIGGERC_H
#define LEMMINGS_DIGGERC_H

#include <entityx/Entity.h>

struct DiggerC : entityx::Component<DiggerC> {
    DiggerC(int pDigDepth, int pDigInterval) :
                                digDepth(pDigDepth),
                                digInterval(pDigInterval),
                                timeFromLastDig(0) { }

    // static data
    int digDepth;
    int digInterval;

    // dynamic data
    int timeFromLastDig;
};

#endif //LEMMINGS_DIGGERC_H
