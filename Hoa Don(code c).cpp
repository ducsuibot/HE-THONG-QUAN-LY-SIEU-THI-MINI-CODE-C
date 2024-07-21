#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_BILLS 100 
// ---------------------------------CODE CAC HAM QUAN LY HOA DON-------------------------------------// 
 typedef struct {
    int ma;
    int maKhachHang;
    int maSanPham;
    int soLuong;
    float tongGia;
    float giamGia;
    float giaCuoi;
} HoaDon; 
HoaDon dsHoaDon[MAX_BILLS];
int soLuongHoaDon = 0;  

 
// 1.Them hoa don 

void themHoaDon() {
    if (soLuongHoaDon >= MAX_BILLS) {
        printf("Khong the them hoa don moi. Danh sach da day.\n");
        return;
    }
    HoaDon hd;
    printf("Nhap ma hoa don: ");
    scanf("%d", &hd.ma);
    printf("Nhap ma khach hang: ");
    scanf("%d", &hd.maKhachHang);
    printf("Nhap ma san pham: ");
    scanf("%d", &hd.maSanPham);
    printf("Nhap so luong san pham mua : ");
    scanf("%d", &hd.soLuong);  
    for(int i=0;i<soLuongSanPham;i++) 
    {
    if(dsSanPham[i].ma==hd.maSanPham)  
   		{ 
   			 hd.tongGia = dsSanPham[i].gia * hd.soLuong;
		}
	}
    printf("Nhap giam gia: ");
    scanf("%f", &hd.giamGia);
    hd.giaCuoi = hd.tongGia - hd.giamGia;
    dsHoaDon[soLuongHoaDon++] = hd;
    printf("Them hoa don thanh cong!\n");
}
 
// 2. Sua hoa don
void suaHoaDon() {
    int ma, i;
    printf("Nhap ma hoa don can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            printf("Nhap ma khach hang moi: ");
            scanf("%d", &dsHoaDon[i].maKhachHang);
            printf("Nhap ma san pham moi: ");
            scanf("%d", &dsHoaDon[i].maSanPham);
            printf("Nhap so luong san pham moi: ");
            scanf("%d",&dsHoaDon[i].soLuong);
            for(int j=0;j<soLuongSanPham;j++) 
   				 {
   					 if(dsSanPham[j].ma==dsHoaDon[i].maSanPham)  // neu ma san pham trog danh sach = ma san phan trong hoa don ->
   					{ 
   							 dsHoaDon[i].tongGia = dsSanPham[j].gia * dsHoaDon[i].soLuong; 
					}
				}
            printf("Nhap giam gia moi: ");
            scanf("%f", &dsHoaDon[i].giamGia);
            dsHoaDon[i].giaCuoi = dsHoaDon[i].tongGia - dsHoaDon[i].giamGia;
            printf("Sua thong tin hoa don thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay hoa don voi ma da cho.\n");
}
 
// 3. Xoa hoa don
void xoaHoaDon() {
    int ma, i, j;
    printf("Nhap ma hoa don can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            for (j = i; j < soLuongHoaDon - 1; j++) {
                dsHoaDon[j] = dsHoaDon[j + 1];
            }
            soLuongHoaDon--;
            printf("Xoa hoa don thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay hoa don voi ma da cho.\n");
}
 
// 4. Tim hoa don theo ma
void timHoaDon() {
    int ma, i;
    printf("Nhap ma hoa don can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            printf("Hoa don tim thay: Ma: %d, Ma khach hang: %d, Ma san pham: %d, So luong: %d, Tong gia: %.2f, Giam gia: %.2f, Gia cuoi: %.2f\n",
                   dsHoaDon[i].ma, dsHoaDon[i].maKhachHang, dsHoaDon[i].maSanPham, dsHoaDon[i].soLuong, dsHoaDon[i].tongGia, dsHoaDon[i].giamGia, dsHoaDon[i].giaCuoi);
            return;
        }
    }
    printf("Khong tim thay hoa don voi ma da cho.\n");
} 
// 5. Luu hoa don vao FILE hoadon.txt
void luuHoaDonVaoTep() {
    FILE *f = fopen("hoadon.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "So Luong Hoa Don: %d\n\n", soLuongHoaDon);
    for (int i = 0; i < soLuongHoaDon; i++) {
        fprintf(f, "Ma Hoa Don: %d\nMa Khach Hang: %d | Ten Khach Hang: %s\nMa San Pham: %d | Ten san pham: %s\nSo Luong sp mua: %d\n", dsHoaDon[i].ma, dsHoaDon[i].maKhachHang,dsKhachHang[i].ten ,dsHoaDon[i].maSanPham,dsSanPham[i].ten, dsHoaDon[i].soLuong);
    }
    fclose(f);
    printf("Da luu danh sach nha cung cap vao tep hoadon.txt.\n");
}
 
// 6. Hien hoa don tu FILE hoadon.txt 
void docHoaDonTuTep() {
    FILE *f = fopen("hoadon.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }   
    char buffer[1000]; // Do dai toi da cua moi dong trong file
    // Doc va in ra so luong hoa don
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }   
    // Doc va in ra tung hoa don
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }  
    fclose(f);
} 
 

//---------------------------------HAM TINH TONG DOANH THU----------------------------------------------//
void tinhTongDoanhThu() {
    float tongDoanhThu = 0;
    for (int i = 0; i < soLuongHoaDon; i++) {
        tongDoanhThu += dsHoaDon[i].giaCuoi;
    }
    printf("Tong doanh thu: %.2f\n", tongDoanhThu);
}
