#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isPositiveInteger(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int tong(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + tong(n - 1);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Có quá nhiều đối số\n");
        return 1;
    }
    if (!isPositiveInteger(argv[1])) {
        printf("Đối số không phải là số dương\n");
        return 1;
    }
    int n = atoi(argv[1]); // atoi để chuyển đổi chuỗi thành số nguyên

    printf("Tổng từ 1 đến %d là: %d\n", n, tong(n));
    return 0;
}
