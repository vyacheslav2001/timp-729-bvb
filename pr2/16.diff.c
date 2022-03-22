#include <stdio.h>
#include <assert.h>
#include <math.h>

int main (void) 
{
	int n, x;
	double result = 0.0;
	int r1 = scanf("%d", &n);
	assert (r1 == 1);
	int numbers[n];
	for (int i = 0; i < n; i++)
		{
			printf("Num %d = ", i+1);
			int r2 = scanf("%d", &x);
			assert (r2 == 1);
			numbers[i] = x;
		}
	for (int i = 0; i < n; i++)
		{	
			result += pow(-1.0, i+1) * pow((double)numbers[i], 3.0);
		}
	printf("Result: %f", result);
	return 0;
}