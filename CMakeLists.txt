cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(CMAKE_SYSTEM_VERSION 10.0 CACHE STRING "" FORCE)

project(KrakenEngine CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    CACHE STRING "" FORCE
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message(WARNING "No implementation of use_package. Create yours. "
                    "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                    "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)
include(FetchContent)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################
set(PROJECT_NAME KrakenEngine)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Cache.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Constants.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Draw.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ErrorLogger.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Font.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Input.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/KrakenEngine.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Math.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Music.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Overflow.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Rect.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Sound.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Texture.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Time.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Window.hpp"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "${CMAKE_CURRENT_SOURCE_DIR}/src/cache.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/draw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/font.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/input.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/music.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/overflow.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/rect.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/sound.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/texture.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/time.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE WordleSDL)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "${OUTPUT_DIRECTORY}KrakenEngine$ENV{TargetExt}"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /std:c++17
            >
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /DEBUG;
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "SDL2;"
            "SDL2_image;"
            "SDL2_mixer;"
            "SDL2_ttf"
        ">"
    )
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

################################################################################
# Post build events
################################################################################
enable_testing()
find_library(SDL2_LIBRARY NAME SDL2 PATHS "C:/SDL/lib")
find_library(SDL2_IMAGE_LIBRARY NAME SDL2_image PATHS "C:/SDL/lib")
find_library(SDL2_MIXER_LIBRARY NAME SDL2_mixer PATHS "C:/SDL/lib")
find_library(SDL2_TTF_LIBRARY NAME SDL2_ttf PATHS "C:/SDL/lib")

add_executable(
    test_Math
    tests/test_Math.cpp
    ${ALL_FILES}
)
target_link_libraries(
	test_Math PRIVATE
	GTest::gtest_main
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
    ${SDL2_TTF_LIBRARY}
)

add_executable(
	test_Overflow
	tests/test_Overflow.cpp
    ${ALL_FILES}
)
target_link_libraries(
	test_Overflow PRIVATE
	GTest::gtest_main
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
    ${SDL2_TTF_LIBRARY}
)

add_executable(
	test_Window
	tests/test_Window.cpp
    ${ALL_FILES}
)
target_link_libraries(
	test_Window PRIVATE
	GTest::gtest_main
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
    ${SDL2_TTF_LIBRARY}
)

target_include_directories(test_Math PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include" "C:/SDL/include")
target_include_directories(test_Overflow PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include" "C:/SDL/include")
target_include_directories(test_Window PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include" "C:/SDL/include")

target_compile_features(test_Math PRIVATE cxx_std_17)
target_compile_features(test_Overflow PRIVATE cxx_std_17)
target_compile_features(test_Window PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(test_Math)
gtest_discover_tests(test_Overflow)
gtest_discover_tests(test_Window)
