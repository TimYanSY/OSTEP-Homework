#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int status;
  int rc = fork();
  if (rc == 0) {
    printf("%s, %d\n", "In child process", getpid());
  } else if (rc > 0) {
    waitpid(rc, &status, WUNTRACED | WCONTINUED);
    printf("%s, %d\n", "In parent process", getpid());
  } else {
    printf("%s\n", "Something goes wrong when forking");
  }
  return 0;
}
