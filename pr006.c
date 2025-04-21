#include <stdio.h>
int main (int argc, char* argv[], char* envp[]) {
printf("Программе передано %d аргументов \n\n", argc);
for (int i =0; i<argc; i++)
	printf("Аргумент [%d]: %s\n", i,argv[i]);
printf("\n");
}	
