#include <pthread.h>
#include <stdio.h>

void *inc_x(void *x_void_ptr)
{
  printf("adress: %d\n", (int)x_void_ptr);
  int* x_ptr = (int*)x_void_ptr;
  printf("adress: %d\n", (int)x_ptr);
  for(int ii = 0; ii < 1488; ii++)
  {
    *x_ptr += ii;
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

  pthread_join(thread_b, NULL);
  pthread_join(thread_a, NULL);

  printf("adress: %d\n", (int)&x);
  printf("value: %d\n", x);

  return 0;
}


