cmake_minimum_required(VERSION 3.26)
project(DurkGame)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

# Header Files
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include/SDL2")
include_directories(
    ${SDL2_INCLUDE_DIRS}
    include
    include/SDL2
)

# Source Files
add_library(${PROJECT_NAME} STATIC
    src/durk_game.cpp
    src/display.cpp
    src/clock.cpp
    src/texture.cpp
    src/rect.cpp
    src/input.cpp
    src/font.cpp
    src/character.cpp
    src/math.cpp
)

# Link Libraries
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
