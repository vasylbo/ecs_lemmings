//
// Created by Vasyl.
//

#include <SDL_events.h>
#include "InteractiveSystem.h"
#include "../components/RenderC.h"
#include "../components/PositionC.h"
#include "../components/InteractiveC.h"
#include "../components/MouseC.h"
#include "../components/CameraC.h"

void InteractiveSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events, entityx::TimeDelta dt) {
    SDL_Event event;
    bool mouseUp = false;
    auto it = entities.entities_with_components<MouseC>().begin();
    PositionC *mousePos = (*it).component<PositionC>().get();
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                mousePos->x = event.motion.x;
                mousePos->y = event.motion.y;
                break;
            case SDL_MOUSEBUTTONUP:
                mouseUp = true;
                break;
            default:
//                printf("event %d \n", event.type);
                break;
        }
    }

    if (mouseUp) {
        PositionC *positionC;
        RenderC *renderC;
        InteractiveC *interactiveC;
        SDL_Rect sprite;
        SDL_Point mousePoint = {(int) mousePos->x, (int) mousePos->y};
        it = entities.entities_with_components<CameraC>().begin();
        PositionC *cameraPos = (*it).component<PositionC>().get();

        for (entityx::Entity entity : entities
                .entities_with_components<PositionC, RenderC, InteractiveC>()) {
            positionC = entity.component<PositionC>().get();
            renderC = entity.component<RenderC>().get();
            interactiveC = entity.component<InteractiveC>() .get();

            sprite.x = (int) (positionC->x - renderC->anchor.x - cameraPos->x);
            sprite.y = (int) (positionC->y - renderC->anchor.y - cameraPos->y);
            sprite.h = renderC->h;
            sprite.w = renderC->w;

            if (SDL_PointInRect(&mousePoint, &sprite)) {
                // todo: do depth search to select only upper one
                (*interactiveC->onClick)(entity, events);

                return;
            }
        }
    }
}
