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
                printf("4. Tim san pham\n");
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
