#include <stdio.h>

int crash() {
  return *((int*)NULL);
}

int main(int argc, char **argv) {
  return crash();
}
