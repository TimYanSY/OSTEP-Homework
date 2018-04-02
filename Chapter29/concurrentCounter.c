#include <stdio.h>
#include <time.h>
#include <pthread.h>

typedef struct __counter_t {
  int value;
  pthread_mutex_t lock;
} counter_t;

void init(counter_t *c) {
  c->value = 0;
  pthread_mutex_init(&c->lock, NULL);
}

void increment(counter_t *c) {
  int i = 0;
  int times =20000000 / 3;
  while (i < times) {
    pthread_mutex_lock(&c->lock);
    c->value++;
    pthread_mutex_unlock(&c->lock);
    i++;
  }
}

void decrement(counter_t *c) {
  pthread_mutex_lock(&c->lock);
  c->value--;
  pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c) {
   pthread_mutex_lock(&c->lock);
   int rc = c->value;
   pthread_mutex_unlock(&c->lock);
   return rc;
 }

int main(int argc, char const *argv[]) {
  counter_t counter;
  init(&counter);
  clock_t before = clock();
  int msec = 0;
  int i = 0;
  pthread_t tid1;
  pthread_t tid2;
  increment(&counter);
  pthread_create(&tid1, NULL, increment, &counter);
  pthread_create(&tid2, NULL, increment, &counter);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  clock_t difference = clock() - before;
  msec = difference * 1000 / CLOCKS_PER_SEC;
  printf("Time taken %d seconds %d milliseconds (%d iterations)\n",
  msec/1000, msec%1000, get(&counter));
  return 0;
}
