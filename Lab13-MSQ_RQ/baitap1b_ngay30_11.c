#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>

struct message {
  long mtype;
  int data;  
};

int factorial(int n) {
  if (n == 0) 
    return 1;
  return n * factorial(n-1);
}

int main(int argc, char* argv[]) {

  int n = atoi(argv[1]);
    if ( n <= 3)
  	printf("Moi nhap so khac lon hon 3 ! \n"); 
  else
  {

  int result = factorial(n);

  key_t key = ftok(".", 'a');
  int msqid = msgget(key, 0666 | IPC_CREAT);

  struct message msg;

  // Tiến trình 1
  msg.mtype = 1;
  msg.data = result;
  msgsnd(msqid, &msg, sizeof(msg.data), 0);

  // Tiến trình 2
  msgrcv(msqid, &msg, sizeof(msg.data), 1, 0); 

  printf("%d! = %d\n", atoi(argv[1]), msg.data);
  }
  return 0;
}