//
// Created by Vasyl.
//

#ifndef LEMMINGS_BUTTONC_H
#define LEMMINGS_BUTTONC_H

#include <entityx/Entity.h>

enum ButtonType {
    ASSIGN_JOB
};
struct ButtonC : public entityx::Component<ButtonC> {
    ButtonC(ButtonType pType):type(pType){};

    ButtonType type;
};
#endif //LEMMINGS_BUTTONC_H
