#include <assert.h>
#include <stdio.h>

int main ()
{
  int a, b;
  int r = scanf ("%d %d", &a, &b);
  assert (r == 2);
  printf ("%d\n", a + b);
  return 0;
}