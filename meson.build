project(
  'tic-tac-toe',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

incdir = include_directories('include')

dependencies = [
]

sources = [
  'src/tic_tac_toe.c',
  'src/term/term.c',
]

exe = executable(
  'tic-tac-toe',
  sources,
  dependencies : dependencies,
  install : true,
  include_directories : incdir
)

test('basic', exe)
