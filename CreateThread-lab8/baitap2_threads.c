#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// khai báo các biến toàn cục 
int nums[100]; // mảng chứa các số
int n; // số phần tử trong mảng

float avg; // giá trị trung bình 
int max; // giá trị lớn nhất
int min; // giá trị nhỏ nhất

// hàm tính trung bình cộng 
void* calcAvg(void* arg) {
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += nums[i];
  }
  avg = (float)sum/n;
  pthread_exit(NULL);
}

// hàm tìm giá trị lớn nhất
void* findMax(void* arg) {
  max = nums[0];
  for(int i=1; i<n; i++) {
    if(nums[i] > max) {
      max = nums[i];
    } 
  }
  pthread_exit(NULL);  
}

// hàm tìm giá trị nhỏ nhất 
void* findMin(void* arg) {
  min = nums[0];
  for(int i=1; i<n; i++) {
    if(nums[i] < min) {
      min = nums[i]; 
    }
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   // lấy số phần tử mảng 
  n = argc - 1;

  // khởi tạo mảng nums
  for(int i=0; i<n; i++){
    nums[i] = atoi(argv[i+1]); 
  }
  // tạo các luồng 
  pthread_t tid1, tid2, tid3;
  pthread_create(&tid1, NULL, calcAvg, NULL);
  pthread_create(&tid2, NULL, findMax, NULL); 
  pthread_create(&tid3, NULL, findMin, NULL);

  // join các luồng
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);

  // in kết quả
  printf("Avg: %.2f\n", avg);
  printf("Max: %d\n", max); 
  printf("Min: %d\n", min);

  return 0;
}