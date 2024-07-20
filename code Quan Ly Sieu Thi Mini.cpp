#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Khai bao so luong phan tu mang cua cac struct =))
#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_SUPPLIERS 100
#define MAX_BILLS 100 
#define MAX_EMPLOYEES 100  
 

// Struct San pham =)) 
typedef struct {
    int ma;
    char ten[50];
    float gia;
    int soLuong;
} SanPham;
 
//Struct Khach hang =))
typedef struct {
    int ma;
    char ten[50];
    char diaChi[100];
    char soDienThoai[15];
} KhachHang;
 
// Struct Nhan vien =))
typedef struct {
    int ma;
    char ten[50];
    float luong;
    char chucVu[50];
    char soDienThoai[15];
} NhanVien; 
 
// Struct nha cung cap =))
typedef struct {
    int ma;
    char ten[50];
    char diaChi[100];
    char soDienThoai[15];
} NhaCungCap;
 
// Struct Hoa don =))
typedef struct {
    int ma;
    int maKhachHang;
    int maSanPham;
    int soLuong;
    float tongGia;
    float giamGia;
    float giaCuoi;
} HoaDon;
 
// Khoi tao so luong phan tu mang=0
SanPham dsSanPham[MAX_PRODUCTS];
int soLuongSanPham = 0;

KhachHang dsKhachHang[MAX_CUSTOMERS];
int soLuongKhachHang = 0; 
 
NhanVien dsNhanVien[MAX_EMPLOYEES];
int soLuongNhanVien = 0; 

NhaCungCap dsNhaCungCap[MAX_SUPPLIERS];
int soLuongNhaCungCap = 0;

HoaDon dsHoaDon[MAX_BILLS];
int soLuongHoaDon = 0;  


// Cac chuc nang cua Quan Ly San Pham =)))
void themSanPham();
void suaSanPham();
void xoaSanPham();
void timSanPham();
void timSanPhamTheoTen();
void sapXepSanPhamTheoGia();
void sapXepSanPhamTheoTen();
void luuSanPhamVaoTep(); 
void docSanPhamTuTep();

// Cac chuc nang cua Quan Ly Khach Hang =))
void themKhachHang();
void suaKhachHang();
void xoaKhachHang();
void timKhachHang();   
void luuKhachHangVaoTep(); 
void docKhachHangTuTep();
 
// Cac chuc nang cua Quan Ly Nhan Vien =))
void themNhanVien(); 
void suaNhanVien();
void xoaNhanVien();
void timNhanVien();
void luuNhanVienVaoTep();  
void docNhanVienTuTep();

// Cac chuc nang cua Quan Ly Nha Cung Cap =)))
void themNhaCungCap();
void suaNhaCungCap();
void xoaNhaCungCap();
void timNhaCungCap();  
void luuNhaCungCapVaoTep(); 
void docNhaCungCapTuTep();
 
// Cac chuc nang cua Quan Ly Hoa Don =)))
void themHoaDon();
void suaHoaDon();
void xoaHoaDon();
void timHoaDon(); 
void luuHoaDonVaoTep(); 
void docHoaDonTuTep();
void tinhTongDoanhThu();
void menuChinh();
 
 
// ---------------------------------CODE CAC HAM QUAN LY SAN PHAM-------------------------------------// 
 
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

 
// ---------------------------------CODE CAC HAM QUAN LY KHACH HANG------------------------------------// 
 
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

 
// ---------------------------------CODE CAC HAM QUAN LY NHAN VIEN------------------------------------//  
 
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

// ---------------------------------CODE CAC HAM QUAN LY NHA CUNG CAP---------------------------------//

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
        fprintf(f, "Ma nha cung cap: %d\n Ten nha cung cap: %s\nDia chi nha cung cap: %s\nSDT nha cung cap: %s\n", dsNhaCungCap[i].ma, dsNhaCungCap[i].ten, dsNhaCungCap[i].diaChi, dsNhaCungCap[i].soDienThoai);
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
 
// ---------------------------------CODE CAC HAM QUAN LY HOA DON-------------------------------------// 
 
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
        tongDoanhThu += dsHoaDon[i].giaCuoi; // cong lan luot tung phan tu trong mang
    }
    printf("Tong doanh thu: %.2f\n", tongDoanhThu);
}
 
   
// ---------------------------------CODE HAM MENU QUAN LY CAC CHUC NANG --------------------------------//    
    
