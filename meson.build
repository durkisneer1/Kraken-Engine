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

# Install Dependencies
deps = [
    dependency('sdl2'),
    dependency('sdl2_image'),
    dependency('sdl2_ttf'),
    dependency('sdl2_mixer'),
]

if compiler.get_id() == 'msvc'
    deps += dependency('sdl2main')
endif

# Static Library File
libkraken = static_library('kraken', sources: sources, include_directories: incs, dependencies: deps)

# Build Example Program
if get_option('build_example')
    subdir('example')
    executable(
        'krakenapp',
        sources: example_src,
        include_directories: [incs, include_directories('example')],
        dependencies: deps,
        win_subsystem: 'console',
        link_with: libkraken,
    )
endif