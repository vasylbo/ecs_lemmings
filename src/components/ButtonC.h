//
// Created by Vasyl.
//

#ifndef LEMMINGS_BUTTONC_H
#define LEMMINGS_BUTTONC_H

#include <entityx/Entity.h>

enum ButtonType {
    ASSIGN_JOB
};

enum ButtonState {
    SELECTED, IDLE
};

struct ButtonC : public entityx::Component<ButtonC> {
    ButtonC(ButtonType pType):
            type(pType),
            state(ButtonState::IDLE){};

    // static data
    ButtonType type;

    // dynamic data
    ButtonState state;
};
#endif //LEMMINGS_BUTTONC_H
