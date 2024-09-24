
//3122560066 -Đào phú duy tân


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

FILE *fptr;
int n;
int arr[100];
int soNguyenTo[100]; // Tạo một mảng tạm thời để lưu các số nguyên tố
int dem = 0; // Biến đếm số lượng số nguyên tố
int tongcacsonguyento = 0;
void* docfile(void* arg) {
   // char *filename = (char*) arg;
    if ((fptr = fopen("input.txt", "r")) == NULL) {
        printf("Error! Opening File\n");
        exit(1);
    }

    fscanf(fptr, "%d", &n);

    printf("So phan tu mang: %d\n", n);

    for (int i = 0; i < n; i++) {
        fscanf(fptr, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }

    printf("\n");

    fclose(fptr);
    pthread_exit(NULL);
}

int laNguyenTo(int num) {
    if (num < 2) return 0;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void* tinhTongNguyenTo(void* arg) {
    printf("Mang cac so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        if (laNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
            soNguyenTo[dem++] = arr[i]; // Lưu các số nguyên tố vào mảng tạm thời
        }
    }
    printf("\n");
    

    for (int i = 0; i < n; i++) {
        if (laNguyenTo(arr[i])) {
            tongcacsonguyento += arr[i];
        }
    }

    printf("Tong cac so nguyen to: %d\n", tongcacsonguyento);

    pthread_exit(NULL);
}

void* sapXepMang(void* arg) {
    for (int i = 0; i < dem - 1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (soNguyenTo[i] > soNguyenTo[j]) {
                int temp = soNguyenTo[i];
                soNguyenTo[i] = soNguyenTo[j];
                soNguyenTo[j] = temp;
            }
        }
    }

    printf("Mang cac so nguyen to da duoc sap xep: ");

    for (int i = 0; i < dem; i++) {
        printf("%d ", soNguyenTo[i]);
    }

    printf("\n");

    pthread_exit(NULL);
}

void* ghiFile(void* arg) {
    if ((fptr = fopen("result.txt", "w")) == NULL) {
        printf("Error! Opening File\n");
        exit(1);
    }

    fprintf(fptr, "So phan tu mang: %d\n", n);
	for (int i = 0; i < n; i++) {
        if (arr[i]) {
            fprintf(fptr, "%d ", arr[i]);
        }
    }

    fprintf(fptr, "\n");

	
     fprintf(fptr, "Mang cac so nguyen to:\n");

    for (int i = 0; i < n; i++) {
        if (laNguyenTo(arr[i])) {
            fprintf(fptr, "%d ", arr[i]);
        }
    }
    fprintf(fptr, "\n");
	 fprintf(fptr,"Tong cac so nguyen to: %d\n", tongcacsonguyento);

    fprintf(fptr, "Mang cac so nguyen to da sap xep:\n");

    for (int i = 0; i < dem; i++) {
        fprintf(fptr, "%d ", soNguyenTo[i]);
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t tid1, tid2, tid3, tid4;

    if (argc != 2) {
        printf("Sai cu phap. Hay nhap theo dinh dang: ./ten_chuong_trinh ten_tap_tin\n");
        return 1;
    }

    pthread_create(&tid1, NULL, docfile, (void*) argv[1]);
pthread_join(tid1, NULL);

    pthread_create(&tid2, NULL, tinhTongNguyenTo, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&tid3, NULL, sapXepMang, NULL);
    pthread_join(tid3, NULL);

    pthread_create(&tid4, NULL, ghiFile, NULL);
    pthread_join(tid4, NULL);

    return 0;
}