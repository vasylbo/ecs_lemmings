//
// Created by Vasyl.
//

#ifndef LEMMINGS_BUTTONC_H
#define LEMMINGS_BUTTONC_H

#include <entityx/Entity.h>
#include "../LemmingType.h"

enum ButtonState {
    SELECTED, IDLE
};

struct StateSwitchButtonC : public entityx::Component<StateSwitchButtonC> {
    StateSwitchButtonC(LemmingType pType):
            stateToSwitch(pType),
            state(ButtonState::IDLE){};

    // static data
    LemmingType stateToSwitch;

    // dynamic data
    ButtonState state;
};
#endif //LEMMINGS_BUTTONC_H
