#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // Tạo thư mục "BaiTap" tại Desktop
  system("mkdir ~/Desktop/BaiTap");

  // Tạo thư mục "LyThuyet" và "ThucHanh" trong "BaiTap"
  system("mkdir ~/Desktop/BaiTap/LyThuyet");
  system("mkdir ~/Desktop/BaiTap/ThucHanh");

  // Tạo file rỗng với tên là "test" trong "ThucHanh"
  system("touch ~/Desktop/BaiTap/ThucHanh/test");

  // Thông báo đã hoàn thành
  printf("Đã hoàn thành!\n");

  return 0;
}