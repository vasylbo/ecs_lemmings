//
// Created by Vasyl.
//

#ifndef LEMMINGS_INTERACTIVEC_H
#define LEMMINGS_INTERACTIVEC_H

#include <entityx/Entity.h>

// supposed to be only tag to show that object is interactive to mouse
struct InteractiveC : entityx::Component<InteractiveC> {
    InteractiveC() {}
};
#endif //LEMMINGS_INTERACTIVEC_H
