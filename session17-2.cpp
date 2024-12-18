#include <stdio.h>
#include <stdlib.h>
const int maxLegth = 1000;
void nhapChuoi(char **str);
void inChuoi(char *str);
void demChu(char *str);
void demSo(char *str);
void demKyTu(char *str);
int main() {
    char *string = NULL;
    int choice;
    printf("\nMENU\n");
    printf("1. Nhap chuoi\n");
    printf("2. In chuoi\n");
    printf("3. Dem so luong chu cai trong chuoi và in ra\n");
    printf("4. Dem so luong chu so trong chuoi và in ra\n");
    printf("5. Dem so luong ky tu dac biet trong chuoi và in ra\n");
    printf("6. Thoat\n");
    do {
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                nhapChuoi(&string);
                break;
            case 2:
                inChuoi(string);
                break;
            case 3:
                demChu(string);
                break;
            case 4:
                demSo(string);
                break;
            case 5:
                demKyTu(string);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (1);
    free(string);
    return 0;
}

void nhapChuoi(char **str) {
    *str = (char *)malloc(maxLegth * sizeof(char));
    if (*str == NULL) {
        printf("Loi\n");
        exit(1);
    }
    printf("Nhap chuoi: ");
    fgets(*str, maxLegth, stdin);
    for (char *ptr = *str; *ptr != '\0'; ptr++) {
        if (*ptr == '\n') {
            *ptr = '\0';
            break;
        }
    }
}

void inChuoi(char *str) {
    if (str == NULL) {
        printf("Loi\n");
    } else {
        printf("Chuoi la: %s\n", str);
    }
}

void demChu(char *str) {
    if (str == NULL) {
        printf("Loi\n");
        return;
    }
    int count = 0;
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
            count++;
        }
    }
    printf("So luong chu cai la: %d\n", count);
}

void demSo(char *str) {
    if (str == NULL) {
        printf("Loi\n");
        return;
    }
    int count = 0;
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr >= '0' && *ptr <= '9') {
            count++;
        }
    }
    printf("So luong chu so la: %d\n", count);
}

void demKyTu(char *str) {
    if (str == NULL) {
        printf("Loi\n");
        return;
    }
    int count = 0;
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (!((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= '0' && *ptr <= '9'))) {
            count++;
        }
    }
    printf("So luong ky tu dac biet la: %d\n", count);
}

