#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void finish();
void abort();

int main() {
  signal(SIGABRT, abort);
  signal(SIGINT, finish);
  raise(SIGABRT);
  printf("Press <Ctrl> c to terminate the program\n");
  while (1);
}

void finish() {
  printf("\nProgram terminated\n");
  exit(EXIT_SUCCESS);
}

void abort() {
  printf(
      "SIGABRT raised, we would normally abort/terminate the program now, but "
      "this will continue\n");
}
