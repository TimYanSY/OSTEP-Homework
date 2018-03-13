#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Book {
  char *name;
  int id;
};

int main() {
  // struct Book book1;
  // book1.id = 1;
  // book1.name = "First Book";
  // struct Book book2;
  // book2.id = 2;
  // book2.name = "Second Book";
  // struct Book books[2];
  // books[0] = book1;
  // books[1] = book2;
  // printf("%s\n", books[0].name);
  // printf("%s\n", books[1].name);
  int size = 0;

  int* data = (int *)(malloc(sizeof(int)));
  data[0] = 2;
  size++;
  for (int i = 0; i < size; i++) {
    printf("%d\n", data[i]);
  }

  data = (int *)(realloc(data, sizeof(int) * 2));
  data[1] = 1;
  size++;
  for (int i = 0; i < size; i++) {
    printf("%d\n", data[i]);
  }
  return 0;
}
