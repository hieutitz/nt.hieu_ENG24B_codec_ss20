     #include <stdio.h>
#include <string.h>

typedef struct {
    char maSanPham[20];
    char tenSanPham[50];
    float giaNhap;
    float giaBan;
    int soLuong;
} SanPham;

void nhapThongTinSanPham(SanPham dsSanPham[], int *soLuongSanPham, float *doanhThu);
void hienThiSanPham(SanPham dsSanPham[], int soLuongSanPham);
void nhapSanPham(SanPham dsSanPham[], int *soLuongSanPham, float *doanhThu);
void capNhatSanPham(SanPham dsSanPham[], int soLuongSanPham);

int main() {
    SanPham dsSanPham[100];
    int soLuongSanPham = 0;
    float doanhThu = 0;
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSanPham(dsSanPham, &soLuongSanPham, &doanhThu);
                break;
            case 2:
                hienThiSanPham(dsSanPham, soLuongSanPham);
                break;
            case 3:
                nhapSanPham(dsSanPham, &soLuongSanPham, &doanhThu);
                break;
            case 4:
                capNhatSanPham(dsSanPham, soLuongSanPham);
                break;
            case 5: {
                break;
            }
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Doanh thu hien tai: %.2f\n", doanhThu);
                break;
            case 9:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

void nhapThongTinSanPham(SanPham dsSanPham[], int *soLuongSanPham, float *doanhThu) {
    printf("Nhap so luong san pham: ");
    scanf("%d", soLuongSanPham);
    for (int i = 0; i < *soLuongSanPham; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        scanf("%s", dsSanPham[i].maSanPham);
        printf("Ten san pham: ");
        getchar();
        fgets(dsSanPham[i].tenSanPham, sizeof(dsSanPham[i].tenSanPham), stdin);
        dsSanPham[i].tenSanPham[strcspn(dsSanPham[i].tenSanPham, "\n")] = '\0';
        printf("Gia nhap: ");
        scanf("%f", &dsSanPham[i].giaNhap);
        printf("Gia ban: ");
        scanf("%f", &dsSanPham[i].giaBan);
        printf("So luong: ");
        scanf("%d", &dsSanPham[i].soLuong);
        *doanhThu -= dsSanPham[i].soLuong * dsSanPham[i].giaNhap;
    }
}

void hienThiSanPham(SanPham dsSanPham[], int soLuongSanPham) {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < soLuongSanPham; i++) {
        printf("San pham thu %d:\n", i + 1);
        printf("Ma san pham: %s\n", dsSanPham[i].maSanPham);
        printf("Ten san pham: %s\n", dsSanPham[i].tenSanPham);
        printf("Gia nhap: %.2f\n", dsSanPham[i].giaNhap);
        printf("Gia ban: %.2f\n", dsSanPham[i].giaBan);
        printf("So luong: %d\n", dsSanPham[i].soLuong);
    }
}

void nhapSanPham(SanPham dsSanPham[], int *soLuongSanPham, float *doanhThu) {
    char maSanPham[20];
    printf("Nhap ma san pham: ");
    scanf("%s", maSanPham);
    for (int i = 0; i < *soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].maSanPham, maSanPham) == 0) {
            int soLuong;
            printf("Nhap so luong: ");
            scanf("%d", &soLuong);
            dsSanPham[i].soLuong += soLuong;
            *doanhThu -= soLuong * dsSanPham[i].giaNhap;
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("San pham moi!\n");
    strcpy(dsSanPham[*soLuongSanPham].maSanPham, maSanPham);
    printf("Nhap ten san pham: ");
    getchar();
    fgets(dsSanPham[*soLuongSanPham].tenSanPham, sizeof(dsSanPham[*soLuongSanPham].tenSanPham), stdin);
    dsSanPham[*soLuongSanPham].tenSanPham[strcspn(dsSanPham[*soLuongSanPham].tenSanPham, "\n")] = '\0';
    printf("Gia nhap: ");
    scanf("%f", &dsSanPham[*soLuongSanPham].giaNhap);
    printf("Gia ban: ");
    scanf("%f", &dsSanPham[*soLuongSanPham].giaBan);
    printf("So luong: ");
    scanf("%d", &dsSanPham[*soLuongSanPham].soLuong);
    *doanhThu -= dsSanPham[*soLuongSanPham].soLuong * dsSanPham[*soLuongSanPham].giaNhap;
    (*soLuongSanPham)++;
}

void capNhatSanPham(SanPham dsSanPham[], int soLuongSanPham) {
    char maSanPham[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", maSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].maSanPham, maSanPham) == 0) {
            printf("Nhap ten san pham moi: ");
            getchar();
            fgets(dsSanPham[i].tenSanPham, sizeof(dsSanPham[i].tenSanPham), stdin);
            dsSanPham[i].tenSanPham[strcspn(dsSanPham[i].tenSanPham, "\n")] = '\0';
            printf("Gia nhap moi: ");
            scanf("%f", &dsSanPham[i].giaNhap);
            printf("Gia ban moi: ");
            scanf("%f", &dsSanPham[i].giaBan);
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay ma san pham!\n");
}
    


