#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char **argv)
{
    char str[256] = "-123.5 + 4 - 456+56";
    
    char formatted_str[512] = {0};
    int j = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
		if (str[i] == '+' || str[i] == '-')
		{
			formatted_str[j++] = ' ';
			formatted_str[j++] = str[i];
			formatted_str[j++] = ' ';
		}
		else
		{
			formatted_str[j++] = str[i];			
		}
	}
    
    char delim[] = " ";
    char *token = strtok(formatted_str,delim);
    
    double result = 0;
    bool is_plus = 1; // 1 - Сложение; 0 - Вычитание    
    while (token != NULL)
    {	
		if (strcmp(token,"+") == 0)
		{
			is_plus = 1;
		}
		else if (strcmp(token,"-") == 0)
		{
			is_plus = 0;	
		}
		else
		{
			double num = strtod(token,NULL);
			
			if (is_plus)
			{
				result += num;
			}
			else
			{
				result -= num;
			}
		}
		
		token = strtok(NULL,delim);
	}
	
	printf("Result: %f\n", result);
    	
	return 0;
}

