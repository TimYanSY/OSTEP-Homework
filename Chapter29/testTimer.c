#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int msec = 0, trigger = 10; /* 10ms */
  int iterations = 0;
  clock_t before = clock();

  do {
    /*
     * Do something to busy the CPU just here while you drink a coffee
     * Be sure this code will not take more than `trigger` ms
     */

    clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    iterations++;
  } while ( msec < trigger );
  printf("%d\n", CLOCKS_PER_SEC);
  printf("Time taken %d seconds %d milliseconds (%d iterations)\n",
  msec/1000, msec%1000, iterations);
  return 0;
}
