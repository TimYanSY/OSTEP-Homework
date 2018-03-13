#include <stdlib.h>
#include <stdio.h>

int main() {
  // int data[100];
  // data[100] = 0;

  int *data = (int *)(malloc(sizeof(int) * 100));
  data[100] = 0;
  return 0;
}
