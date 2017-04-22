#include <pthread.h>
#include <stdio.h>

void *inc_x(void *x_void_ptr)
{
  int* x_ptr = (int*)x_void_ptr;
  for(int ii = 0; ii < 2000; ii++)
  {
    (*x_ptr)++;
  }

  return NULL;
}

int main()
{
  int x = 0;

  pthread_t thread_a;
  pthread_t thread_b;

  pthread_create(&thread_a, NULL, inc_x, &x);
  pthread_create(&thread_b, NULL, inc_x, &x);

  printf("thread: %02x\n", (unsigned)thread_a);
  printf("thread: %02x\n", (unsigned)thread_b);

  pthread_join(thread_b, NULL);
  pthread_join(thread_a, NULL);

  printf("value: %d\n", x);

  return 0;
}


