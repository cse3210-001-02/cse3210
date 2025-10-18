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

subdir('tests')
