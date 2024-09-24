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
  key_t key = ftok(".", 'a');
  int msqid = msgget(key, 0666 | IPC_CREAT);

  struct message msg;

  // Tiến trình con
  pid_t pid = fork();

  if (pid == 0) {
    
    // Nhận số n từ tiến trình cha  
    msgrcv(msqid, &msg, sizeof(msg.data), 1, 0);
    int n = msg.data;

    // Tính n!
    int result = factorial(n);

    // Gửi kết quả về cho tiến trình cha
    msg.mtype = 2; 
    msg.data = result;
    msgsnd(msqid, &msg, sizeof(msg.data), 0);

  } else {

    // Tiến trình cha
    msg.mtype = 1;
    msg.data = atoi(argv[1]);
       if ( msg.data  <= 3)
         printf("Moi nhap so nguyen lon hon 3! \n");
      else{


     
       // Gửi số n cho tiến trình con
       msgsnd(msqid, &msg, sizeof(msg.data), 0);
       
       // Nhận kết quả từ tiến trình con 
       msgrcv(msqid, &msg, sizeof(msg.data), 2, 0);

       // In kết quả
       printf("%d! = %d\n", atoi(argv[1]), msg.data);

     }
  }

  return 0;  
}