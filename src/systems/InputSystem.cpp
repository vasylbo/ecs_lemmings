//
// Created by Vasyl.
//

#include <SDL_events.h>
#include "InputSystem.h"
#include "../components/RenderC.h"
#include "../components/PositionC.h"
#include "../components/InteractiveC.h"

void InputSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events, entityx::TimeDelta dt) {
    SDL_Event event;
    bool mouseUp = false;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                _currentPos.x = event.motion.x;
                _currentPos.y = event.motion.y;
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
        for (entityx::Entity entity : entities
                .entities_with_components<PositionC, RenderC, InteractiveC>()) {
            positionC = entity.component<PositionC>().get();
            renderC = entity.component<RenderC>().get();
            interactiveC = entity.component<InteractiveC>() .get();

            sprite.x = (int) (positionC->x - renderC->anchor.x);
            sprite.y = (int) (positionC->y - renderC->anchor.y);
            sprite.h = renderC->h;
            sprite.w = renderC->w;

            if (SDL_PointInRect(&_currentPos, &sprite)) {
                // todo: do depth search to select only upper one
                (*interactiveC->onClick)(entity, events);

                return;
            }
        }
    }
}
