#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// hàm xử lý luồng in số lẻ 
void* printOdd(void* arg) {
  int n = *(int*)arg;
  int i;
  for (i=1; i<=n; i+=2) {
    printf("%d\n", i);
  }
  
  pthread_exit(NULL);
}

// hàm xử lý luồng in số chẵn
void* printEven(void* arg) {
  int n = *(int*)arg;
  int i;
  for (i=2; i<=n; i+=2) {
    printf("%d\n", i); 
  }

  pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
  pthread_t tid1, tid2;
  int n = atoi(argv[1]);

  // tạo luồng 1
  pthread_create(&tid1, NULL, printOdd, &n);  

  // tạo luồng 2
  pthread_create(&tid2, NULL, printEven, &n);

  // đợi 2 luồng kết thúc
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  
  return 0;
}