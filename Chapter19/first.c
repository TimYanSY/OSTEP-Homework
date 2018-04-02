#include <stdio.h>
#include <sys/time.h>

int main() {
  struct timeval begin, end;
  gettimeofday(&begin, NULL);
  for (int i = 0; i < 100000000; i++) {

  }
  gettimeofday(&end, NULL);
  double elapsed = (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)/1000000.0);
  printf("%lf\n", elapsed);
}
