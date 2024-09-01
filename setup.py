import subprocess
import os
import sys

if not os.path.exists('subprojects'):
    os.mkdir('subprojects')

wraps = [
    'sdl2',
    'sdl2_image',
    'sdl2_ttf',
    'sdl2_mixer',
]

for wrap in wraps:
    print(f'Installing wrap: {wrap}')
    subprocess.run(f'meson wrap install {wrap}', shell=True)

# Run Meson setup
result = subprocess.run(['meson', 'setup', 'builddir'])
if result.returncode != 0:
    print('Meson setup failed.\n', result.stderr)
    sys.exit(result.returncode)


# Compile Kraken and Example App
result = subprocess.run(['meson', 'compile', '-C', 'builddir'])
if result.returncode != 0:
    print('Compilation failed.\n', result.stderr)
    sys.exit(result.returncode)
    