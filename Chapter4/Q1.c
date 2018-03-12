#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int x = 100;
  int rc = fork();
  printf("In process %d, value is %d\n", (int) getpid(), x);
  return 0;
}
