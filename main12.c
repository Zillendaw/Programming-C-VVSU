#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Функция для печати календаря на конкретный месяц
void print_month_calendar(int year, int month) {
	
	// Константный массив символов каждого месяца
    const char *months_ru[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", 
                               "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    
    // Инициализация структуры tm
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = 1;
    date.tm_isdst = -1; // Для определения: летнее время или нет

    // Вызов mktime, чтобы заполнить поле tm_wday (день недели), поскольку в системах Unix календарь начинается с 1 января 1970 года 
    // + проверка "на дурака" если ввёдёт случайно 32 января
    if (mktime(&date) == -1) {
        printf("Ошибка даты!\n");
        return;
    }

    printf("\n--- %s %d ---\n", months_ru[month - 1], year);
    printf(" Пн  Вт  Ср  Чт  Пт  Сб  Вс\n");

    // В struct tm: 0 - Воскресенье, 1 - Понедельник ... 6 - Суббота
    // Переводим в формат: 0 - Пн, 6 - Вс
    int start_pos = (date.tm_wday + 6) % 7;

    // Пустые отступы до первого дня
    for (int j = 0; j < start_pos; j++) printf("    ");

    // Чтобы узнать количество дней в месяце - Прибавляем по дню, 
    // пока месяц не изменится.
    int current_month = date.tm_mon;
    while (date.tm_mon == current_month) {
        printf(" %2d ", date.tm_mday);
        
        if ((start_pos + date.tm_mday) % 7 == 0) {
            printf("\n");
        }

        date.tm_mday++;
        mktime(&date); // Обновляем структуру когда дни в месяце заканчивается
    }
    
    if ((start_pos + date.tm_mday - 1) % 7 != 0) {
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int year = 0, month = 0, day = 0;
    char input[256] = "";
    
    if (scanf("%255s", input) != 1) 
	{
		printf("ERROR: EMPTY...\n");
		return -1;
	}

    int dot_count = 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] == '.') dot_count++;
    }
    
    if (strcmp(input, "now") == 0) {
        time_t t = time(NULL);
        struct tm *now = localtime(&t);
        printf("%04d.%02d.%02d\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    }
    else if (dot_count == 0) {
        // Календарь на год
        if (sscanf(input, "%d", &year) == 1) {
            for (int m = 1; m <= 12; m++) {
                print_month_calendar(year, m);
            }
        }
    }
    else if (dot_count == 1) {
        // Календарь на месяц
        if (sscanf(input, "%d.%d", &year, &month) == 2) {
            if (month >= 1 && month <= 12) {
                print_month_calendar(year, month);
            } else {
                printf("Invalid month!\n");
            }
        }
    }
    else if (dot_count == 2) {
        // День недели для конкретной даты
        if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3) {
            struct tm date = {0};
            date.tm_year = year - 1900;
            date.tm_mon = month - 1;
            date.tm_mday = day;
            date.tm_isdst = -1;

            if (mktime(&date) != -1) {
                const char *days[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
                printf("%s\n", days[date.tm_wday]);
            } else {
                printf("Invalid date!\n");
            }
        }
    }
    else {
        printf("Not correct input!\n");
    }
    
    return 0;
}
