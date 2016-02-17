//
// Created by Vasyl.
//

#ifndef LEMMINGS_LAYERC_H
#define LEMMINGS_LAYERC_H

#include <entityx/Entity.h>

template<int Layer>
struct LayerC : entityx::Component<LayerC<Layer>> {
};

#endif //LEMMINGS_LAYERC_H
