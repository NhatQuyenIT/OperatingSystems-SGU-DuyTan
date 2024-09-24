#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 12

int count = 0;
pthread_mutex_t mutex; 

void* passengerThread() {
  // mô phỏng khách lên thuyền
  pthread_mutex_lock(&mutex);
  printf("Khách lên thuyền\n");
  count++;

  if(count == 4) {
    crossRiver(); // đưa thuyền qua sông
    count = 0;
  }

  pthread_mutex_unlock(&mutex);
}

void crossRiver() {
  // mô phỏng đưa thuyền qua sông
  printf("+-------------------+ \n");
  printf("Đưa khach qua sông\n"); 
  printf("+-------------------+ \n");
}

int main() {

  pthread_t threads[NUM_THREADS];

  // khởi tạo mutex
  pthread_mutex_init(&mutex, NULL);

  // tạo các luồng mô phỏng khách 
  for(int i=0; i<NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, passengerThread, NULL);
  }

  // join tất cả các luồng
  for(int i=0; i<NUM_THREADS; i++) {
    pthread_join(threads[i], NULL); 
  }

  // hủy mutex
  pthread_mutex_destroy(&mutex);

  return 0;
}