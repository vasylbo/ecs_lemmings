//
// Created by Vasyl.
//

#ifndef LEMMINGS_ASSET_H
#define LEMMINGS_ASSET_H

#include "entityx/Entity.h"

struct AssetC : public entityx::Component<AssetC> {
    AssetC() {};
    AssetC(const char *pId):id(pId) {};

    const char *id;
};
#endif //LEMMINGS_ASSET_H
