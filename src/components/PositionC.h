//
// Created by Vasyl.
//


#ifndef LEMMINGS_POSITIONC_H
#define LEMMINGS_POSITIONC_H

#include <entityx/Entity.h>

struct PositionC : public entityx::Component<PositionC> {
    PositionC() { };
    PositionC(double pX, double pY) : x(pX), y(pY) { };

    double x, y;
};

#endif //LEMMINGS_POSITIONC_H
