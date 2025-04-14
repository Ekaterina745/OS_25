//Программа пораждающая дочерний процесс (часть 2)/
//Процесс- родитель и процесс- ребенок должны выполнять разные дейчтвия 
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
pid_t procid, pprocid;
int a=0, b;
        procid = getpid();
        printf("До вызова fork() - %d\na=%d\n", procid, a);
        b = fork();
	if (b<0) {
	 //во время выполнения fork() произошла ошибка. Выходим из программы с возвратом кода -1
	 printf("Ошибка при выполнении fork()\n");
	 exit(-1);//выход из программы
	}
	else if (b==0) {
	       printf("\n\nПоявился дочерний процесс, получил значение %d\n", b);	
        procid = getpid();
        a = a+1; // проверяем изменение значения переменной а
           printf("После вызова fork() - %d\na=%d\n", procid,a);
	}
	else {
         printf("\n\nРодительский процесс после вызова fork() получил идентификатор ребенк: %d\n", b);
         procid = getpid();
	       a = a+1111; // проверяем изменение значения переменной а                                                printf("После вызова fork() - %d\na=%d\n", procid,a);
	}
	return 0;
}
