#include <stdio.h>
int main (int argc, char* argv[], char* envp[]) {
printf("Программе передано %d аргументов \n\n", argc);
if(argc>=2){
for (int i =0; i<argc; i++)
	printf("Аргумент [%d]: %s\n", i,argv[i]);
printf("\n");
}
else {
 //список занчений переменных среды
 int j=0;
 
 while (envp[j]!=NULL) {
	 printf("%d %s\n", j, envp[j]);
		 j++;
             }
       }
}
