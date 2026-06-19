#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;
long long final_sum = 0;

void fibonacci(int target, int current_step,int a, int b)
{
	if (target < 0)
	{
		printf("Число Фибоначчи не может быть меньше 0!\n");
		longjmp(buffer,2026);		
	}
	
	final_sum += a;
	
	if (current_step == target)
	{
		longjmp(buffer,1);
	}

	fibonacci(target, current_step + 1, b, (a + b));
	
}

int main(int argc, char **argv)
{
	int n = 45;
	int error_code = setjmp(buffer);
	
	if (error_code == 0)
	{
		fibonacci(n,1,1,1);
	}
	else if (error_code == 1)
	{
		printf("Сумма первых %d чисел Фибоначчи: %lld (Код: %d)\n", n, final_sum, error_code);
	}
	else
	{
		printf("Ошибка! Не получилось... Код ошибки: %d\n", error_code);
	}
	
	return 0;
}

