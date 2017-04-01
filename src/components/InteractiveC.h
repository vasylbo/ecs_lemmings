//
// Created by Vasyl.
//

#ifndef LEMMINGS_INTERACTIVEC_H
#define LEMMINGS_INTERACTIVEC_H

#include <entityx/Entity.h>
#include "../systems/InteractiveSystem.h"

struct InteractiveC : entityx::Component<InteractiveC> {
	bool hasBeenClicked;

    InteractiveC(): hasBeenClicked(false) {}
};
#endif //LEMMINGS_INTERACTIVEC_H
