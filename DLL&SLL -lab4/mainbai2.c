#include <stdio.h>
#include <dlfcn.h> // Thư viện cho dynamic linking

int main() {
    // Load thư viện
    void *lib = dlopen("./libnhapxuat.so", RTLD_LAZY);
    if (!lib) {
        fprintf(stderr, "Không thể nạp thư viện: %s\n", dlerror());
        return 1;
    }

    // Lấy con trỏ đến hàm nhap và outputArray từ thư viện
    void (*nhap)(int *, int) = dlsym(lib, "nhap");
    void (*xuat)(int *, int) = dlsym(lib, "xuat");

    if (!nhap || !nhap) {
        fprintf(stderr, "Không thể lấy con trỏ đến hàm: %s\n", dlerror());
        dlclose(lib);
        return 1;
    }

    int size;
    printf("Nhập kích thước của mảng: ");
    scanf("%d", &size);

    int arr[size];

    // Gọi hàm nhap từ thư viện
    nhap(arr, size);

    // Gọi hàm outputArray từ thư viện
    xuat(arr, size);

    // Đóng thư viện
    dlclose(lib);

    return 0;
}
