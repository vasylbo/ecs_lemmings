//
// Created by Vasyl.
//

#ifndef LEMMINGS_GAMEC_H
#define LEMMINGS_GAMEC_H

#include "entityx/entityx.h"

struct GameC : public entityx::Component<GameC> {
    GameC(int pLemmingsToCreate, int pLemmingInterval) :
            lemmingsToCreate(pLemmingsToCreate),
            lemmingInterval(pLemmingInterval),
            timeFromLastLemming(0),
            lemmingsCreated(0) { }

    // static data
    const int lemmingInterval;
    const int lemmingsToCreate;

    // dynamic data (to lazy to separate)
    int timeFromLastLemming;
    int lemmingsCreated;

    // can have raw entity here, because its only an id holder
    entityx::Entity selectedButton;
};

#endif //LEMMINGS_GAMEC_H
