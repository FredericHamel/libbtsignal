#include <stdio.h>

int func_a(int x) {
  return 50/x;
}

int func_b(int x) {
  if (x < 0) {
    return x;
  }
  return func_b(x-1) + func_a(x);
}

int main(int argc, char **argv) {
  return func_b(20);
}
