#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

static int ___STACK_SIZE;

static void bt_sighandler(int sig, siginfo_t *info, void *ctx) {
  void *trace[___STACK_SIZE];
  char **messages = (char**)NULL;
  int i, trace_size = 0;
  ucontext_t *uctx = (ucontext_t*)ctx;
  trace_size = backtrace(trace, ___STACK_SIZE);
  trace[1] = (void*)uctx->uc_mcontext.gregs[REG_RIP];
  messages = backtrace_symbols(trace, trace_size);
  printf("**** BACKTRACE (%s) ****\n", strsignal(sig));
  for (i = 1; i < trace_size; ++i) {
    printf("[bt] %s\n", messages[i]);
  }
  exit(0);
}

void __attribute__((constructor)) __bt_signal_init(int argc, char **argv) {
#define ___DEFAULT_STACK_SIZE 16
  int stack_size;
  char *stack_size_str;
  struct sigaction sa;
  sa.sa_sigaction = bt_sighandler;
  sigmask(SIGSEGV);
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;

  stack_size_str = getenv("STACK_SIZE");
  if (stack_size_str) {
    stack_size = atoi(stack_size_str);
    ___STACK_SIZE = stack_size > 0 ? stack_size : ___DEFAULT_STACK_SIZE;
  } else {
    ___STACK_SIZE = ___DEFAULT_STACK_SIZE;
  }

  sigaction(SIGSEGV, &sa, NULL);
  sigaction(SIGFPE, &sa, NULL);
#undef ___DEFAULT_STACK_SIZE
}
