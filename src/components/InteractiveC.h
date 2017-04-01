//
// Created by Vasyl.
//

#ifndef LEMMINGS_INTERACTIVEC_H
#define LEMMINGS_INTERACTIVEC_H

#include <entityx/Entity.h>
#include "../systems/InteractiveSystem.h"

struct InteractiveC : entityx::Component<InteractiveC> {
	const bool needsMouseOverCheck;

	bool hasBeenClicked;
	bool hasMouseOver;

    InteractiveC(bool pNeedsOverCheck = false): 
		needsMouseOverCheck(pNeedsOverCheck), 
		hasBeenClicked(false) {}
};
#endif //LEMMINGS_INTERACTIVEC_H
