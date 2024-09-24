#include <stdio.h>

void xuat(int *arr, int size) {
    printf("Mảng vừa nhập là:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}