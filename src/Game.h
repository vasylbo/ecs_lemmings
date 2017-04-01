//
// Created by Vasyl.
//
#pragma once

#include <SDL_image.h>
#include "SDL_render.h"
#include "entityx/System.h"
#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "components/RenderC.h"
#include "components/PositionC.h"
#include "systems/RenderSystem.h"
#include "components/SurfaceC.h"
#include "components/LemmingC.h"
#include "systems/MovementSystem.h"
#include "components/SensorC.h"
#include "components/MoveC.h"
#include "systems/MoveSensorSystem.h"
#include "systems/AnimationSystem.h"
#include "components/AssetC.h"
#include "components/GameC.h"
#include "components/InteractiveC.h"
#include "components/AnimationC.h"
#include "systems/StateSystem.h"
#include "systems/SpawnSystem.h"
#include "systems/InteractiveSystem.h"
#include "systems/DiggerSystem.h"
#include "systems/FallSystem.h"
#include "entityx/tags/TagsComponent.h"
#include "LemmingBuilder.h"
#include "components/MouseC.h"
#include "components/CameraC.h"
#include "Constants.h"
#include "systems/GameCameraSystem.h"
#include "components/LayerC.h"
#include "systems/StateSwitchButtonSystem.h"
#include "systems/BuilderSystem.h"

namespace ex = entityx;

class Game {
public:
    explicit Game(SDL_Renderer *pRenderer);

    void createGame();
    void createBack(SDL_Renderer *pRenderer);
    void createGui(SDL_Renderer *pRenderer);

	// not belongs here
    SDL_Texture *generateButtonTexture(SDL_Renderer *pRenderer);

    void update(ex::TimeDelta dt);;

    bool isActive() {
        // do something
        return true;
    };

    ~Game() {
    };

private:
    LemmingBuilder _builder;
    ex::EntityManager _entities;
    ex::SystemManager _systems;
    ex::EventManager _events;
};


