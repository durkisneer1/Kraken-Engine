
# Meson Project Details
project(
    'kraken-engine',
    ['c', 'cpp'],
    license: 'MIT',
    license_files: 'LICENSE',
    default_options: [
        'default_library=static',
        'c_std=c17',
        'cpp_std=c++17',
        'warning_level=2',
    ],
)

# Compiler Type
compiler = meson.get_compiler('c')

# Sources
subdir('src')

# Includes
incs = include_directories('include')

# Install Dependencies ---------------------------------------

# Check for SDL2 and optional SDL2 dependencies

deps = [
    dependency('sdl2', required: true),
]

# Optional dependencies
sdl2_image_dep = dependency('sdl2_image', required: false)
if sdl2_image_dep.found()
    deps += sdl2_image_dep
endif

sdl2_ttf_dep = dependency('sdl2_ttf', required: false)
if sdl2_ttf_dep.found()
    deps += sdl2_ttf_dep
endif

sdl2_mixer_dep = dependency('sdl2_mixer', required: false)
if sdl2_mixer_dep.found()
    deps += sdl2_mixer_dep
endif


if compiler.get_id() == 'msvc'
    deps += dependency('sdl2main')
endif

# Static Library File
libkraken = static_library('kraken', sources: sources, include_directories: incs, dependencies: deps)
# Build Example Program
if get_option('build_example')
    executable(
        'krakenapp',
        'example/main.cpp',
        include_directories: incs,
        dependencies: deps,
        win_subsystem: 'console',
        link_with: libkraken,
    )
endif
