// Вариант 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Функция создание матрицы с рандомными числами
int** create_matrix (int m)
{
	int** matrix = (int**)malloc(m * sizeof(int**));
	
	for (int i = 0; i <= m; i++)
	{
		matrix[i] = (int*)malloc(m * sizeof(int*));
		for (int j = 0; j <= m; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
	
	return matrix;
}

// Функция освобождение матрицы
void free_matrix(int** matrix, int m)
{
	for (int i = 0; i <= m; i++)
	{
		free(matrix);
	}
}

// Функция суммирование матрицы
int sum_matrix(int** matrix, int m)
{
	int sum = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			matrix[i][j] += sum;
		}
	}
	
	return sum;
}

void print_matrix(int **matrix, int m)
{
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	//int n = 0;
	//printf("Input size matrix: ");
	//scanf("%d",&n);
	
	FILE *input = fopen("input.txt","w");
	FILE *output = fopen("output.txt","r");
	
	if (!input) 
	{
		printf("! ! ! ERROR WITH INPUT.TXT ! ! !\n"); 
		return -1;	
	}
	if (!output)
	{
		printf("! ! ! ERROR WITH OUTPUT.TXT ! ! !\n"); 
		return -2;	
	}
	
	int day = 0;
	int month = 0;
	int year = 0;
	
	if (fscanf(input,"%d %d %d",&day,&month,&year) != 3)
	{
		printf("ERROR: less arguments...\n");
		fclose(input);
		return -3;
	}
	fclose(input);
	
	
	
	// Замер скорости программы
	clock_t start_time = clock();
	srand(time(NULL));
	
	time_t t = time(NULL);
	struct tm current_time = *localtime(&t);
	
	struct tm target_time = {0};
	target_time.tm_mday = day;
	target_time.tm_mon = month - 1;
	target_time.tm_year = year - 1900;
	
	time_t current_t = mktime(&current_time);
	time_t target_t = mktime(&target_time);
	
	double diff_seconds = difftime(target_t, current_t);
	int days_left = (int)(diff_seconds / (60 * 60 * 24));
	
	if (days_left < 0)
	{
		printf("Data already done...\n");
	}
	else
	{
		printf("Time: %02d.%02d.%04d: %d\n",day,month,year,days_left);
	}
	
	
	// Создать матрицы пока не появится две с один. суммой
	//int m;
	//printf("Input size matrix: \n");
	//scanf("%d",&m);
	
	//int max_sum = m * m * 100;
	
	//int** matrix_by_sum[max_sum + 1];
	//for (int i = 0; i <= max_sum; i++)
	//{
		//matrix_by_sum[i] = NULL;
	//}
	
	//int step = 0;
	//while(1)
	//{
		//step++;
		//int** new_mat = create_matrix(m);
		//int sum = get_sum(new_mat,m);
		
		//if (matrix_by_sum[sum] != NULL)
		//{
			//fprint(output,"Got it on %d step(-s), Sum elements: %d\n\n",step,sum);
			
			//fprintf(out,"First matrix:\n");
			//print_matrix(new_mat,m);
			//fclose(out);
			
			//printf("Matrix with sum %d writed in output.txt\n",sum);
			//break;
		//}
		//else
		//{
			//matrix_by_sum[sum] = new_mat;
		//}
	//}
	
	//// Очистка памяти
	//for (int i = 0;  <= count; i++)
	//{
		//free_matrix(matrix_by_sum);
	//}
	
	clock_t end_time = clock();
	double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Time running programm: %f seconds",time_spent);
	
	return 0;
}

