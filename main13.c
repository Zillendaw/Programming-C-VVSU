#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// SIGABRT
void handle_abort(int sig) {
    printf("\nПолучен сигнал %d (SIGABRT). Аварийное завершение...\n", sig);
    exit(1); 
}

// SIGFPE
void handle_fpe(int sig) {
    printf("\nОшибка математики! (SIGFPE). Выходим, чтобы не зациклиться.\n");
    exit(1); 
}

// SIGILL
void handle_ill(int sig) {
    printf("\nПолучен сигнал %d (SIGILL). Спасаем программу от вылета из-за чёртовых указателей!\n", sig);
    exit(1); 
}

// SIGSEGV
void handle_segv(int sig) {
	printf("\nПолучен сигнал %d (SIGSEGV). Программа is down!\n", sig);
    exit(1); 
}

void pointer_test()
{
	int* ptr = NULL;
	printf("Указатель смотрит на адрес: %p\n", ptr);
	*ptr = 42;
}

// SIGINT
void handle_int(int sig) {
	printf("\nПолучен сигнал %d (SIGINT). Программу будем закрывать...\n", sig);
    exit(1); 
}

// SIGTERM
void handle_term(int sig) {
	printf("\nПолучен сигнал %d (SIGTERM). Программа будет УНИЧТОЖЕНА!\n", sig);
    exit(1); 
}

int main(int argc, char **argv)
{
	int input = 0;
	
	// Обработчики
	signal(SIGABRT,handle_abort);
	signal(SIGFPE,handle_fpe);
	signal(SIGILL,handle_ill);
	signal(SIGSEGV,handle_segv);
	signal(SIGINT, handle_int);
	signal(SIGTERM, handle_term);
	
	printf("Program is started!\n");
	while(input != -1)
	{
		printf("Введите число:\n");
		printf("1 - Вызвать SIGABRT (через abort())\n");
		printf("2 - Вызвать SIGFPE (деление на ноль)\n");
		printf("3 - Вызвать SIGILL (попытка отправить инструкцию)\n");
		printf("4 - Вызвать SIGINT (попытка прервать программу)\n");
		printf("5 - Вызвать SIGSEGV (попытка вызвать функцию)\n");
		printf("6 - Вызвать SIGTERM (попытка аварийно / принудительно завершить программу)\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
			printf("Инициализирую abort()...\n");
			abort();
			break;
			
			case 2:
			printf("Попробуем решить математику с делением на ноль...\n");
			int a = 5;
			int b = 0;
			int c = a / b;
			printf("Результат: %ls", &c);
			break;
			
			case 3:
			__asm__ __volatile__(".byte 0x0f, 0x0b"); // Инструкция UD2			break;
			break;
			
			case 4:
			while(1)
			{
				printf("CTRL + C нажми...\n");
				sleep(1);
			}
			
			case 5:
			pointer_test();
			printf("Инструкция соблюдена!\n");
			break;
			
			case 6:
			while(1)
			{
				printf("PID процесса: %d. Ожидаем kill программы: kill %d\n", getpid(), getpid());
				sleep(1);
			}
			break;
			
			default:
			printf("Не то число!\n");
		}
	}
	return 0;
}

