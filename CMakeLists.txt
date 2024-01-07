cmake_minimum_required(VERSION 3.10)
project(Kraken LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -m64")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(include)
# include_directories(include/tmxlite)
include(FetchContent)

# ================ <deps> ==============

set(FREETYPE_GIT_VERSION VER-2-13-2)
set(SDL_GIT_VERSION release-2.28.5)
set(SDL_TTF_GIT_VERSION release-2.20.2)
set(SDL_IMAGE_GIT_VERSION release-2.8.2)
set(SDL_MIXER_GIT_VERSION release-2.6.3)
set(TMX_LITE_VERSION v1.4.4)

set(SDL2MIXER_VENDORED TRUE)

if (NOT freetype_FOUND) # If there's none, fetch and build
  include(FetchContent)
  FetchContent_Declare(
    freetype
    GIT_REPOSITORY https://github.com/freetype/freetype.git
    GIT_TAG ${FREETYPE_GIT_VERSION}
    #GIT_TAG VER-2-10-4
  )
  FetchContent_GetProperties(freetype)
  if (NOT freetype_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(freetype)
    message("freetype_LIBRARY: " ${freetype_LIBRARY}) # fail but define in cmake
    message("freetype_INCLUDE_DIR: " ${freetype_INCLUDE_DIR}) #pass
    message("freetype_SOURCE_DIR: " ${freetype_SOURCE_DIR}) # pass
    message("freetype_BINARY_DIR: " ${freetype_BINARY_DIR}) # pass

    #set(FT_WITH_ZLIB OFF CACHE BOOL "" FORCE)
    #set(FT_WITH_BZIP2 OFF CACHE BOOL "" FORCE)
    #set(FT_WITH_PNG OFF CACHE BOOL "" FORCE)
    #set(FT_WITH_HARFBUZZ OFF CACHE BOOL "" FORCE)
    #set(FT_WITH_BROTLI OFF CACHE BOOL "" FORCE)

    # build freetype
    list(APPEND CPP_INCLUDE_DIRS ${freetype_SOURCE_DIR}/include)
    list(APPEND CPP_INCLUDE_DIRS ${freetype_BINARY_DIR}/include)
    list(APPEND CPP_HEADER_FILES ${freetype_SOURCE_DIR}/include/ft2build.h)
    
    list(APPEND FREETYPE_INCLUDE_DIRS ${freetype_SOURCE_DIR}/include)
    list(APPEND FREETYPE_INCLUDE_DIRS ${freetype_BINARY_DIR}/include)

    set(FREETYPE_LIBRARY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

    #link_directories(${sdl_ttf_BINARY_DIR}/Debug)# this will look for libs files.
    add_subdirectory(${freetype_SOURCE_DIR} ${freetype_BINARY_DIR}) #add to build in sub dir
    add_library(Freetype::Freetype ALIAS freetype)

  endif()
endif()

message("sdl_FOUND:" ${SDL_FOUND})
if (NOT sdl_FOUND) # If there's none, fetch and build sdl
  include(FetchContent)
  FetchContent_Declare(
    sdl
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG ${SDL_GIT_VERSION}
  )
  FetchContent_GetProperties(sdl)
  if (NOT SDL2_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sdl)
    #message("SDL_LIBRARY: " ${sdl_LIBRARY}) # fail but define in cmake
    #message("SDL_INCLUDE_DIR: " ${sdl_INCLUDE_DIR}) #pass
    #message("sdl_SOURCE_DIR: " ${sdl_SOURCE_DIR}) # pass
    #message("sdl_BINARY_DIR: " ${sdl_BINARY_DIR}) # pass
    # build SDL2
    list(APPEND CPP_INCLUDE_DIRS ${sdl_SOURCE_DIR}/include)
    #include_directories(${sdl2_BINARY_DIR}/include) 

    link_directories(${PROJECT_BINARY_DIR}/Debug)
    add_subdirectory(${sdl_SOURCE_DIR} ${sdl_BINARY_DIR})
    
    #needed for sub modules
    list(APPEND SDL2_INCLUDE_DIR ${sdl_SOURCE_DIR}/include)

    list(APPEND SDL2_LIBRARIES ${PROJECT_SOURCE_DIR}/build/Debug/SDL2maind.lib)
    list(APPEND SDL2_LIBRARIES ${PROJECT_SOURCE_DIR}/build/Debug/SDL2-staticd.lib)
    list(APPEND SDL2_LIBRARIES ${PROJECT_SOURCE_DIR}/build/Debug/SDL2d.lib)

    #list(APPEND SDL2_LIBRARY ${PROJECT_BINARY_DIR}/Debug/SDL2maind.lib)
    #list(APPEND SDL2_LIBRARY ${PROJECT_BINARY_DIR}/Debug/SDL2-staticd.lib)
    #list(APPEND SDL2_LIBRARY ${PROJECT_BINARY_DIR}/Debug/SDL2d.lib)

    #list(APPEND SDL2_LIB ${PROJECT_SOURCE_DIR}/build/Debug/SDL2maind.lib)
    #list(APPEND SDL2_LIB ${PROJECT_SOURCE_DIR}/build/Debug/SDL2-staticd.lib)
    #list(APPEND SDL2_LIB ${PROJECT_SOURCE_DIR}/build/Debug/SDL2d.lib)

    list(APPEND CPP_LIBS "SDL2main")
    list(APPEND CPP_LIBS "SDL2-static")
    add_library(SDL2::SDL2 ALIAS SDL2)
    add_library(SDL2::SDL2-static ALIAS SDL2-static)

  endif()
endif()

set(SDL2TTF_INSTALL OFF CACHE STRING "" FORCE)

if (NOT sdl_ttf_FOUND) # If there's none, fetch and build sdl
  include(FetchContent)
  FetchContent_Declare(
    sdl_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG ${SDL_TTF_GIT_VERSION}
  )
  FetchContent_GetProperties(sdl_ttf)
  if (NOT sdl_ttf_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sdl_ttf)
    #message("sdl_ttf_LIBRARY: " ${sdl_ttf_LIBRARY}) # fail but define in cmake
    #message("sdl_ttf_INCLUDE_DIR: " ${sdl_ttf_INCLUDE_DIR}) #pass
    #message("sdl_ttf_SOURCE_DIR: " ${sdl_ttf_SOURCE_DIR}) # pass
    #message("sdl_ttf_BINARY_DIR: " ${sdl_ttf_BINARY_DIR}) # pass
    # build SDL2
    #list(APPEND CPP_INCLUDE_DIRS ${sdl_image_SOURCE_DIR}/include)
    add_subdirectory(${sdl_ttf_SOURCE_DIR} ${sdl_ttf_BINARY_DIR})
    #list(APPEND CPP_LIBS "sdl_ttf")
  endif()
endif()

if (NOT sdl_image_FOUND) # If there's none, fetch and build sdl
  include(FetchContent)
  FetchContent_Declare(
    sdl_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG ${SDL_IMAGE_GIT_VERSION}
  )
  FetchContent_GetProperties(sdl_image)
  if (NOT sdl_image_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sdl_image)
    #message("sdl_image_LIBRARY: " ${sdl_image_LIBRARY}) # fail but define in cmake
    #message("sdl_image_INCLUDE_DIR: " ${sdl_image_INCLUDE_DIR}) #pass
    #message("sdl_image_SOURCE_DIR: " ${sdl_image_SOURCE_DIR}) # pass
    #message("sdl_image_BINARY_DIR: " ${sdl_image_BINARY_DIR}) # pass
    set(SUPPORT_JPG OFF CACHE BOOL "" FORCE)
    set(SUPPORT_PNG ON CACHE BOOL "" FORCE)
    set(BUILD_SHOWIMAGE OFF CACHE BOOL "" FORCE)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    # BUILD_SHARED_LIBS OFF is LIB

    # build sdl2 image
    #list(APPEND CPP_INCLUDE_DIRS ${sdl_image_SOURCE_DIR}/include)
    add_subdirectory(${sdl_image_SOURCE_DIR} ${sdl_image_BINARY_DIR})
    #list(APPEND CPP_LIBS "SDL2_image")
  endif()
endif()

if (NOT sdl_mixer_FOUND) # If there's none, fetch and build sdl
  include(FetchContent)
  FetchContent_Declare(
    sdl_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG ${SDL_MIXER_GIT_VERSION}
  )
  FetchContent_GetProperties(sdl_mixer)

  if (NOT sdl_mixer_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sdl_mixer)
    #message("sdl_mixer_LIBRARY: " ${sdl_mixer_LIBRARY}) # fail but define in cmake
    #message("sdl_mixer_INCLUDE_DIR: " ${sdl_mixer_INCLUDE_DIR}) #pass
    #message("sdl_mixer_SOURCE_DIR: " ${sdl_mixer_SOURCE_DIR}) # pass
    #message("sdl_mixer_BINARY_DIR: " ${sdl_mixer_BINARY_DIR}) # pass

    set(ANDROID ON)
    set(SUPPORT_OGG ON CACHE BOOL "" FORCE)

    # build SDL2 MIXER
    list(APPEND CPP_INCLUDE_DIRS ${sdl_mixer_SOURCE_DIR}/include)
    add_subdirectory(${sdl_mixer_SOURCE_DIR} ${sdl_mixer_BINARY_DIR})
    list(APPEND CPP_LIBS "SDL2_mixer")
  endif()
endif()

FetchContent_Declare(
  tmxlite
  GIT_REPOSITORY https://github.com/fallahn/tmxlite.git
  GIT_TAG ${TMX_LITE_VERSION}
)
set(tmxlite_SOURCE_DIR ${tmxlite_SOURCE_DIR}/tmxlite)

FetchContent_MakeAvailable(tmxlite)
list(APPEND CPP_INCLUDE_DIRS ${tmxlite_SOURCE_DIR}/tmxlite/include)
add_subdirectory(${tmxlite_SOURCE_DIR}/tmxlite ${tmxlite_BINARY_DIR})
list(APPEND CPP_LIBS "tmxlite")

# ================ </deps> ==============

file(GLOB SOURCES "src/*.cpp")
add_library(${PROJECT_NAME} ${SOURCES})

FetchContent_MakeAvailable(SDL SDL_image SDL_ttf SDL_mixer)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2_image SDL2_ttf SDL2_mixer)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/../include)
install(TARGETS ${PROJECT_NAME})