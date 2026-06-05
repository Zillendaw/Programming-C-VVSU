#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char **argv)
{
	int year = 0;
	int month = 0;
	int day = 0;
	
	char input[256] = "";
	
	scanf("%255s",input);
	
	int length = strlen(input);
	int dot_count = 0;
	
	for (int i= 0; i < length; i++)
	{
		if (input[i] == '.')
		{
			dot_count++;
		}
	}
	
	if (input == "now")
	{
		
	}
	else if (dot_count == 0)
	{
		sscanf(input,"%c",&year);
		
	}
	else if (dot_count == 1)
	{
		sscanf(input,"%.c%.c",&year,&month);

	}
	else if (dot_count == 2)
	{
		sscanf(input,"%.c%.c%.c",&year,&month,&day);
	}
	else if (input == NULL)
	{
		printf("Not corrent input integers!");
		scanf("%255s",input);
	}
	
	return 0;
}

