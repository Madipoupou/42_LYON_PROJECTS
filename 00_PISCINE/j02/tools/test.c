#include <stdio.h>

void ft_ft(int *n)
{
	*n = 42;
}

void ft_ft_2(int n)
{
	n = 42;
}

int main(void)
{
	int n;
	n = 5;
	printf("%d\n", n);

	ft_ft_2(n);
	printf("%d\n", n);
}
