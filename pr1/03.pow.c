#include <stdio.h>
#include <math.h>
#include <assert.h>

int main (void) 
{
	int a,b;
	int r = scanf("%d %d", &a, &b);
	assert (r == 2);
	double result = pow((double)a, (double)b);
	printf ("pow: %.2f", result);
	return 0;
}