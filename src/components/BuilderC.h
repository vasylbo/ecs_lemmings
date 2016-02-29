//
// Created by Vasyl.
//

#ifndef LEMMINGS_BUILDERC_H
#define LEMMINGS_BUILDERC_H

#include <entityx/Entity.h>

struct BuilderC : public entityx::Component<BuilderC> {
    BuilderC():lastFrame(0){};

    int lastFrame;
};
#endif //LEMMINGS_BUILDERC_H
