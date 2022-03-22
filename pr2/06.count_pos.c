#include <stdio.h>
#include <assert.h>

int main (void) 
{
	int n, x, result = 0;
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
			if (numbers[i] > 0) result++;
		}
	printf("Result: %d", result);
	return 0;
}