#include <stdio.h>
#include <limits.h>

#define ERR_INPUT 100;
#define ERR_OVERFLOW 200;

int is_overflow(int a, int b)
{
        if (INT_MAX - a < b)
		return 1;
	else
		return 0;
}

int next_fib(int *last_fib, int *cur_fib)
{
	int tmp_num = *cur_fib;
	*cur_fib += *last_fib;
	*last_fib = tmp_num;
	return 0;
}

int main(void)
{
	int num;
	printf("Enter the number of the Fibonacci number: ");
	if (scanf("%d", &num) && num >= 0)
	{
		if (num > 0)
		{
			int last_fib = 0, cur_fib = 1;
			for (int i = 1; i < num; i++)
			{
				if (is_overflow(last_fib, cur_fib))
				{
					printf("Overflow error\n");
					return ERR_OVERFLOW;
				}
				next_fib(&last_fib, &cur_fib);
			}
			printf("The Fibonacci number is: %d\n", cur_fib);
		}
		else
			printf("The Fibonacci number is: 0\n");
	}
	else
	{
		printf("Invalid input\n");
		return ERR_INPUT;
	}
	return 0;
}
