cmake_minimum_required(VERSION 3.10)
project(Kraken)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -m64")

include_directories(include)
include_directories(C:/SDL2/include)
include_directories(include/tmxlite)

file(GLOB SOURCES "src/*.cpp")

add_library(Kraken ${SOURCES})
