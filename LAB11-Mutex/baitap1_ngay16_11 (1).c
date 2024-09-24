
//daophuduytan-3122560066

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
int account = 700;  //so du ban dau`

void* withdraw(void* arg) {
  pthread_mutex_lock(&mutex);
  account -= 200; 
  printf("Withdraw 200$, balance = %d$\n", account);
  pthread_mutex_unlock(&mutex);
  
  return NULL;
}

void* deposit(void* arg) {
  pthread_mutex_lock(&mutex);
  account += 300;
  printf("Deposit 300$, balance = %d$\n", account); 
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  
  pthread_mutex_init(&mutex, NULL);
  
  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, withdraw, NULL);
  pthread_create(&thread2, NULL, deposit, NULL); 

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  pthread_mutex_destroy(&mutex);

  return 0;
}