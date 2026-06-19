#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

long long fibonacci (int n)
{
	//printf("%d\n",n);
	
	if (n == 0) 
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;		
	}
	else if (n < 0)
	{
		printf("Число Фибоначчи не может быть меньше 0!\n");
		longjmp(buffer,1);		
	}
	
	return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char **argv)
{
	int n = 45;
	int error_code = setjmp(buffer);
	
	if (error_code == 0)
	{
		printf("%d-е число Фиббоначи: %lld\n", n, fibonacci(n));
	}
	else
	{
		printf("Ошибка! Не получилось... Код ошибки: %d\n", error_code);
	}
	return 0;
}

