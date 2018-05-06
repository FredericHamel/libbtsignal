
project('libbtsignal', 'c')

if build_machine.system() == 'windows'
  error('Windows system is not yet supported')
endif

src = ['src/libbtsignal.c']
libbtsignal = shared_library('btsignal', src, install: true)

subdir('tests')

