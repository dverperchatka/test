#include <stdio.h>
#include <math.h>

#define INPUT_ERR 100
#define INCORRECT_DATA 101
#define OVERFLOW_ERR 200

float get_asin_approx(float x, float epsilon)
{
	return 0;
}

int main(void)
{
	float x, ε;
	if (!scanf("%f", &x))
	{
		printf("Invalid input: Expected float number\n");
		return INPUT_ERR;
	}
	
	if (!scanf("%f", &ε))
	{
		printf("Invalid input: Expected float number\n");
		return INPUT_ERR;
	}
	return 0;
}
