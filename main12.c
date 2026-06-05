#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
  int year = 0;
  int month = 0;
  int day = 0;
  
  char input[256] = "";
  
  scanf("%255s", input);
  
  int length = strlen(input);
  int dot_count = 0;
  
  for (int i = 0; i < length; i++)
  {
    if (input[i] == '.')
    {
      dot_count++;
    }
  }
  
  if (strcmp(input, "now") == 0)
  {
    // Вывод текущей даты
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%04d.%02d.%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  }
  else if (dot_count == 0)
  {
    // Календарь на год
    sscanf(input, "%d", &year);
    
    const char *months_ru[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", 
                               "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
                               
    for (month = 1; month <= 12; month++) {
        printf("\n--- %s %d ---\n", months_ru[month - 1], year);
        printf(" Пн  Вт  Ср  Чт  Пт  Сб  Вс\n");
        
        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // Проверка на високосный год
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_in_month[1] = 29;
        }
        
        // Вычисление дня недели для 1-го числа (Алгоритм Сакамото)
        int y = year, m = month;
        int t_mon[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        if (m < 3) y -= 1;
        int first_dow = (y + y/4 - y/100 + y/400 + t_mon[m-1] + 1) % 7; // 0=Вс, 1=Пн ... 6=Сб
        int start_pos = (first_dow + 6) % 7; // Смещаем, чтобы 0=Пн ... 6=Вс
        
        // Пустые отступы до первого дня
        for (int j = 0; j < start_pos; j++) printf("    ");
        
        // Печать дней месяца
        for (int d = 1; d <= days_in_month[m-1]; d++) {
            printf(" %2d ", d);
            if ((start_pos + d) % 7 == 0) printf("\n");
        }
        if ((start_pos + days_in_month[m-1]) % 7 != 0) printf("\n");
    }
  }
  else if (dot_count == 1)
  {
    // Календарь на один месяц
    sscanf(input, "%d.%d", &year, &month);

    if (month >= 1 && month <= 12) {
        const char *months_ru[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", 
                                   "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
        printf("\n--- %s %d ---\n", months_ru[month - 1], year);
        printf(" Пн  Вт  Ср  Чт  Пт  Сб  Вс\n");
        
        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // Проверка на високосный год
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_in_month[1] = 29;
        }
        
        int y = year, m = month;
        int t_mon[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        if (m < 3) y -= 1;
        int first_dow = (y + y/4 - y/100 + y/400 + t_mon[m-1] + 1) % 7;
        int start_pos = (first_dow + 6) % 7; 
        
        for (int j = 0; j < start_pos; j++) printf("    ");
        for (int d = 1; d <= days_in_month[m-1]; d++) {
            printf(" %2d ", d);
            if ((start_pos + d) % 7 == 0) printf("\n");
        }
        if ((start_pos + days_in_month[m-1]) % 7 != 0) printf("\n");
    } else {
        printf("Invalid month!\n");
    }
  }
  else if (dot_count == 2)
  {
    // Вычисление дня недели для конкретной даты
    sscanf(input, "%d.%d.%d", &year, &month, &day);
    
    if (month >= 1 && month <= 12) {
        int y = year, m = month, d = day;
        int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        if (m < 3) y -= 1;
        
        // Алгоритм Сакамото для нахождения дня недели
        int dow = (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
        const char *days[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
        
        printf("%s\n", days[dow]);
    } else {
        printf("Invalid date!\n");
    }
  }
  else
  {
    printf("Not correct input integers!\n");
  }
  
  return 0;
}
