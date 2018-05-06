
tests = ['0_sigfpe', '1_sigsegv']

test_env = ['LD_PRELOAD=' + libbtsignal.full_path()]

foreach tt : tests
  exe = executable(tt, [ tt + '/main.c'], implib: true)
  test('test_' + tt, exe, env : test_env)
endforeach
