//
// Created by Vasyl.
//

#ifndef LEMMINGS_MOUSEC_H
#define LEMMINGS_MOUSEC_H

#include <entityx/Entity.h>

struct MouseC : public entityx::Component<MouseC> {
    MouseC() {};

    // just a tag component showing that entity is a mouse
};
#endif //LEMMINGS_MOUSEC_H
