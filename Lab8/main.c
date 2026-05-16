#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 255

typedef struct {		
	char lastname[64];
	char name[64];
	int birth_year;
	char sex[4];
	int height;
} Person;

// Функция для сравнение двух людей по году рождения
int compare_by_year(const void *a, const void *b) {
	
	// Берём два объекта из структуры Person для сравнения
	Person *personA = (Person *)a;
	Person *personB  = (Person *)b;
	
	// Сравниваем в компараторе года рождения
	return (personA->birth_year - personB->birth_year);
}

// Функция для сравнение двух людей по имени
int compare_by_name(const void *a, const void *b) {
	
	// Берём два объекта из структуры Person для сравнения
	Person *personA = (Person *)a;
	Person *personB  = (Person *)b;
	
	// Сравниваем в компараторе по имени
	return strcmp(personA->name,personB->name);
}

int main ()
{
	FILE *open_file = fopen("main.txt","r");
	FILE *output_file = fopen("output.txt","w");
	
	if (open_file == NULL || output_file == NULL)
	{
		printf("Error: txt file is not open!");
		return -1;
	}
	
	Person people[MAX_LINES];
	char buffer[MAX_LENGTH];
	int line_count = 0;
	
	
	// Пока можем прочитать строку из файла в buffer
	while (fgets(buffer, MAX_LENGTH, open_file) != NULL)
	{
		int parsed = sscanf(buffer, "%s %s %d %s %d",
						people[line_count].lastname,
						people[line_count].name,
						&people[line_count].birth_year,
						people[line_count].sex,
						&people[line_count].height);
						
		// Проверяем, успешно ли считано ровно 5 элементов?
		if (parsed == 5)
		{
			printf("%s %s, %d год, пол %s, вес %d\n",
				   people[line_count].lastname,
				   people[line_count].name,
				   people[line_count].birth_year,
				   people[line_count].sex,
				   people[line_count].height);
			
			line_count++;
		}
	}	
	
	printf("\nВсего загружено людей: %d\n",line_count);	
	
	// Сортируем массив людей
	qsort(people, line_count, sizeof(Person), compare_by_name);
	
	// Выводим отсортированный массив людей
	printf("Sorted People:\n");
	for (int i = 0; i < line_count; i++)
	{
		printf("%s %s, %d\n", people[i].lastname, people[i].name, people[i].birth_year);
		
		fprintf(output_file, "%s %s, %d г.р., %s, %d см\n", people[i].lastname, people[i].name, people[i].birth_year, people[i].sex, people[i].height);
	}
	
		
	fclose(open_file);
	fclose(output_file);
	
	return 0;
}
