cmake_minimum_required(VERSION 3.3)
project(lemmings)

# got from http://stackoverflow.com/questions/32857351/linking-sdl2-and-clion
# configure the SDL (cf. "SDL2-2.0.3\i686-w64-mingw32\lib\pkgconfig\sdl2.pc")
# C++ flags
set(SDL2_Flags "-mwindows -Wl,--no-undefined -static-libgcc")
# library paths
set(SDL2_ROOT "${PROJECT_SOURCE_DIR}/libs/SDL2-2.0.4/i686-w64-mingw32")
set(SDL2_Includes "${SDL2_ROOT}/include/SDL2")
set(SDL2_LibDir   "${SDL2_ROOT}/lib")
# imported targets for CMake (cf. https://cmake.org/Wiki/CMake/Tutorials/Exporting_and_Importing_Targets)
add_library(SDL2     STATIC IMPORTED)
add_library(SDL2main STATIC IMPORTED)
set_property(TARGET SDL2     PROPERTY IMPORTED_LOCATION "${SDL2_LibDir}/libSDL2.a")
set_property(TARGET SDL2main PROPERTY IMPORTED_LOCATION "${SDL2_LibDir}/libSDL2main.a")
# the libs to link against
# note: as always with gcc, the order is important...
set(SDL2_Libs mingw32 SDL2 SDL2main m dinput8 dxguid dxerr8 user32 gdi32 winmm imm32 ole32 oleaut32 shell32 version uuid)


# unfortunate find_package does not corectly work on my pc
set(EX_ROOT "${PROJECT_SOURCE_DIR}/libs/entityx")
set(EX_Includes "${EX_ROOT}")
set(EX_LibDir "${EX_ROOT}/bin/Debug")
add_library(EX STATIC IMPORTED)
set_property(TARGET EX PROPERTY IMPORTED_LOCATION ${EX_LibDir}/libentityx-d.a)
set(EX_Libs EX)

set(SDL_IMAGE_ROOT "${PROJECT_SOURCE_DIR}/libs/SDL2_image-2.0.1/i686-w64-mingw32")
set(SDL_IMAGE_Includes "${SDL_IMAGE_ROOT}/include")
set(SDL_IMAGE_LibDir "${SDL_IMAGE_ROOT}/lib")
add_library(SDL_IMAGE STATIC IMPORTED)
set_property(TARGET SDL_IMAGE PROPERTY IMPORTED_LOCATION
        ${SDL_IMAGE_LibDir}/libSDL2_image.a)
set(SDL_IMAGE_Libs SDL_IMAGE)

set(SDL_CONFIG_ROOT "${PROJECT_SOURCE_DIR}/libs/SDL_Config-1.2")
set(SDL_CONFIG_Includes "${SDL_CONFIG_ROOT}/src")
set(SDL_CONFIG_LibDir "${SDL_CONFIG_ROOT}/bin")
add_library(SDL_CONFIG STATIC IMPORTED)
set_property(TARGET SDL_CONFIG PROPERTY IMPORTED_LOCATION
        ${SDL_CONFIG_LibDir}/SDL_Config.a})
set(SDL_CONFIG_Libs SDL_CONFIG)

# configure the project
# include the SDL flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${SDL2_Flags}")
# collect the sources
set(SOURCE_FILES src/main.cpp src/Game.h src/systems/RenderSystem.cpp src/systems/RenderSystem.h src/components/RenderC.h src/components/PositionC.h src/components/SurfaceC.h src/systems/FallSystem.cpp src/systems/FallSystem.h src/components/LemmingC.h src/components/CanFallC.h src/components/GroundedC.h src/systems/MovementSystem.cpp src/systems/MovementSystem.h src/components/SensorC.h src/systems/MoveSensorSystem.cpp src/systems/MoveSensorSystem.h src/utils.cpp src/utils.h src/components/MoveC.h src/components/AssetC.h src/components/AnimationC.h src/systems/AnimationSystem.cpp src/systems/AnimationSystem.h src/systems/StateSystem.cpp src/systems/StateSystem.h src/systems/SpawnSystem.cpp src/systems/SpawnSystem.h src/components/GameC.h src/systems/InputSystem.cpp src/systems/InputSystem.h src/components/InteractiveC.h src/systems/DiggerSystem.cpp src/systems/DiggerSystem.h src/components/DiggerC.h src/events/StateChangeEvent.h src/LemmingType.h src/LemmingBuilder.cpp src/LemmingBuilder.h src/systems/ButtonSystem.cpp src/systems/ButtonSystem.h)
# define the target
add_executable(lemmings ${SOURCE_FILES})
# include the SDL headers
target_include_directories(lemmings SYSTEM PRIVATE ${SDL2_Includes}
        ${EX_Includes} ${SDL_IMAGE_Includes} ${SDL_CONFIG_Includes})
# link against the SDL (and its dependencies)
target_link_libraries(lemmings ${SDL2_Libs} ${EX_Libs} ${SDL_IMAGE_Libs}
        ${SDL_CONFIG})


