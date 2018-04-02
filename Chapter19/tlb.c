#include <stdio.h>
#include <sys/time.h>

int main() {
  int num = 160000;
  int array[num];
  struct timeval begin, end;
  double elapsed = 0;
  for (int i = 0; i < num; i += 2) {
    gettimeofday(&begin, NULL);
    array[i] += i;
    gettimeofday(&end, NULL);
    elapsed += (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)/1000000.0);
  }
  printf("%lf\n", elapsed / num);
}
