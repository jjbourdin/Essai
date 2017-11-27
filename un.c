#include<stdio.h>

int fib (int n) {
  if (n < 2)
	return 1;
  return fib(n - 1) + fib (n - 2);
}
int fibiter (int n) {
  int a, b, c;
  a = 1;
  b = 1;
  while (n > 1) {
	c = a + b;
	b = a;
	a = c;
	n--;
  }
  return a;
}
int main () {
  int a, b;

  for (a = 0; a < 20; a++) {
	b = fibiter (a);
	printf(" fibiter (%d) == %d\n", a, b);
  }
}
