subdir('traversals')

main_program = executable('tree', 'main/tree_demo.c',
  link_with: libbaume,
  include_directories: includes)

nodes = executable('node_test', 'nodes.c',
  link_with: libbaume,
  include_directories: includes)
test('node_test', nodes)

