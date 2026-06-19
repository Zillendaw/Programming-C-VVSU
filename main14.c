#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;
int final_sum = 0;

int fibonacci(int n)
{
	//printf("%d\n",n);
	
	if (n < 0)
	{
		printf("Число Фибоначчи не может быть меньше 0!\n");
		longjmp(buffer,228);		
	}
	
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	return fibonacci(n-1) + fibonacci(n-2);
	longjmp(buffer,1);
}

int main(int argc, char **argv)
{
	int n = 45;
	int error_code = setjmp(buffer);
	
	if (error_code == 0)
	{
		printf("%d-е число Фиббоначи: %d; Код: %d\n", n, fibonacci(n),error_code);
	}
	else
	{
		printf("Ошибка! Не получилось... Код ошибки: %d\n", error_code);
	}
	return 0;
}

