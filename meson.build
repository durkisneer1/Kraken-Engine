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
python = find_program('python3', 'python')

result = run_command(python, 'scripts/install_sdl.py')
if result.returncode() != 0
    error('install_sdl.py script failed.\n', result.stderr())
endif

deps = [
    dependency('sdl2'),
    dependency('sdl2_image'),
    dependency('sdl2_ttf'),
    dependency('sdl2_mixer'),
]

if compiler.get_id() == 'msvc'
    deps += dependency('sdl2main')
endif
# -----------------------------------------------------------

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