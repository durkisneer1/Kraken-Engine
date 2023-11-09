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

# SDL2 Libraries
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES
        "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib"
        "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib"
        "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_image.lib"
        "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_ttf.lib"
    )
else ()
    set(SDL2_LIBRARIES
        "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib"
        "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib"
        "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_image.lib"
        "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_ttf.lib"
    )
endif ()
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

# Link Libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
