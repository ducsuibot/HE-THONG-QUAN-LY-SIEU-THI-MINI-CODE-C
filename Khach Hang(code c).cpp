#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_CUSTOMERS 100 
// ---------------------------------CODE CAC HAM QUAN LY KHACH HANG------------------------------------// 
 typedef struct {
    int ma;
    char ten[50];
    char diaChi[100];
    char soDienThoai[15];
} KhachHang;
KhachHang dsKhachHang[MAX_CUSTOMERS];
int soLuongKhachHang = 0; 
// 1. Them khach hang
void themKhachHang() {
    if (soLuongKhachHang >= MAX_CUSTOMERS) {
        printf("Khong the them khach hang moi. Danh sach da day.\n");
        return;
    }
    KhachHang kh;
    printf("Nhap ma khach hang: ");
    scanf("%d", &kh.ma);
    printf("Nhap ten khach hang: ");
    getchar();
    gets(kh.ten);
    printf("Nhap dia chi khach hang: ");
    gets(kh.diaChi);
    printf("Nhap so dien thoai khach hang: ");
    gets(kh.soDienThoai);
    dsKhachHang[soLuongKhachHang++] = kh;
    printf("Them khach hang thanh cong!\n");
}
 
// 2. Sua khach hang
void suaKhachHang() {
    int ma, i;
    printf("Nhap ma khach hang can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            printf("Nhap ten khach hang moi: ");
            getchar();
            gets(dsKhachHang[i].ten);
            printf("Nhap dia chi khach hang moi: ");
            gets(dsKhachHang[i].diaChi);
            printf("Nhap so dien thoai khach hang moi: ");
            gets(dsKhachHang[i].soDienThoai);
            printf("Sua thong tin khach hang thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay khach hang voi ma da cho.\n");
}
 
// 3. Xoa khach hang
void xoaKhachHang() {
    int ma, i, j;
    printf("Nhap ma khach hang can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            for (j = i; j < soLuongKhachHang - 1; j++) {
                dsKhachHang[j] = dsKhachHang[j + 1];
            }
            soLuongKhachHang--;
            printf("Xoa khach hang thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay khach hang voi ma da cho.\n");
}
 
// 4. Tim khach hang theo ma
void timKhachHang() {
    int ma, i;
    printf("Nhap ma khach hang can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            printf("Khach hang tim thay: Ma: %d, Ten: %s, Dia chi: %s, So dien thoai: %s\n",
                   dsKhachHang[i].ma, dsKhachHang[i].ten, dsKhachHang[i].diaChi, dsKhachHang[i].soDienThoai);
            return;
        }
    }
    printf("Khong tim thay khach hang voi ma da cho.\n");
}
 
// 5. Luu thong tin khach hang vao FILE khachhang.txt
void luuKhachHangVaoTep() {
    FILE *f = fopen("khachhang.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "\nSO LUONG KHACH HANG: %d\n", soLuongKhachHang);
    for (int i = 0; i < soLuongKhachHang; i++) {
        fprintf(f, "Ma khach hang: %d\nTen khach hang: %s\nDia chi khach hang: %s\nSDT khach hang: %s\n", dsKhachHang[i].ma, dsKhachHang[i].ten, dsKhachHang[i].diaChi, dsKhachHang[i].soDienThoai);
    }
    fclose(f);
    printf("Da luu danh sach khach hang vao tep khachhang.txt.\n");
}    
// 6. Hien thong tin khach hang tu FILE khachhang.txt
void docKhachHangTuTep() {
    FILE *f = fopen("khachhang.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }   
    char buffer[1000]; // Do dai toi da cua moi dong trong file
    // Doc va in ra so luong Khach hang
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }   
    // Doc va in ra tung khach hang
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(f);
}

