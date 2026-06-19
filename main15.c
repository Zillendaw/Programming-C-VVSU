#include <stdio.h>

void print_direct (int n)
{
	if (n == 0)
	{
		return;
	}
	
	print_direct(n/10);
	printf("%d ", n % 10);
}

void print_reverse (int n)
{
	if (n == 0)
	{
		return;
	}
	printf("%d ", n % 10);
	print_reverse(n/10);
}

int main(int argc, char **argv)
{
	int N = 1234567890;
	printf("Number: %d\n", N);

	printf("\nNORMAL:\n");
	print_direct(N);
	
	printf("\nREVERSE:\n");
	print_reverse(N);
	printf("\n");
	
	return 0;
}

