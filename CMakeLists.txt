CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
project(SDLTEST)

if(DEFINED ENV{ENNI_WORKSPACE})
message("ENNI Workspace: " $ENV{ENNI_WORKSPACE})
set(ENNI_WORKSPACE $ENV{ENNI_WORKSPACE})
else()
# TODO: Mostrar mensaje de error
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ENNI_WORKSPACE}/sdl2-cmake-scripts/")
message("CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})

IF (WIN32)
set(SDL2_PATH "${ENNI_WORKSPACE}/sdl2-dependencies/SDL2/")
set(SDL2_TTF_PATH "${ENNI_WORKSPACE}/sdl2-dependencies/SDL2_ttf/")
set(SDL2_MIXER_PATH "${ENNI_WORKSPACE}/sdl2-dependencies/SDL2_mixer/")
set(SDL2_IMAGE_PATH "${ENNI_WORKSPACE}/sdl2-dependencies/SDL2_image/")
ENDIF()

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

# Simple SDL Window
add_executable(SDL_Simple_Window SDL_Simple_Window.cpp)
target_link_libraries(SDL_Simple_Window ${SDL2_LIBRARY})

# Test TTF Library
add_executable(SDL_TTF_Test SDL_TTF_Test.cpp)
target_link_libraries(SDL_TTF_Test  ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})