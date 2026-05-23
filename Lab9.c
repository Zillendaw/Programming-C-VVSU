#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    char str[256] = "-123.5 + 4 - 456+56";
    
    char delim[] = " ";
    char symbol_plus = '+';
    char symbol_minus = '-';
    
    //printf("Add input: ");
    //scanf("%s",&str);
    
    char *token = strtok(str,delim);
    
    while (token != NULL)
    {
		double result;
		
		if (strchr(token,symbol_minus) != NULL)
		{
			double num_minus = strtod(token,NULL);
			result += num_minus;
			//printf("%s",token);
		}		
		else if (strchr(token,symbol_plus) != NULL)
		{
			
			//printf("%s",token);
		}
		
		token = strtok(NULL,delim);
		if (token == NULL)
		{
			printf("%f",result);
		}
	}
    	
	return 0;
}

