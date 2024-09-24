#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int Tong(int n)
{
	int S=0;
	for(int i=1; i<=n; i++) S+=i;
	return S;
}

int Tonguocso(int n)
{
	int S=0;
	for(int i=1; i<=n; i++) if(n%i==0) S+=i;
	return S;
}

int main()
{
	int n;
	printf("Nhap n: "); scanf("%d", &n);
	pid_t pid = fork();
	if(pid != 0)
	{ 
		printf("Tong cua 1 + 2 + ... + n = % d , PID cha %d\n" , Tong(n) , getpid());
		wait(NULL);
	}
	else printf("tổng các ước số của n = %d , PID con %d\n", Tonguocso(n) , getpid());
	return 0;
}