
// daophuduytan-3122560066 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int pipefd[2]; 
  pid_t pid;

  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) { // child process
    close(pipefd[0]); // close read end
    
    int n = atoi(argv[1]);
    int result = 1;
    for (int i = 1; i <= n; i++) {
      result *= i;
    }

    write(pipefd[1], &result, sizeof(result));
    close(pipefd[1]);

  } else { // parent process  
    close(pipefd[1]); // close write end

    int result;
    read(pipefd[0], &result, sizeof(result));
    printf("%d! = %d\n", atoi(argv[1]), result);
    close(pipefd[0]);
  }

  return 0;
}