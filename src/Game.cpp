#include "Game.h"

Game::Game(SDL_Renderer *pRenderer) :
	_events(),
	_entities(_events),
	_systems(_entities, _events),
	_builder(&_entities, &_events)
{
	_systems.add<RenderSystem>(pRenderer);
	_systems.add<GameCameraSystem>();
	_systems.add<AnimationSystem>();
	_systems.add<MovementSystem>();
	_systems.add<MoveSensorSystem>();
	_systems.add<BuilderSystem>(pRenderer);
	_systems.add<DiggerSystem>(pRenderer);
	_systems.add<FallSystem>();
	_systems.add<StateSystem>(&_builder);
	_systems.add<SpawnSystem>(&_builder);
	_systems.add<StateSwitchButtonSystem>();
	_systems.add<InteractiveSystem>();
	_systems.configure();

	int pngFlags = IMG_INIT_PNG;
	IMG_Init(pngFlags);

	createGame();
	createBack(pRenderer);
	createGui(pRenderer);
}

void Game::createGame()
{
	ex::Entity game = _entities.create();

	game.assign<GameC>(40, constants::DEFAULT_SPAWN_INTERVAL);

	ex::Entity mouse = _entities.create();
	game.assign<PositionC>(0, 0);
	game.assign<MouseC>();

	ex::Entity gameCamera = _entities.create();
	gameCamera.assign<PositionC>(0, 0);
	gameCamera.assign<CameraC>();
}

void Game::createBack(SDL_Renderer *pRenderer)
{
	ex::Entity back = _entities.create();

	SDL_Surface *surface = IMG_Load("level.png");
	int w, h;
	printf("surface %d %d %d \n",
		surface->format->BitsPerPixel,
		surface->pitch / surface->w, surface->pitch);
	SDL_Texture *texture = SDL_CreateTexture(pRenderer,
		surface->format->format,
		SDL_TEXTUREACCESS_STREAMING,
		surface->w, surface->h);
	if (!texture) {
		printf("texture cant be created %s \n", SDL_GetError());
	}

	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

	void *pixels;
	int pitch;
	SDL_LockTexture(texture, nullptr, &pixels, &pitch);
	memcpy(pixels, surface->pixels, (size_t)surface->h * pitch);
	SDL_UnlockTexture(texture);

	back.assign<LayerC<constants::GAME_LAYER>>();
	back.assign<RenderC>(texture, constants::MAP_SCALE);
	back.assign<SurfaceC>(surface, constants::MAP_SCALE,
		constants::MAP_STEP_HEIGHT);
	back.assign<PositionC>(0, 0);
}

void Game::createGui(SDL_Renderer *pRenderer)
{
	ex::Entity button;

	for (int i = 0; i < 5; i++) {
		button = _entities.create();
		button.assign<PositionC>(i * 100, constants::GAME_HEIGHT);
		button.assign<LayerC<constants::GUI_LAYER>>();
		button.assign<RenderC>(generateButtonTexture(pRenderer), 0, 0);
		button.assign<StateSwitchButtonC>(LemmingType::BUILDER);
		button.assign<InteractiveC>();
	}
}

SDL_Texture * Game::generateButtonTexture(SDL_Renderer *pRenderer)
{
	SDL_Texture *texture = SDL_CreateTexture(pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_TARGET,
		80, 80);

	SDL_SetRenderTarget(pRenderer, texture);

	SDL_SetRenderDrawColor(pRenderer, 0xAA, 0xAA, 0xAA, 0xFF);
	SDL_RenderClear(pRenderer);

	SDL_SetRenderTarget(pRenderer, NULL);

	return texture;
}

void Game::update(ex::TimeDelta dt)
{
	_systems.update_all(dt);
}
