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
    ]
)

# Sources
subdir('src')

# Includes
incs = include_directories('include')

# Dependencies
deps = [
    dependency('sdl2'),
    dependency('sdl2_image'),
    dependency('sdl2_ttf'),
    dependency('sdl2_mixer')
]

# Static Library File
libkraken = static_library('kraken', sources: sources, include_directories: incs, dependencies: deps)

# Compile Executable
executable(
    'app',
    'main.cpp',
    include_directories: incs,
    dependencies: deps,
    win_subsystem: 'console',
    link_with: libkraken,
)
