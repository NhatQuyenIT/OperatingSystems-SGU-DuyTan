#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

  int a, b, result;
  char op;

  // Tạo named pipe
  mkfifo("mypipe", 0666);

  // Tiến trình cha
  if (fork() > 0) {

    // Mở named pipe để ghi  
    int fd = open("mypipe", O_WRONLY);

    // Nhập dữ liệu
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    printf("Nhap phep toan: "); 
    scanf(" %c", &op);

    // Ghi dữ liệu vào named pipe
    write(fd, &a, sizeof(int));
    write(fd, &b, sizeof(int));
    write(fd, &op, sizeof(char));

    // Đóng named pipe
    close(fd);

  } else {

    // Tiến trình con

    // Mở named pipe để đọc
    int fd = open("mypipe", O_RDONLY);

    // Đọc dữ liệu từ named pipe
    read(fd, &a, sizeof(int));
    read(fd, &b, sizeof(int));
    read(fd, &op, sizeof(char));

    // Tính toán
    if (op == '+') {
      result = a + b; 
    } else if (op == '-') {
      result = a - b;
    } else if (op == '*') {
      result = a * b;
    } else {
      result = a / b;
    }

    // In kết quả
    printf("%d %c %d = %d\n", a, op, b, result);

    // Đóng named pipe
    close(fd);
  
  }

  return 0;
}