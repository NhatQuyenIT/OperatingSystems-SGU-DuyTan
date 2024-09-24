#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// hàm kiểm tra số nguyên tố 
bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false; 
  }
  return true;
}

// hàm in ra các số nguyên tố
void* printPrimes(void* arg) {
  int n = *(int*)arg;

  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
      printf("%d\t", i);
      printf("\n") ;
    }
  }
  
  pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);

  pthread_t tid;
  pthread_create(&tid, NULL, printPrimes, &n);

  pthread_join(tid, NULL);

  return 0;
}