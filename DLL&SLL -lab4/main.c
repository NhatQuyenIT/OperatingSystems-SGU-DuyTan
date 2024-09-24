// main.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Phép tính không hợp lệ \n");
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);

    char operator = argv[2][0];

    void *handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Không thể mở thư viện động: %s\n", dlerror());
        return 1;
    }

    int (*math_function)(int, int);
    if (operator == '+') {
        math_function = dlsym(handle, "add");
    } else if (operator == '-') {
        math_function = dlsym(handle, "sub");
    } else {
        printf("Phép tính không hợp lệ: %c\n", operator);
        return 1;
    }

    if (!math_function) {
        fprintf(stderr, "Không thể tìm hàm: %s\n", dlerror());
        return 1;
    }

    int result = math_function(num1, num2);
    printf("Kết quả: %d\n", result);

    dlclose(handle);

    return 0;
}
