#include <stdio.h>
#include <math.h>

void pair_sort(float *a, float *b)
{
	if (*a < *b)
	{
		float tmp_base = *a;
		*a = *b;
		*b = tmp_base;
	}
}

int main()
{
	float a, b, h;
	printf("Enter first base: ");
	scanf("%f", &a);
	printf("Enter second base: ");
	scanf("%f", &b);
	printf("Enter height: ");
	scanf("%f", &h);
	
	pair_sort(&b, &a);
	float c = (b - a)/2.0;
	float d = pow(c*c + h*h, .5f);
	float P = 2*d + a + b;
	
	printf("Perimeter: %f\n", P);
}
