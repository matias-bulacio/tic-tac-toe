project(
  'tic-tac-toe',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

incdir = include_directories('include')

ncurses = dependency('ncurses')

dependencies = [
	ncurses
]

sources = [
  'src/app.c',
  'src/input.c',
  'src/start.c',
  'src/tic-tac-toe/board.c',
]

exe = executable(
  'tic-tac-toe',
  sources,
  dependencies : dependencies,
  install : true,
  include_directories : incdir
)

test('basic', exe)
