#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_PRODUCTS 100 
// ---------------------------------CODE CAC HAM QUAN LY SAN PHAM-------------------------------------// 
 typedef struct {
    int ma;
    char ten[50];
    float gia;
    int soLuong;
} SanPham; 
SanPham dsSanPham[MAX_PRODUCTS];
int soLuongSanPham = 0;
// 1. Them san pham
void themSanPham() {
    if (soLuongSanPham >= MAX_PRODUCTS) {
        printf("Khong the them san pham moi. Danh sach da day.\n");
        return;
    }
    SanPham sp;
    printf("Nhap ma san pham: ");
    scanf("%d", &sp.ma);
    printf("Nhap ten san pham: ");
    getchar();
    gets(sp.ten);
    printf("Nhap gia san pham: ");
    scanf("%f", &sp.gia);
    printf("Nhap so luong san pham: ");
    scanf("%d", &sp.soLuong);
    dsSanPham[soLuongSanPham++] = sp;
    printf("Them san pham thanh cong!\n");
}
// 2. Sua san pham
void suaSanPham() {
    int ma, i;
    printf("Nhap ma san pham can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            printf("Nhap ten san pham moi: ");
            getchar();
            gets(dsSanPham[i].ten);
            printf("Nhap gia san pham moi: ");
            scanf("%f", &dsSanPham[i].gia);
            printf("Nhap so luong san pham moi: ");
            scanf("%d", &dsSanPham[i].soLuong);
            printf("Sua thong tin san pham thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da cho.\n");
}
// 3. Xoa san pham
void xoaSanPham() {
    int ma, i, j;
    printf("Nhap ma san pham can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            for (j = i; j < soLuongSanPham - 1; j++) {
                dsSanPham[j] = dsSanPham[j + 1];
            }
            soLuongSanPham--;
            printf("Xoa san pham thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da cho.\n");
}
 
// 4. Tim san pham theo ma
void timSanPham() {
    int ma, i;
    printf("Nhap ma san pham can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            printf("San pham tim thay: Ma: %d, Ten: %s, Gia: %.2f, So luong: %d\n",
                   dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].gia, dsSanPham[i].soLuong);
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da cho.\n");
}
// 5. Tim san pham theo ten
void timSanPhamTheoTen() {
    char ten[50];
    printf("Nhap ten san pham can tim: ");
    getchar();
    gets(ten);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].ten, ten) == 0) {
            printf("San pham tim thay: Ma: %d, Ten: %s, Gia: %.2f, So luong: %d\n",
                   dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].gia, dsSanPham[i].soLuong);
            return;
        }
    }
    printf("Khong tim thay san pham voi ten da cho.\n");
}
// 6. Sap xep san pham theo gia
void sapXepSanPhamTheoGia() {
    int i, j;
    for (i = 0; i < soLuongSanPham - 1; i++) {
        for (j = i + 1; j < soLuongSanPham; j++) {
            if (dsSanPham[i].gia > dsSanPham[j].gia) {
                SanPham temp = dsSanPham[i];
                dsSanPham[i] = dsSanPham[j];
                dsSanPham[j] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo gia tang dan.\n");
}
// 7. Sap xep san pham theo ten
void sapXepSanPhamTheoTen() {
    int i, j;
    for (i = 0; i < soLuongSanPham - 1; i++) {
        for (j = i + 1; j < soLuongSanPham; j++) {
            if (strcmp(dsSanPham[i].ten, dsSanPham[j].ten) > 0) {
                SanPham temp = dsSanPham[i];
                dsSanPham[i] = dsSanPham[j];
                dsSanPham[j] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo ten tang dan.\n");
}
 
// 8. Luu san pham vao FILE sanpham.txt
void luuSanPhamVaoTep() {
    FILE *f = fopen("sanpham.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "\nSO LUONG SAN PHAM:%d\n\n", soLuongSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        fprintf(f, "Ma san pham: %d\nTen san pham: %s\nGia san pham: %.0f\nSo luong: %d\n\n\n", dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].gia, dsSanPham[i].soLuong);
    }
    fclose(f);
    printf("Da luu danh sach san pham vao tep sanpham.txt.\n");
}  
 
// 9. Hien san pham tu FILE sanpham.txt ra man hinh
void docSanPhamTuTep() {
    FILE *f = fopen("sanpham.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    } 
    char buffer[1000]; // Do dai toi da cua moi dong trong file    
    // Doc va in ra so luong san pham
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }    
    // Doc va in ra tung san pham
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(f);
}

