#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_EMPLOYEES 100   
// ---------------------------------CODE CAC HAM QUAN LY NHAN VIEN------------------------------------//  
 typedef struct {
    int ma;
    char ten[50];
    float luong;
    char chucVu[50];
    char soDienThoai[15];
} NhanVien;  
 
NhanVien dsNhanVien[MAX_EMPLOYEES];
int soLuongNhanVien = 0;  

// 1. Them nhan vien
void themNhanVien() {
    if (soLuongNhanVien >= MAX_EMPLOYEES) {
        printf("Khong the them nhan vien moi. Danh sach da day.\n");
        return;
    }
    NhanVien nv;
    printf("Nhap ma nhan vien: ");
    scanf("%d", &nv.ma);
    printf("Nhap ten nhan vien: ");
    getchar();
    gets(nv.ten);
    printf("Nhap luong nhan vien: ");
    scanf("%f", &nv.luong);
    printf("Nhap chuc vu nhan vien: ");
    getchar();
    gets(nv.chucVu);
    printf("Nhap so dien thoai nhan vien: ");
    gets(nv.soDienThoai);
    dsNhanVien[soLuongNhanVien++] = nv;
    printf("Them nhan vien thanh cong!\n");
}
 
// 2. Sua nhan vien
void suaNhanVien() {
    int ma, i;
    printf("Nhap ma nhan vien can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            printf("Nhap ten nhan vien moi: ");
            getchar();
            gets(dsNhanVien[i].ten);
            printf("Nhap luong nhan vien moi: ");
            scanf("%f", &dsNhanVien[i].luong);
            printf("Nhap chuc vu nhan vien moi: ");
            getchar();
            gets(dsNhanVien[i].chucVu);
            printf("Nhap so dien thoai nhan vien moi: ");
            gets(dsNhanVien[i].soDienThoai);
            printf("Sua thong tin nhan vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ma da cho.\n");
}
 
// 3. Xoa nhan vien
void xoaNhanVien() {
    int ma, i, j;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            for (j = i; j < soLuongNhanVien - 1; j++) {
                dsNhanVien[j] = dsNhanVien[j + 1];
            }
            soLuongNhanVien--;
            printf("Xoa nhan vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ma da cho.\n");
}
 
// 4. Tim nhan vien
void timNhanVien() {
    int ma, i;
    printf("Nhap ma nhan vien can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            printf("Nhan vien tim thay: Ma: %d, Ten: %s, Luong: %.2f, Chuc vu: %s, So dien thoai: %s\n",
                   dsNhanVien[i].ma, dsNhanVien[i].ten, dsNhanVien[i].luong, dsNhanVien[i].chucVu, dsNhanVien[i].soDienThoai);
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ma da cho.\n");
}
 
// 5. Luu danh sach nhan vien vao FILE nhanvien.txt
void luuNhanVienVaoTep() {
    FILE *f = fopen("nhanvien.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "SO LUONG NHAN VIEN: %d\n", soLuongNhanVien);
    for (int i = 0; i < soLuongNhanVien; i++) {
        fprintf(f, "Ma nhan vien: %d\nTen nhan vien: %s\nLuong: %f\nChuc vu: %s\nSDT nhan vien:%s\n", dsNhanVien[i].ma, dsNhanVien[i].ten, dsNhanVien[i].luong, dsNhanVien[i].chucVu, dsNhanVien[i].soDienThoai);
    }
    fclose(f);
    printf("Da luu danh sach nhan vien vao tep nhanvien.txt.\n");
} 
 
// 6. Hien danh sach nhan vien tu FILE nhanvien.txt 
void docNhanVienTuTep() {
    FILE *f = fopen("nhanvien.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }   
    char buffer[1000]; // Do dai toi da cua moi dong trong file
    // Doc va in ra so luong Khan vien
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }   
    // Doc va in ra tung nhan vien
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }  
    fclose(f);
}
