cmake_minimum_required(VERSION 3.16)
set(LIBRARY "Kraken")
set(TESTING "Kraken_Test")
project(${TESTING} LANGUAGES CXX)
project(${LIBRARY} LANGUAGES CXX)

# default log level to WARN (3) if not explicitly set with cmake ... -DLOG_LEVEL=number
if(NOT DEFINED LOG_LEVEL)
    message(STATUS "Setting Log Level to 3")
    set(LOG_LEVEL 3)
else(NOT DEFINED LOG_LEVEL)
    message(STATUS "Log Level set to " ${LOG_LEVEL})
endif(NOT DEFINED LOG_LEVEL)

file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "test/*.cpp")
add_library(${LIBRARY} ${SOURCES})
add_executable(${TESTING} EXCLUDE_FROM_ALL ${SOURCES} ${TESTS})

target_compile_definitions( ${LIBRARY} PUBLIC LOG_LEVEL=${LOG_LEVEL} )
target_compile_definitions( ${TESTING} PUBLIC LOG_LEVEL=${LOG_LEVEL} )

set_target_properties( ${LIBRARY} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
   ${CMAKE_SOURCE_DIR}/bin )
set_target_properties( ${LIBRARY} PROPERTIES LIBRARY_OUTPUT_DIRECTORY
   ${CMAKE_SOURCE_DIR}/bin )

set_target_properties( ${TESTING} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
   ${CMAKE_SOURCE_DIR}/bin )
set_target_properties( ${TESTING} PROPERTIES LIBRARY_OUTPUT_DIRECTORY
   ${CMAKE_SOURCE_DIR}/bin )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /std:c++latest")
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)
include(FetchContent)
include(GoogleTest)

# ================ <deps> ==============

set(SDL_GIT_VERSION release-2.28.5)
set(SDL_TTF_GIT_VERSION release-2.20.2)
set(SDL_IMAGE_GIT_VERSION release-2.8.2)
set(SDL_MIXER_GIT_VERSION release-2.6.3)
set(TMX_LITE_VERSION v1.4.4)

###############
#    SDL2     #
###############

set(SDL2_DISABLE_INSTALL OFF CACHE BOOL "Disable installation of SDL2") # i forget why this is necessary but im assuming it wont work without
set(SDL_STATIC OFF CACHE BOOL "Build a static library")
set(SDL_SHARED ON CACHE BOOL "Build a shared library")
set(SDL_TEST OFF CACHE BOOL "Build the test programs")
set(SDL_STATIC_PIC OFF CACHE BOOL "Build static libraries with PIC (Position Independent Code)")
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        ${SDL_GIT_VERSION}
    GIT_PROGRESS TRUE
)
# set(SDL_SHARED OFF CACHE BOOL "Build a shared library")
FetchContent_MakeAvailable(SDL2)
target_include_directories(${LIBRARY} PRIVATE ${SDL2_SOURCE_DIR}/include)
target_include_directories(${TESTING} PRIVATE ${SDL2_SOURCE_DIR}/include)

###############
#  SDL2_ttf   #
###############

set(BUILD_SHARED_LIBS ON CACHE BOOL "Build the library as a shared library")
# set(SDL2TTF_BUILD_SHARED_LIBS OFF CACHE BOOL "Build the library as a shared library")
set(SDL2TTF_SAMPLES OFF CACHE BOOL "Build the SDL2_ttf sample program(s)")
# let it know it needs to get its vendored deps
set(SDL2TTF_VENDORED ON CACHE BOOL "Use the vendored version of FreeType and HarfBuzz")
FetchContent_Declare(
    SDL2_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf
    GIT_TAG        ${SDL_TTF_GIT_VERSION}
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2_ttf)
target_include_directories(${LIBRARY} PRIVATE ${SDL2_ttf_SOURCE_DIR}) # include is in the root of the repo
target_include_directories(${TESTING} PRIVATE ${SDL2_ttf_SOURCE_DIR}) # include is in the root of the repo

