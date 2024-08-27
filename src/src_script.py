import os

dir_name = os.path.basename(os.getcwd())
all_files = os.listdir()

filtered_files = [
    f'{dir_name}/{file}' for file in all_files
    if file not in ['meson.build', os.path.basename(__file__)]
]

with open('meson.build', 'w') as f:
    f.write(f'sources = {filtered_files}')
    