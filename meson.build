project(
  'cse3210',
  ['cpp'],
  default_options: ['cpp_std=c++20'],
  license: 'MIT',
  license_files: 'LICENSE',
  version: '0.1.0',
)

incdir = include_directories('./include')

executable(
  'a.out',
  ['./src/main.cc', './src/avltree.cc'],
  include_directories: incdir,
)

style_test_incdir = include_directories('./test/style/include')

executable(
  'style-test',
  ['./test/style/src/qux.cc'],
  include_directories: style_test_incdir,
  install: false,
  build_by_default: false,
)
