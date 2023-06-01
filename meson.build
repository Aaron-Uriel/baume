project('libbaume', 'c',
  license: 'WTFPL',
  version: '0.0.1',
  default_options: ['warning_level=3', 'buildtype=debug', 'debug=true',
    'errorlogs=true', 'c_args=--pedantic-errors',
    'c_std=c2x'])

includes = include_directories('include')

subdir('include')
subdir('src')
subdir('tests')

# Make this library usable as a Meson subproject.
libbaume_dep = declare_dependency(
  include_directories: includes,
  link_with : libbaume
)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'libbaume',
  filebase : 'libbaume',
  description : '¡Árboles!',
  subdirs : 'libbaume',
  libraries : libbaume,
  version : '0.0.1',
)
