import subprocess
subprocess.call('doxygen', shell=True)

extensions = ['breathe']

breathe_projects = {'KrakenEngine' : 'xml'}
breathe_default_project = 'KrakenEngine'

master_doc = 'index'

source_suffix = '.rst'

project = 'Kraken Engine'
copyright = '2024, Derrick Martinez'
author = 'Derrick Martinez'

html_static_path = ['_static']
html_theme = 'furo'
html_title = 'Kraken Engine'

html_theme_options = {
    'sidebar_hide_name': False,  # Set to True once logo is in place
}