#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main ()
{
	fork();
	printf("hello1 process ID: %d\n", getpid());
	printf("hello2 process ID: %d\n", getpid());
	wait(NULL);
	
}