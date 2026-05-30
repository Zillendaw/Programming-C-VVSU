#include <stdio.h>
#include <stdarg.h>
#include "math_utils.h"

int sum (int count, ...)
{
	int result = 0;
	va_list args;
	va_start(args,count);
	
	for (int i = 0; i < count; i++)
	{
		int num = va_arg(args, int);
		result += num;
	}
	
	va_end(args);
	return result;
}

int max (int count, ...)
{
	int result = 0;
	va_list args;
	va_start(args,count);

	for (int i = 0; i < count; i++) { 
		int num = va_arg(args,int);
		if (result < num) {
			result = num;
		}
	}
	
	va_end(args);
	return result;
}

int min (int count, ...)
{
	int result = 0;
	va_list args;
	va_start(args,count);

	for (int i = 0; i < count; i++) { 
		int num = va_arg(args,int);
		if (result > num) {
			result = num;
		}
	}
	
	va_end(args);
	return result;
}

double avg (int count, ...)
{
	double result = 0;
	va_list args;
	va_start(args,count);

	for (int i = 0; i < count; i++) { 
		int num = va_arg(args,int);
		result += num;
	}
	
	result /= count;
	
	va_end(args);
	return result;
}