###############
#  SDL_image  #
###############

FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG        ${SDL_IMAGE_GIT_VERSION}
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2_image)
target_include_directories(${LIBRARY} PRIVATE ${SDL2_image_SOURCE_DIR}/include)
target_include_directories(${TESTING} PRIVATE ${SDL2_image_SOURCE_DIR}/include)

###############
#  SDL_mixer  #
###############

# disable annoying codecs we dont need that require dependencies i dont have
set(SDL2MIXER_OPUS OFF CACHE BOOL "Enable Opus support")
set(SDL2MIXER_FLAC OFF CACHE BOOL "Enable FLAC support")
set(SDL2MIXER_MOD OFF CACHE BOOL "Enable Mod support")
set(SDL2MIXER_MIDI OFF CACHE BOOL "Enable MIDI support")

# mp3 enabled
set(SDL2MIXER_MP3 ON CACHE BOOL "Enable MP3 support")

# wav enabled
set(SDL2MIXER_WAV ON CACHE BOOL "Enable WAV support")

FetchContent_Declare(
    SDL2_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG        ${SDL_MIXER_GIT_VERSION}
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2_mixer)
target_include_directories(${LIBRARY} PRIVATE ${SDL2_mixer_SOURCE_DIR}/include)
target_include_directories(${TESTING} PRIVATE ${SDL2_mixer_SOURCE_DIR}/include)

#############
#  tmxlite  #
#############

set(TMXLITE_STATIC_LIB OFF CACHE BOOL "Build tmxlite as static")
FetchContent_Declare(
  tmxlite
  GIT_REPOSITORY https://github.com/fallahn/tmxlite.git
  GIT_TAG ${TMX_LITE_VERSION}
  GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(tmxlite)

list(APPEND CPP_INCLUDE_DIRS ${tmxlite_SOURCE_DIR}/tmxlite/include)
add_subdirectory(${tmxlite_SOURCE_DIR}/tmxlite ${tmxlite_BINARY_DIR})
list(APPEND CPP_LIBS "tmxlite")

target_include_directories(${LIBRARY} PRIVATE ${tmxlite_SOURCE_DIR}/tmxlite/include)
target_include_directories(${TESTING} PRIVATE ${tmxlite_SOURCE_DIR}/tmxlite/include)

###########
#  gtest  #
###########

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
    GIT_PROGRESS TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ================ </deps> ==============

enable_testing()

if (WIN32)
  add_custom_command(
    TARGET ${TESTING}
    COMMENT "Copy gtest dlls"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/bin/libgtest.dll ${CMAKE_SOURCE_DIR}/bin/
    VERBATIM
  )
endif()
if (WIN32)
  add_custom_command(
    TARGET ${TESTING}
    COMMENT "Copy gmock dlls"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/bin/libgmock.dll ${CMAKE_SOURCE_DIR}/bin/
    VERBATIM
  )
endif()
if (WIN32)
  add_custom_command(
    TARGET ${TESTING}
    COMMENT "Copy gtest_main dlls"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/bin/libgtest_main.dll ${CMAKE_SOURCE_DIR}/bin/
    VERBATIM
  )
endif()
if (WIN32)
  add_custom_command(
    TARGET ${TESTING}
    COMMENT "Copy gmock_main dlls"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/bin/libgmock_main.dll ${CMAKE_SOURCE_DIR}/bin/
    VERBATIM
  )
endif()

target_link_libraries(${LIBRARY} PRIVATE SDL2 SDL2_image SDL2_ttf SDL2_mixer tmxlite)
target_link_libraries(${TESTING} PRIVATE SDL2 SDL2_image SDL2_ttf SDL2_mixer tmxlite gtest gtest_main)

target_include_directories(${LIBRARY} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${TESTING} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${TESTING} PRIVATE ${tmxlite_SOURCE_DIR}/../googletest-src/googletest/include)
gtest_discover_tests(${TESTING})

install(TARGETS ${LIBRARY})
