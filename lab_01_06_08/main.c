#include <stdio.h>
#include <math.h>

#define INPUT_ERR 100
#define INCORRECT_DATA 101
#define OVERFLOW_ERR 200

float epsilon = 1e-10;

float pseudo_scalar(float a_x, float a_y, float b_x, float b_y)
{
	return a_x*b_y - a_y*b_x;
}

int signum(float a)
{
	return (a > 0) - (a < 0);
}

int dot_input(float *x, float *y)
{
	if (!scanf("%f", x))
	{
		printf("Invalid input: Expected two float numbers\n");
		return INPUT_ERR;
	}
	if (isinf(*x))
	{
		printf("Invalid input: Number is too long\n");
		return OVERFLOW_ERR;
	}
	if (!scanf("%f", y))
	{
		printf("Invalid input: Expected two float numbers\n");
		return INPUT_ERR;
	}
	if (isinf(*y))
	{
		printf("Invalid input: Number is too long\n");
		return OVERFLOW_ERR;
	}
	return 0;
}

int main(void)
{
	int err_code = 0;
	
	float x_1, y_1, x_2, y_2, x_3, y_3;
	printf("Enter first vertex (x,y): \n");
	if ((err_code=dot_input(&x_1, &y_1)) != 0)
		return err_code;
	printf("Enter second vertex (x,y): \n");
	if ((err_code=dot_input(&x_2, &y_2)) != 0)
		return err_code;
	printf("Enter third vertex (x,y): \n");
	if ((err_code=dot_input(&x_3, &y_3)) != 0)
		return err_code;
		
	if ((x_1 == x_2 && y_1 == y_2) || (x_2 == x_3 && y_2 == y_3) || (x_3 == x_1 && y_3 == y_1) || (fabs((y_3-y_1)*(x_2-x_1) - (x_3-x_1)*(y_2-y_1)) < epsilon))
	{
		printf("No such triangle exists\n");
		return INCORRECT_DATA;
	}
	
	float p_x, p_y;
	printf("Enter point coordinates (x,y): \n");
	if ((err_code=dot_input(&p_x, &p_y)) != 0)
		return err_code;
	

	
	int left_1 = signum(pseudo_scalar(x_2-x_1, y_2-y_1, p_x-x_1, p_y-y_1));
	int left_2 = signum(pseudo_scalar(x_3-x_2, y_3-y_2, p_x-x_2, p_y-y_2));
	int left_3 = signum(pseudo_scalar(x_1-x_3, y_1-y_3, p_x-x_3, p_y-y_3));
	
	if (left_1 * left_2 * left_3 == 0)
	{
		printf("The point is on the edge of the triangle\n");
		printf("Output code: 1\n");
	}
	else if (left_1 == left_2 && left_2 == left_3)
	{
		printf("The point is in the triangle\n");
		printf("Output code: 0\n");
	}
	else
	{
		printf("The point is not in the triangle\n");
		printf("Output code: 2\n");
	}
}
