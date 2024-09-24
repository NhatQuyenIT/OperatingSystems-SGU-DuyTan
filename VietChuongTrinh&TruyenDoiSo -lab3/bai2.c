#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPositiveInteger(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Không có đối số đầu vào.\n");
        return 1;
    }
    int *numbers = malloc((argc - 1) * sizeof(int));
    int validCount = 0;

    // Lọc và chuyển đổi các đối số thành số nguyên và lưu vào mảng numbers
    for (int i = 1; i < argc; i++) {
        if (isPositiveInteger(argv[i])) {
            numbers[validCount] = atoi(argv[i]);
            validCount++;
        }
    }
    // Sắp xếp danh sách số nguyên theo thứ tự tăng dần
    bubbleSort(numbers, validCount);
    // In ra danh sách số nguyên đã sắp xếp
    printf("Danh sách số nguyên sau khi sắp xếp tăng dần:\n");
    for (int i = 0; i < validCount; i++) 
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    //giai phong bo nho
    free(numbers);
    return 0;
}
