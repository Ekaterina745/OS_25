//Программа, получающая значения индентификаторов текущего родительского процесса
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	pid_t prid, parentprid;
	prid = getpid();
	parentprid = getppid();
	printf("Ид. текущего процесса: %d\n Ид. родительского процесса %d\n", prid, parentprid);
	return 0;
}
