#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef float * ptf;
void ech (ptf a, ptf b) {
  if (*a < *b) {
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
  }
}
float good (float x, float y) {
  float z=0.0;
  ech (&x, &y);
  if (y < 0.0)
	return - good (x, -y);
  while (y >= 0.0) {
	z += x;
	y -= 1.0;
  }
  return z;
}
void leta (float x, float y, ptf f) {
  float v = 0.0;
  while (y > 0.0) {
	*f++ = v;
	v += x;
	y -= 1.0;
  }
}
void aff (ptf tas, int nb) {
  while (nb--)
	printf("%g ", *tas++);
  printf("\n");
}
int main (int argc, char ** argv) {
  float a, b;
  ptf f;
  if (argc != 3)
	return 1;
  a = atof (argv[1]);
  b = atof (argv[2]);
  ech (&a, &b);
  if (b < 0.0)
	return 1;
  f = (ptf) malloc ((size_t) a * sizeof (float));
  leta (a, b, f);
  aff (f, (int) a);
  printf("%g %g => %g\n", a, b, good(a,b));
}
