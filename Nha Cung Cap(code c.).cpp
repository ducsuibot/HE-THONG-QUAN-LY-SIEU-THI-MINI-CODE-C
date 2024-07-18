#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_SUPPLIERS 100 
// ---------------------------------CODE CAC HAM QUAN LY NHA CUNG CAP---------------------------------//
typedef struct {
    int ma;
    char ten[50];
    char diaChi[100];
    char soDienThoai[15];
} NhaCungCap; 
NhaCungCap dsNhaCungCap[MAX_SUPPLIERS];
int soLuongNhaCungCap = 0;
// 1. Them nha cung cap
void themNhaCungCap() {
    if (soLuongNhaCungCap >= MAX_SUPPLIERS) {
        printf("Khong the them nha cung cap moi. Danh sach da day.\n");
        return;
    }
    NhaCungCap ncc;
    printf("Nhap ma nha cung cap: ");
    scanf("%d", &ncc.ma);
    printf("Nhap ten nha cung cap: ");
    getchar();
    gets(ncc.ten);
    printf("Nhap dia chi nha cung cap: ");
    gets(ncc.diaChi);
    printf("Nhap so dien thoai nha cung cap: ");
    gets(ncc.soDienThoai);
    dsNhaCungCap[soLuongNhaCungCap++] = ncc;
    printf("Them nha cung cap thanh cong!\n");
} 

// 2. Sua Nha Cung Cap
void suaNhaCungCap() {
    int ma, i;
    printf("Nhap ma nha cung cap can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhaCungCap; i++) {
        if (dsNhaCungCap[i].ma == ma) {
            printf("Nhap ten nha cung cap moi: ");
            getchar();
            gets(dsNhaCungCap[i].ten);
            printf("Nhap dia chi nha cung cap moi: ");
            gets(dsNhaCungCap[i].diaChi);
            printf("Nhap so dien thoai nha cung cap moi: ");
            gets(dsNhaCungCap[i].soDienThoai);
            printf("Sua thong tin nha cung cap thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nha cung cap voi ma da cho.\n");
}
 
// 3. Xoa nha cung cap
void xoaNhaCungCap() {
    int ma, i, j;
    printf("Nhap ma nha cung cap can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhaCungCap; i++) {
        if (dsNhaCungCap[i].ma == ma) {
            for (j = i; j < soLuongNhaCungCap - 1; j++) {
                dsNhaCungCap[j] = dsNhaCungCap[j + 1];
            }
            soLuongNhaCungCap--;
            printf("Xoa nha cung cap thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nha cung cap voi ma da cho.\n");
}
 
// 4.Tim nha cung cap
void timNhaCungCap() {
    int ma, i;
    printf("Nhap ma nha cung cap can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhaCungCap; i++) {
        if (dsNhaCungCap[i].ma == ma) {
            printf("Nha cung cap tim thay: Ma: %d, Ten: %s, Dia chi: %s, So dien thoai: %s\n",
                   dsNhaCungCap[i].ma, dsNhaCungCap[i].ten, dsNhaCungCap[i].diaChi, dsNhaCungCap[i].soDienThoai);
            return;
        }
    }
    printf("Khong tim thay nha cung cap voi ma da cho.\n");
} 
 
// 5. Luu nha cung cap vao FILE nhacungcap.txt
 void luuNhaCungCapVaoTep() {
    FILE *f = fopen("nhacungcap.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "SO LUONG NHA CUNG CAP: %d\n", soLuongNhaCungCap);
    for (int i = 0; i < soLuongNhaCungCap; i++) {
        fprintf(f, "Ma nha cung cap: %d\n Ten nha cung cap: %s\n%sDia chi nha cung cap: \n%sSDT nha cung cap: \n", dsNhaCungCap[i].ma, dsNhaCungCap[i].ten, dsNhaCungCap[i].diaChi, dsNhaCungCap[i].soDienThoai);
    }
    fclose(f);
    printf("Da luu danh sach nha cung cap vao tep nhacungcap.txt.\n");
} 
 
// 6. Hien nha cung cap tu FILE nhacungcap.txt 
void docNhaCungCapTuTep() {
    FILE *f = fopen("nhacungcap.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }   
    char buffer[1000]; // Do dai toi da cua moi dong trong file
    // Doc va in ra so luong Nha cung cap
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }   
    // Doc va in ra tung nha cung cap
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }   
    fclose(f);
}
