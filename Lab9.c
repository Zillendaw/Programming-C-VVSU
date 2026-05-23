#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char str[256];
    
    char delim[] = " ";
    char symbol_plus = '+';
    char symbol_minus = '-';
    
    printf("Add input: ");
    scanf("%s",&str);
    
    char *token = strtok(str,delim);
    
    while (token != NULL)
    {
		//int len = strlen(str);
		
		if (strchr(token,symbol_plus) != NULL)
		{
			printf("%s",token);
			break;
		}		
		else if (strchr(token,symbol_minus) != NULL)
		{
			printf("%s",token);
			break;
		}
		
		token = strtok(NULL,delim);
		if (token == NULL)
		{
			printf("Unknown...\n");
		}
	}
    	
	return 0;
}

