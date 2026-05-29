#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char **argv)
{
    char str[256] = "-123.5 + 4 - 456+56";
    
    char delim[] = " ";
    char symbol_plus = '+';
    char symbol_minus = '-';
    
    char *token = strtok(str,delim);
    double result = 0;
    bool is_plus = 1;
    
    while (token != NULL)
    {	
		double num = strtod(token,NULL);
		printf("result: %f\n",result);
		printf("token: '%s'\n", token);
		
		if (strcmp(token,"+") == 0)
		{
			is_plus = 1;
		}
		else if (strcmp(token,"-") == 0)
		{
			is_plus = 0;	
		}
		
		if (is_plus)
		{
			result += num;
		}
		else
		{
			result -= num;
		}
		
		token = strtok(NULL,delim);
		if (token == NULL)
		{
			printf("%f\n",result);
		}
	}
    	
	return 0;
}

