//
// Created by Vasyl.
//

#ifndef LEMMINGS_MOVESENSORC_H
#define LEMMINGS_MOVESENSORC_H

#include "entityx/Entity.h"
struct SensorC : entityx::Component<SensorC> {
    SensorC() {};
    SensorC(int pSight, int pVerticalStep):
            sight(pSight), verticalStep(pVerticalStep) {};

    int sight;
    int verticalStep;

    bool leftS;
    bool rightS;
};
#endif //LEMMINGS_MOVESENSORC_H
