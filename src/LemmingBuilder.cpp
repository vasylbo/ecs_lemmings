//
// Created by Vasyl.
//

#include "LemmingBuilder.h"
#include "components/PositionC.h"
#include "components/CanFallC.h"
#include "components/AssetC.h"
#include "components/AnimationC.h"
#include "components/LemmingC.h"
#include "components/SensorC.h"
#include "components/MoveC.h"
#include "components/InteractiveC.h"
#include "components/DiggerC.h"

LemmingBuilder::LemmingBuilder(ex::EntityManager *pEntities):
    _entities(pEntities){

}

ex::Entity LemmingBuilder::makeLemming(int pX, int pY) {
    ex::Entity lemming = _entities->create();

    lemming.assign<CanFallC>();
    lemming.assign<PositionC>(pX, pY);
    lemming.assign<LemmingC>();

    return lemming;
}

ex::Entity LemmingBuilder::makeFalling(ex::Entity &lemming) {
    lemming.assign<AssetC>("fall.png");
    lemming.assign<AnimationC>("fall", 15, 6, 18, 12, 18, 4);

    return lemming;
}

ex::Entity LemmingBuilder::makeDigger(ex::Entity &lemming) {
    lemming.assign<AssetC>("dig.png");
    lemming.assign<AnimationC>("dig", 15, 16, 27, 32, 32, 16);
    lemming.assign<DiggerC>(4, 600);


    return lemming;
}

ex::Entity LemmingBuilder::makeWalker(ex::Entity &lemming) {
    lemming.assign<AssetC>("walk.png");
    lemming.assign<AnimationC>("walk", 15, 6, 20, 12, 20, 5);

    lemming.assign<SensorC>(5, 5);
    lemming.assign<MoveC>(15);
    lemming.assign<InteractiveC>();

    return lemming;
}

void LemmingBuilder::cleanLemming(ex::Entity &lemming) {
    lemming.remove<AssetC>();
    lemming.remove<AnimationC>();
    if (lemming.has_component<SensorC>()) {
        lemming.remove<SensorC>();
        lemming.remove<MoveC>();
        lemming.remove<InteractiveC>();
    }
    if (lemming.has_component<DiggerC>()) {
        lemming.remove<DiggerC>();
    }
}
