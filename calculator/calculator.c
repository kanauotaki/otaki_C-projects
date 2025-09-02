#include <stdlib.h>
#include <stdio.h>

int	add(int a, int b)
{
	return (a + b);
}

int	sub(int	a, int b)
{
	return (a - b);
}

int	mul(int a, int b)
{
	return (a * b);
}

int	divide(int a, int b)
{
	if (b == 0)
	{
		printf("error : 分母が0\n");
		exit (1);
	}
	return (a / b);
}

int	get_index(char op)
{
	switch(op)
	{
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		default: printf("無効な演算子\n");
			 exit (1);
	}
}

int	calculator(int a, int b, int (*func)(int, int))
{
	return (func(a, b));
}

int	main(int argc, char **argv)
{
	int	index;
	int (*operations[4])(int, int) = {add, sub, mul, divide};
	int	result;
	if (argc != 4)
		printf("\n");
	else
	{
		index = get_index(argv[2][0]);
		result = calculator(atoi(argv[1]), atoi(argv[3]), operations[index]);
		printf ("%d\n", result);
	}
	return 0;
}
	
