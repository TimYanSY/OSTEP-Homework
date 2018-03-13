#include <stdlib.h>
#include <stdio.h>

int main() {
  // int data[100];
  // data[100] = 0;

  int *data = (int *)(malloc(sizeof(int) * 100));
  data[50] = 2;
  free(data);
  data[50] = 3;
  printf("%d\n", data[50]);
  free(&data[50]);
}
