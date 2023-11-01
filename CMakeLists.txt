cmake_minimum_required(VERSION 3.26)
project(DurkGame)

set(CMAKE_CXX_STANDARD 20)

include_directories(
    include
    include/SDL2
)
link_directories(lib/SDL2)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)

add_library(${PROJECT_NAME} STATIC
    src/durk_game.cpp
    src/display.cpp
    src/clock.cpp
    src/texture.cpp
    src/rect.cpp
    src/input.cpp
        src/font.cpp
)

target_link_libraries(${PROJECT_NAME}
    SDL2
    SDL2_image
    SDL2_ttf
)
