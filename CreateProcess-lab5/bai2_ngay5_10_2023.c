#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int pnum, count, retval, child_no, parent_pid;
  char letter = 'A';
  char letterr = 'A';
  pnum = atoi(argv[1]);
  if(pnum <= 0)
  {
    printf("So tien trinh con phai lon hon 0.");
    return -1;
  }
  else
  {
    retval=1;
    // Tạo một mảng các tiến trình cha
    pid_t *parent_pids = (pid_t *)malloc(sizeof(pid_t) * pnum);
    for (int i = 0; i < pnum; i++) {
      parent_pids[i] = NULL;
    }

    for (count=0 ; count<pnum; count++)
    {
      retval=fork();
      if(retval!=0)
      {
        parent_pid = getppid();
        letter++ ;
      }
      else break;
    }

    // THoả mãn sơ đồ cây !!
    if (retval == 0) {
      child_no= count;
      if (letter == 'B' || letter == 'C') {
        parent_pids[child_no ] = getppid() +1;
      } else if (letter == 'D' || letter == 'E') 
      {
        parent_pids[child_no ] = getppid() +2; 
        letterr++ ;
      } else if (letter == 'F') {
        parent_pids[child_no ] = getppid() +3;
        letterr++ ;letterr++;
              }
    }

    // In ra thông tin của các tiến trình con
    if (retval == 0) {
      printf("\nTien trinh %c, PID %d, PID cha %d, Cha la %c \n", letter, getpid(), parent_pids[count], letterr);
    }

    // Kiểm tra xem tất cả các tiến trình con đã kết thúc hay chưa
    while (1) {
      int status;
      int child_pid = waitpid(-1, &status, 0);
      if (child_pid == -1) {
        break;
      }
    }

    // Giải phóng bộ nhớ cho mảng các tiến trình cha
    free(parent_pids);
  }
  return 0;
}