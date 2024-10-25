project(
    'kraken-engine',
    ['c', 'cpp'],
    license : 'MIT',
    license_files: 'LICENSE',
    default_options : [
        'default_library=static',
        'c_std=c17',
        'cpp_std=c++17',
        'warning_level=3',
    ],
)

cc = meson.get_compiler('c')

subdir('src')
incs = include_directories('include')

deps = [
    dependency('sdl2'),
    dependency('sdl2_image'),
    dependency('sdl2_ttf'),
    dependency('sdl2_mixer'),
]

# Declare kraken engine lib and dependency
libkraken = static_library('kraken', sources : sources, include_directories : incs, dependencies : deps)
kraken_engine_dep = declare_dependency(link_with : libkraken, dependencies : deps, include_directories : incs)
meson.override_dependency('kraken-engine', kraken_engine_dep)

if get_option('build_example')
    subdir('example')
    executable(
        'krakenapp',
        sources : example_src,
        include_directories : [incs, include_directories('example')],
        dependencies : deps + [kraken_engine_dep],
        win_subsystem : 'console',
        link_with : libkraken,
    )
endif
