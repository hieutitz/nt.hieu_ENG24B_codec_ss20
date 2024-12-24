#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maSach[20];
    char tenSach[50];
    char tacGia[50];
    float giaTien;
    char theLoai[30];
} Sach;

void nhapThongTinSach(Sach dsSach[], int *soLuongSach);
void hienThiThongTinSach(Sach dsSach[], int soLuongSach);
void themSachTaiViTri(Sach dsSach[], int *soLuongSach);
void xoaSachTheoMa(Sach dsSach[], int *soLuongSach);

int main() {
    Sach dsSach[100];
    int soLuongSach = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSach(dsSach, &soLuongSach);
                break;
            case 2:
                hienThiThongTinSach(dsSach, soLuongSach);
                break;
            case 3:
                themSachTaiViTri(dsSach, &soLuongSach);
                break;
            case 4:
                xoaSachTheoMa(dsSach, &soLuongSach);
                break;
            case 5:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 5);

    return 0;
}

void nhapThongTinSach(Sach dsSach[], int *soLuongSach) {
    printf("Nhap so luong sach: ");
    scanf("%d", soLuongSach);
    for (int i = 0; i < *soLuongSach; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", dsSach[i].maSach);
        printf("Ten sach: ");
        getchar();
        fgets(dsSach[i].tenSach, sizeof(dsSach[i].tenSach), stdin);
        dsSach[i].tenSach[strcspn(dsSach[i].tenSach, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(dsSach[i].tacGia, sizeof(dsSach[i].tacGia), stdin);
        dsSach[i].tacGia[strcspn(dsSach[i].tacGia, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &dsSach[i].giaTien);
        printf("The loai: ");
        getchar();
        fgets(dsSach[i].theLoai, sizeof(dsSach[i].theLoai), stdin);
        dsSach[i].theLoai[strcspn(dsSach[i].theLoai, "\n")] = '\0';
    }
}

void hienThiThongTinSach(Sach dsSach[], int soLuongSach) {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", dsSach[i].maSach);
        printf("Ten sach: %s\n", dsSach[i].tenSach);
        printf("Tac gia: %s\n", dsSach[i].tacGia);
        printf("Gia tien: %.2f\n", dsSach[i].giaTien);
        printf("The loai: %s\n", dsSach[i].theLoai);
    }
}

void themSachTaiViTri(Sach dsSach[], int *soLuongSach) {
    int viTri;
    printf("Nhap vi tri muon them (0 - %d): ", *soLuongSach);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > *soLuongSach) return;
    for (int i = *soLuongSach; i > viTri; i--) {
        dsSach[i] = dsSach[i - 1];
    }
    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%s", dsSach[viTri].maSach);
    printf("Ten sach: ");
    getchar();
    fgets(dsSach[viTri].tenSach, sizeof(dsSach[viTri].tenSach), stdin);
    dsSach[viTri].tenSach[strcspn(dsSach[viTri].tenSach, "\n")] = '\0';
    printf("Tac gia: ");
    fgets(dsSach[viTri].tacGia, sizeof(dsSach[viTri].tacGia), stdin);
    dsSach[viTri].tacGia[strcspn(dsSach[viTri].tacGia, "\n")] = '\0';
    printf("Gia tien: ");
    scanf("%f", &dsSach[viTri].giaTien);
    printf("The loai: ");
    getchar();
    fgets(dsSach[viTri].theLoai, sizeof(dsSach[viTri].theLoai), stdin);
    dsSach[viTri].theLoai[strcspn(dsSach[viTri].theLoai, "\n")] = '\0';
    (*soLuongSach)++;
    printf("Them sach thanh cong!\n");
}

void xoaSachTheoMa(Sach dsSach[], int *soLuongSach) {
    char maSach[20];
    printf("Nhap ma sach can xoa: ");
    scanf("%s", maSach);
    for (int i = 0; i < *soLuongSach; i++) {
        if (strcmp(dsSach[i].maSach, maSach) == 0) {
            for (int j = i; j < *soLuongSach - 1; j++) {
                dsSach[j] = dsSach[j + 1];
            }
            (*soLuongSach)--;
            printf("Xoa sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay ma sach!\n");
}

