#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class maiFunctor {
  public:
  double operator ()(int x)
  {
    return x*2;
  }
};

int main (int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stdout, "Usage: %s number\n", argv[0]);
    return 1;
  }

  double inputValue = atof(argv[1]);
  maiFunctor functor;
  double outputValue = functor(inputValue);
  fprintf(stdout,"The square root of %g is %g\n", inputValue, outputValue);

  return 0;
}

