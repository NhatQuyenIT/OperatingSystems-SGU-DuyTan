#include <sys/stat.h>
#include <fcntl.h>  
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n, f = 1, i, fd;

  // Tạo named pipe 
  mkfifo("mypipe", 0666);

  // Tiến trình cha
  if (fork() > 0) {
    
    // Mở named pipe để ghi
    fd = open("mypipe", O_WRONLY);
    
    // Lấy số n từ argv
    n = atoi(argv[1]);
    
    // Ghi n vào named pipe
    write(fd, &n, sizeof(int));
    
    // Đóng named pipe
    close(fd);

  } else {
  
    // Tiến trình con
    
    // Mở named pipe để đọc
    fd = open("mypipe", O_RDONLY);
  
    // Đọc số n từ named pipe
    read(fd, &n, sizeof(int));
  
    // Tính n!
    for(i=2; i<=n; i++)
      f *= i;
  
    // In kết quả
    printf("%d! = %d\n", n, f);
    
    // Đóng named pipe
    close(fd);
  
  }

  return 0;
}