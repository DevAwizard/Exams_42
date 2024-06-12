# include <stdio.h>

// Function to swap the values of two integers
void ft_swap(int *a, int *b)
{
	int temporal;

	temporal = *a;
	*a = *b;
	*b = temporal;
}

int main (void)
{
	int a;
	int b;

	a = 42;

	b = 24;

	printf("a = %d, b = %d\n", a, b);

	ft_swap(&a,&b);

	printf("a = %d, b = %d\n", a, b);

	return (0);
}