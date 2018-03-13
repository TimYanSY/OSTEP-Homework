#include <stdlib.h>
#include <stdio.h>

int main() {
  // int data[100];
  // data[100] = 0;

  int *data = (int *)(malloc(sizeof(int) * 100));
  free(data);
  printf("%d\n", data[0]);
  return 0;
}
