#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex; 

int number = 1; 

void* printOdds() {

   while (number <= 10) {
    if (number % 2 != 0) {
      pthread_mutex_lock(&mutex);
      printf("%d ", number);
      pthread_mutex_unlock(&mutex);
      number++; 
    }
  }

  return NULL;
}


void* printEvens(){

   while (number <= 10) {
    if (number % 2 == 0) {
      pthread_mutex_lock(&mutex);
      printf("%d ", number);
      pthread_mutex_unlock(&mutex);
      number++;
    }
  }

  return NULL;
}

int main() {

  pthread_mutex_init(&mutex, NULL);

  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, printOdds, NULL);
  pthread_create(&thread2, NULL, printEvens, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  pthread_mutex_destroy(&mutex);

  return 0;
}