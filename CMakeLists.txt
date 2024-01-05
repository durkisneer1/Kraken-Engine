cmake_minimum_required(VERSION 3.10)
project(Kraken LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -m64")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

include_directories(include)
#include_directories(C:/SDL2/include)
include_directories(include/tmxlite)

include(FetchContent)

message(STATUS "fetching SDL")
FetchContent_Declare(SDL
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG "release-2.28.5")
message(STATUS "SDL fetched")

message(STATUS "fetching SDL_image")
FetchContent_Declare(SDL_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG "release-2.8.2")
message(STATUS "SDL_image fetched")

message(STATUS "fetching SDL_ttf")
FetchContent_Declare(SDL_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG "release-2.20.2")
message(STATUS "SDL_ttf fetched")

message(STATUS "fetching SDL_mixer")
FetchContent_Declare(SDL_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG "release-2.6.3")
message(STATUS "SDL_mixer fetched")

FetchContent_MakeAvailable(SDL SDL_image SDL_ttf SDL_mixer)

file(GLOB SOURCES "src/*.cpp")
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/../include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)

install(TARGETS ${PROJECT_NAME})
