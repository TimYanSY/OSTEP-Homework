#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int rc = fork();

  if (rc == 0) {
    printf("In process %d\n", getpid());
    char * const argv[] = {"ls", NULL};
    execv("/bin/ls", argv);
  } else if (rc > 0) {
    printf("In process %d\n", getpid());
    wait(NULL);
  } else {
    printf("%s\n", "Some thing goes wrong");
  }

  return 0;
}