void menuChinh() {
    int luaChon;
    do {
        printf("\n============= MENU =============\n");
        printf("1. Quan ly san pham\n");
        printf("2. Quan ly khach hang\n"); 
        printf("3. Quan ly nhan vien\n");
        printf("4. Quan ly nha cung cap\n");
        printf("5. Quan ly hoa don\n");
        printf("6. Tinh tong doanh thu\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                printf("\n============= QUAN LY SAN PHAM =============\n");
                printf("1. Them san pham\n");
                printf("2. Sua san pham\n");
                printf("3. Xoa san pham\n");
                printf("4. Tim san pham theo ma\n");
                printf("5. Tim san pham theo ten\n");
                printf("6. Sap xep san pham theo gia\n");
                printf("7. Sap xep san pham theo ten\n");
                printf("8. Luu danh sach san pham vao tep\n"); 
                printf("9. Hien thi danh sach san pham tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themSanPham();
                        break;
                    case 2:
                        suaSanPham();
                        break;
                    case 3:
                        xoaSanPham();
                        break;
                    case 4:
                        timSanPham();
                        break;
                    case 5:
                        timSanPhamTheoTen();
                        break;
                    case 6:
                        sapXepSanPhamTheoGia();
                        break;
                    case 7:
                        sapXepSanPhamTheoTen();
                        break;
                    case 8:
                        luuSanPhamVaoTep();
                        break; 
                    case 9 : 
                    	docSanPhamTuTep(); 
                    	break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break;
            case 2:
                printf("\n============= QUAN LY KHACH HANG =============\n");
                printf("1. Them khach hang\n");
                printf("2. Sua khach hang\n");
                printf("3. Xoa khach hang\n");
                printf("4. Tim khach hang\n");
                printf("5. Luu danh sach khach hang vao tep\n"); 
                printf("6. Hien danh sach khach hang tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themKhachHang();
                        break;
                    case 2:
                        suaKhachHang();
                        break;
                    case 3:
                        xoaKhachHang();
                        break;
                    case 4:
                        timKhachHang();
                        break;
                    case 5:
                        luuKhachHangVaoTep();
                        break; 
                    case 6: 
                    	docKhachHangTuTep(); 
                    	break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break; 
            case 3: 
            	printf("\n============= QUAN LY NHAN VIEN =============\n");
        printf("1. Them nhan vien\n");
        printf("2. Sua nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Tim nhan vien\n");
        printf("5. Luu danh sach nhan vien vao tep\n"); 
        printf("6. Hien danh sach nhan vien tu tep\n");
        printf("0. Quay lai\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                themNhanVien();
                break;
            case 2:
                suaNhanVien();
                break;
            case 3:
                xoaNhanVien();
                break;
            case 4:
                timNhanVien();
                break;
            case 5:
                luuNhanVienVaoTep();
                break; 
            case 6: 
            	docNhanVienTuTep(); 
            	break;
            case 0:
                return;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
             
            case 4:
                printf("\n============= QUAN LY NHA CUNG CAP =============\n");
                printf("1. Them nha cung cap\n");
                printf("2. Sua nha cung cap\n");
                printf("3. Xoa nha cung cap\n");
                printf("4. Tim nha cung cap\n");
                printf("5. Luu danh sach nha cung cap vao tep\n"); 
                printf("6. Hien danh sach nha cung cap tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themNhaCungCap();
                        break;
                    case 2:
                        suaNhaCungCap();
                        break;
                    case 3:
                        xoaNhaCungCap();
                        break;
                    case 4:
                        timNhaCungCap();
                        break;
                    case 5:
                        luuNhaCungCapVaoTep();
                        break; 
                    case 6: 
                    	docNhaCungCapTuTep(); 
                    	break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break;
            case 5:
                printf("\n============= QUAN LY HOA DON =============\n"); 
                
                printf("1. Them hoa don\n");
        		printf("2. Sua hoa don\n");
        		printf("3. Xoa hoa don\n");
        		printf("4. Tim hoa don\n");
        		printf("5. Luu danh sach hoa don vao tep\n"); 
        		printf("6. Hien danh sach hoa don tu tep\n");
        		printf("0. Quay lai\n");
       			printf("Lua chon cua ban: ");
       			 scanf("%d", &luaChon);
       			 switch (luaChon) {
          		  case 1:
              	      themHoaDon();
                	  break;
           		  case 2:
                	  suaHoaDon();
               		  break;
          		  case 3:
               		  xoaHoaDon();
                	  break;
           		  case 4:
               		  timHoaDon();
               		  break;
           		 case 5:
              		  luuHoaDonVaoTep();
                		break; 
                  case 6: 
                  		docHoaDonTuTep(); 
                  		break;
           		 case 0:
               		 return;
          		  default:
              		  printf("Lua chon khong hop le!\n");
                		break;
       			 } 
       			 break;
            case 6:
                printf("\n============= TINH TONG DOANH THU =============\n");
                tinhTongDoanhThu();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 0);
}
 
// ---------------------------------HAM MAIN--------------------------------//
int main() {
    menuChinh();
    return 0;
}



