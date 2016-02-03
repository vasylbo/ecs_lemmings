//
// Created by Vasyl.
//

#ifndef LEMMINGS_MOVEC_H
#define LEMMINGS_MOVEC_H


struct MoveC : public entityx::Component<MoveC> {
    MoveC() {};
    MoveC(double pSpeed):speed(pSpeed) {

    }

    double speed;
};
#endif //LEMMINGS_MOVEC_H
