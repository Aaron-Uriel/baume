# Argumento usado para distingir las bibliotecas de las pruebas unitarias.
# Solo es agregado en la biblioteca.
lib_args = ['-DBUILDING']

sources = files('nodes.c')
subdir('tree')

libbaume = shared_library(
  'libbaume',
  sources,
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'hidden',
  include_directories : includes
)

