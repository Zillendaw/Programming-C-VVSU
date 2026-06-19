#include <stdio.h>

int main(int argc, char **argv)
{
	long n = 0;
	printf("Input [long]: ");
	scanf("%d", &n);
	
	int count_long = 0;
	long temp_long = n; // Создаём копию дабы не испортить исходное число
	
	while (temp_long != 0)
	{
		if (temp_long & 1)
		{
			count_long++;
		}
		temp_long >>= 1; // Сдвигаем биты вправо на 1 позицию
	}
	printf("Биты в типе long: %d\n",count_long);
	
	
	double d = 0;
	printf("Input [double]: ");
	scanf("%lf", &d);
	
	// Берем адрес &d, приводим его к указателю на unsigned long long,
	// а затем разыменовывем чтобы скопировать сырые биты в переменную bits
	unsigned long long *ptr = (unsigned long long *)&d;
	unsigned long long bits = *ptr;
	
	int count_double = 0;
	
	// Так как bits - Это целое число, мы может крутить его в цикле
	for (int i = 0; i < 64; i++)
	{
		if (bits & 1)
		{
			count_double++;
		}
		bits >>= 1;
	}
	
	printf("Bits in double: %d\n", count_double);
	return 0;
}

