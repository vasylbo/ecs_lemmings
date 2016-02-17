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
#include "events/StateChangeEvent.h"
#include "Constants.h"

LemmingBuilder::LemmingBuilder(ex::EntityManager *pEntities,
                               ex::EventManager *pEvents):
    _entities(pEntities),
    _events(pEvents) {
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
    lemming.assign<DiggerC>(constants::DIG_DEPTH, constants::DIG_INTERVAL);

    return lemming;
}

//todo: find better place for this one
void onLemmingClick(entityx::Entity entity, entityx::EventManager &events) {
    events.emit<StateChangeEvent>(LemmingType::DIGGER, entity);
}

ex::Entity LemmingBuilder::makeWalker(ex::Entity &lemming) {
    lemming.assign<AssetC>("walk.png");
    lemming.assign<AnimationC>("walk", 15, 6, 20, 12, 20, 5);

    lemming.assign<SensorC>(constants::SIGHT, constants::MAP_STEP_HEIGHT);
    lemming.assign<MoveC>(constants::WALK_SPEED);
    // todo: clean up properly
    lemming.assign<InteractiveC>(&onLemmingClick);

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
