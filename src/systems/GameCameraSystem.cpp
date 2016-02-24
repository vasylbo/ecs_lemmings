//
// Created by Vasyl.
//

#include "GameCameraSystem.h"
#include "../components/MouseC.h"
#include "../components/PositionC.h"
#include "../components/CameraC.h"
#include "../Constants.h"
#include "../components/SurfaceC.h"

void GameCameraSystem::update(entityx::EntityManager &entities,
                              entityx::EventManager &events,
                              entityx::TimeDelta dt) {
    auto it = entities.entities_with_components<MouseC>().begin();
    PositionC *mousePos = (*it).component<PositionC>().get();

    it = entities.entities_with_components<CameraC>().begin();
    entityx::Entity camera = *it;
    PositionC *cameraPos = camera.component<PositionC>().get();

    if (mousePos->x > constants::GAME_WIDTH - constants::SCROLL_GAP) {
        it = entities.entities_with_components<SurfaceC>().begin();
        SurfaceC *levelSurface = (*it).component<SurfaceC>().get();
        auto levelWidth = levelSurface->surface->w * levelSurface->scale;
        auto cameraEdge = levelWidth - constants::GAME_WIDTH;

        cameraPos->x += constants::SCROLL_SPEED * dt;
        if (cameraPos->x > cameraEdge) cameraPos->x = cameraEdge;
    } else if (mousePos->x < constants::SCROLL_GAP) {
        cameraPos->x -= constants::SCROLL_SPEED * dt;
        if (cameraPos->x < 0) cameraPos->x = 0;
    }
    printf("camera pos %f \n", cameraPos->x);
}
