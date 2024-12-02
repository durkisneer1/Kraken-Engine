project(
    'kraken-engine',
    ['c', 'cpp'],
    license : 'MIT',
    license_files : 'LICENSE',
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
    dependency('SDL2_image'),
    dependency('SDL2_ttf'),
    dependency('SDL2_mixer'),
    dependency('pugixml'),
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

if get_option('build_tests')
    gtest_proj = subproject('gtest')

    gtest_dep = gtest_proj.get_variable('gtest_dep')
    gmock_dep = gtest_proj.get_variable('gmock_dep')
    gtest_main_dep = gtest_proj.get_variable('gtest_main_dep')
    gtest_dep = dependency('gtest', main : true, required : false)
    gmock_dep = dependency('gmock', main : true, required : false)
    gtest_main_dep = dependency('gtest_main', main : true, required : false)

    gtest = shared_library('gtest', install : true)
    gmock = shared_library('gmock', install : true)
    gtest_main = shared_library('gtest_main', install : true)

    subdir('tests')
    executable(
        'krakentests',
        sources : test_src,
        include_directories : [incs, include_directories('tests')],
        dependencies : deps + [kraken_engine_dep, gtest_dep, gtest_main_dep],
        win_subsystem : 'console',
        link_with : [libkraken, gtest, gtest_main]
    )
endif
