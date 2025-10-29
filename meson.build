project(
  'cse3210',
  ['cpp'],
  default_options: ['cpp_std=c++17'],
  license: 'MIT',
  license_files: 'LICENSE',
  version: '0.1.0',
)

incdir = include_directories('./include')
dep = declare_dependency(
  include_directories: incdir,
)

executable(
  'a.out',
  ['./src/main.cc'],
  dependencies: [dep],
)

# cpp = meson.get_compiler('cpp')

# custom_target(
#   'OSAP_001_T2_source.cpp',
#   input: './src/main.cc',
#   output: 'OSAP_001_T2_source.cpp',
#   command: [
#     cpp.cmd_array(),
#     '-E',
#     '-P',
#     '-I../include',
#     '-frewrite-includes',
#     '-nostdinc',
#     '-nostdinc++',
#     '-o', '@OUTPUT@',
#     '@INPUT@',
#   ],
# )

subdir('tests')
