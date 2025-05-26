//Программа №1 для элюстрации работы с разделяемой памятью 

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

int main() {
        //указатель на адрес, по которому будет находиться наша разделяемая память 	
         int *array;
	//IPC-дескриптор для обращения к области разделяемой памяти
	int shmid;
	//лаг, указывающий на необходмимость создания нового массива в разделяемой памяти
	int new = 1;
	//мя файла, предназначенное для генерации IPC-ключа
	char pathname[] = "pr011a.c";
	//еременная для хранения ipc-ключа
	key_t key;

	//енерация ipc-ключа
	if((key = ftok(pathname, 0))<0) {
                printf ("Не удалось сгенерировать ключ\n");
		exit(-1);
	}
	//Создание памяти в эксклюзивном режиме
	if((shmid =shmget(key, 3*sizeof(int), 0666 | IPC_CREAT | IPC_EXCL))<0) {
                if (errno != EEXIST) {
                  printf("Не удалось создать область разделяемой памяти\n");
		  exit(-1);
		}
		else {
			if((shmid = shmget(key, 3*sizeof(int), 0)) <0) {
				printf("Не удалось найти разделяемую память\n");
				exit(-1);
			}
			new = 0;
		}
           
	}
        if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {
              printf("Не можем присоеденить область разделяемой памяти к адресному пространству текущего процесса");
	      exit(-1);
	}
        if(new) {
           array[0] = 1;
	   array[1] = 0;
	   array[2] = 1;
	}	
	else {
           array[0] += 1;
	   array[2] += 1;
	}
	printf("Первая программа юыла запущена %d раз, вторая программа была запущенно %d раз, общее колличество запусков- %d\n", array[0], array[1], array[2]);
	if(shmdt(array) <0) {
           printf("Не удалось отсоеденить область разделяемой памяти");
	   exit(-1);
	}
	
       	return 0;
}
