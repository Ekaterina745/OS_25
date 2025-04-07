//Программа пораждающая дочерний процесс (часть 1)
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
	procid = getpid();
	a = a+1;
	printf("После вызова fork() - %d\na=%d\n", procid,a);
	return 0;
}
