#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Макрос для поиска максимального числа
#define FIND_MAX(arr,n,result) do { \
		(result) = (arr)[0];\
		for (int i = 1; i < (n); i++) { \
			if ((arr)[i] > (result)) {\
				(result) = (arr)[i];\
			}\
		}\
} while(0)\

#define AVG(arr,n,result) do {\
		(result) = (arr)[0];\
		for (int i = 1; i < (n); i++) {\
			(result) += (arr)[i];\
		}\
		(result) /= n;\
	}while(0)\


int main(int argc, char **argv)
{
	char str[256];
	char delim[] = " ";
	
	int arr[256];
	int n = 0;
	int max;
	
	int avg_num;
	
	printf("Input: ");
	fgets(str, sizeof(str), stdin);
	
	char *token = strtok(str,delim);
	
	while (token != NULL)
    {	
		arr[n] = atoi(token); // Преобразуем строку (токен) в целое число (int)
		n++;
		token = strtok(NULL,delim);
	}
	
	if (n > 0)
	{
		FIND_MAX(arr,n,max);
		printf("Maximum number: %d\n",max);
		
		AVG(arr,n,avg_num);
		printf("Average: %d\n",avg_num);
	}
	else
	{
		printf("No numbers entered.\n");
	}
	
	
	
	return 0;
}

