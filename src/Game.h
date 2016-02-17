//
// Created by Vasyl.
//
#pragma once

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
#include "components/AnimationC.h"
#include "systems/StateSystem.h"
#include "systems/SpawnSystem.h"
#include "systems/InputSystem.h"
#include "systems/DiggerSystem.h"
#include "systems/FallSystem.h"
#include "entityx/tags/TagsComponent.h"
#include "LemmingBuilder.h"
#include "components/MouseC.h"
#include "components/CameraC.h"
#include "Constants.h"
#include "systems/GameCameraSystem.h"
#include "components/LayerC.h"

namespace ex = entityx;

class Game {
public:
    //    move implementation to *.cpp
    explicit Game(SDL_Renderer *pRenderer) :
            _events(),
            _entities(_events),
            _systems(_entities, _events),
            _builder(&_entities, &_events){
        _systems.add<RenderSystem>(pRenderer);
        _systems.add<GameCameraSystem>();
        _systems.add<AnimationSystem>();
        _systems.add<MovementSystem>();
        _systems.add<MoveSensorSystem>();
        _systems.add<DiggerSystem>(pRenderer);
        _systems.add<FallSystem>();
        _systems.add<StateSystem>(&_builder);
        _systems.add<SpawnSystem>(&_builder);
        _systems.add<InputSystem>();
        _systems.configure();

        createGame();
        createBack(pRenderer);
    }

    void createGame() {
        ex::Entity game = _entities.create();

        game.assign<GameC>(40, constants::DEFAULT_SPAWN_INTERVAL);

        ex::Entity mouse = _entities.create();
        game.assign<PositionC>(0, 0);
        game.assign<MouseC>();

        ex::Entity gameCamera = _entities.create();
        gameCamera.assign<PositionC>(0, 0);
        gameCamera.assign<CameraC>();
    }

    void createBack(SDL_Renderer *pRenderer) {
        ex::Entity back = _entities.create();

        SDL_Surface *surface = SDL_LoadBMP("level.bmp");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);

        back.assign<LayerC<constants::GAME_LAYER>>();
        back.assign<RenderC>(texture, constants::MAP_SCALE);
        back.assign<SurfaceC>(surface, constants::MAP_SCALE,
                              constants::MAP_STEP_HEIGHT);
        back.assign<PositionC>(0, 0);
    }

    void update(ex::TimeDelta dt) {
        _systems.update_all(dt);
    };

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


