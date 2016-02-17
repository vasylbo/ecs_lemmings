//
// Created by Vasyl.
//

#include "GameCameraSystem.h"
#include "../components/MouseC.h"
#include "../components/PositionC.h"
#include "../components/CameraC.h"
#include "../Constants.h"

void GameCameraSystem::update(entityx::EntityManager &entities,
                              entityx::EventManager &events,
                              entityx::TimeDelta dt) {
    auto it = entities.entities_with_components<MouseC>().begin();
    PositionC *mousePos = (*it).component<PositionC>().get();

    it = entities.entities_with_components<CameraC>().begin();
    entityx::Entity camera = *it;
    PositionC *cameraPos = camera.component<PositionC>().get();

    //todo: dont scroll of the edges
    if (mousePos->x > constants::GAME_WIDTH - constants::SCROLL_GAP) {
        cameraPos->x -= constants::SCROLL_SPEED * dt;
    } else if (mousePos->x < constants::SCROLL_GAP) {
        cameraPos->x += constants::SCROLL_SPEED * dt;
    }
}
