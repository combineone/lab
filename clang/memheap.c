#include <stdlib.h>
#include <stdio.h>

const int heap_size = 1024;

double * heap;

void init_heap()
{
  heap = malloc(sizeof(double) * heap_size);
  for (int ii = 0; ii < 1024; ii++)
  {
    heap[ii] = 0;
  }
}

void free_heap()
{
  free(heap);
}

int main(void)
{
  printf("Size of double: %lu\n", sizeof(double));

  init_heap();

  heap[0] = 216;
  printf("Result: %d\n", (int)heap[0]);

  free_heap();
}
