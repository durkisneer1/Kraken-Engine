import os
import subprocess

import sphinx_rtd_theme

breathe_projects = {'KrakenEngine': 'xml'}
breathe_default_project = 'KrakenEngine'

needs_sphinx = "1.3"

extensions = [
    'breathe',
    'sphinx.ext.autosectionlabel'
]

notfound_context = {
    "title": "Page not found",
    "body": """
        <h1>Page not found</h1>
        <p>
            Sorry, we couldn't find that page. It may have been renamed or removed
            in the version of the documentation you're currently browsing.
        </p>
        <p>
            If you're currently browsing the
            <em>latest</em> version of the documentation, try browsing the
            <a href="/en/stable/"><em>stable</em> version of the documentation</a>.
        </p>
        <p>
            Alternatively, use the
            <a href="#" onclick="$('#rtd-search-form [name=\\'q\\']').focus()">Search docs</a>
            box on the left or <a href="/">go to the homepage</a>.
        </p>
    """,
}

on_rtd = os.environ.get("READTHEDOCS", None) == "True"
if on_rtd:
    subprocess.call('cd ../doxygen; doxygen', shell=True)
else:
    notfound_urls_prefix = ''

source_suffix = '.rst'
source_encoding = "utf-8-sig"

master_doc = 'index'

project = 'Kraken Engine'
copyright = '2024, Derrick Martinez'
author = 'Derrick Martinez'

version = os.getenv("READTHEDOCS_VERSION", "0.0.3")
release = version

supported_languages = {
    "en": "Kraken Engine %s documentation in English",
}

language = os.getenv("READTHEDOCS_LANGUAGE", "en")
if "-" in language:
    (lang_name, lang_country) = language.split("-")
    language = lang_name + "_" + lang_country.upper()

if not language in supported_languages.keys():
    print("Unknown language: " + language)
    print("Supported languages: " + ", ".join(supported_languages.keys()))
    print(
        "The configured language is either wrong, or it should be added to supported_languages in conf.py. Falling back to 'en'."
    )
    language = "en"

html_theme = "sphinx_rtd_theme"
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

html_theme_options = {
    'logo_only': True,
    "display_version": False,
    "collapse_navigation": False,
}

html_title = supported_languages[language] % ("(" + version + ")")
html_logo = "_static/kraken-engine-banner.png"
html_static_path = ['_static']

html_css_files = [
    'css/algolia.css',
    'https://cdn.jsdelivr.net/npm/docsearch.js@2/dist/cdn/docsearch.min.css',
    "css/custom.css?10",  # Increment the number at the end when the file changes to bust the cache.
]

html_js_files = [
    "js/custom.js?7",  # Increment the number at the end when the file changes to bust the cache.
]

file_insertion_enabled = False
