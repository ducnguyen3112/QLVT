
#include "giaodien.h"
#include "xulidulieu.h"
#include "NhanVien.h"
#include "VatTu.h"
#include "Date.h"
using namespace std;

void menu(int vt, DSNV& dsnv, DSVT& dsvt){
	char c;
	int dong;
	int max = 100;
	VatTu* ds[100];
	int index;
	bool b=true;
	string maNV_HD;
	printLogo();
	while (true)
	{

		xoaKhungDuLieu();
		xoaKhungHuongDan();
		xoaKhungThongBao();
		printLogo();
		do
		{
			Printmenu(vt);
			GiaoDienChinh();
			c = _getch();
			
			switch (c)
			{
			case Up:vt--;
				if (vt == 0) {
					vt = 15;
				}
				break;
			case Down:vt++;
				if (vt == 16) {
					vt = 1;
				}
				break;
			case ESC:
				exit(0);
			}

		} while (c != Enter);



		switch (vt)
		{
		case 1:				
			dong = dsvt.slvt + 10;
			xuatDSVT_TREE(dsvt, dsvt.TREE, 0);
			huongDanThemVatTu(240);			
			while (true)
			{
				duongKeDuoi(dong, 255);
				set_color(240);
				GiaoDienVatTu();				
				duongKeNganCach(dong);
				duongKeDuoi(dong + 1, 240);
				gotoxy(xstt, dong);
				cout << dong - 9;
				ShowCur(1);
				if (!themVatTu(dsvt, dong))
				{					
					huongDanThemVatTu(255);
					break;
				}
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them vat tu moi thanh cong.";
				Sleep(1000);
				set_color(255);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them vat tu moi thanh cong.";
				dong++;
			}
			break;
		case 2:			
			if (dsvt.slvt == 0)
			{
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the xoa!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}			
			while (true)
			{		
				int ndsx = 0;
				chuyenCay_Mang_Xoa(dsvt.TREE, ds, ndsx);
				sapXep_DSVT(ds, ndsx);
				GiaoDienVatTu();
				duongKeDuoi(ndsx + 10, 240);
				index = chonVatTu(dsvt, ds, ndsx);				
				if (index == -1)
				{
					giaiPhong_DSVT(ds, ndsx);
					break;					
				}
				int check = xacNhanXoa("Ban chac chan muon xoa?");
				if (check == 1)
				{
					xoaVatTu(dsvt, dsvt.TREE, ds, index, ndsx);
					thongBao("- Xoa vat tu thanh cong.");
					xoaKhungDuLieu();
					giaiPhong_DSVT(ds, ndsx=ndsx-1);					
				}
				else if (check == 0) {
					xoaKhungThongBao();
					index = chonVatTu(dsvt, ds, ndsx);
				}
				else if (check == -1)
				{					
					set_color(240);
					giaiPhong_DSVT(ds, ndsx);
					break;
				}
			}
			break;
		case 3:			
			if (dsvt.slvt == 0)
			{			
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the chinh sua!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}
			while (true)
			{
				int ndss = 0;
				GiaoDienVatTu();
				duongKeDuoi(dsvt.slvt + 10, 240);
				chuyenCay_Mang(dsvt.TREE, ds, ndss);
				//sapXep_DSVT(ds, ndss);
				index = chonVatTu(dsvt, ds, ndss);
				if (index == -1)
				{
					giaiPhong_DSVT(ds, ndss);
					xoaKhungDuLieu();
					break;
				}
				xoaKhungHuongDan();
				khungHieuChinhVatTu(90, 10);
				huongDanHieuChinh();
				int check = hieuChinhVatTu(dsvt,ds, index, 90, 10);
				if (check == 1)
				{
					xoaKhungHuongDan();
					thongBao("-Hieu chinh vat tu thanh cong.");
					xoaKhungDuLieu();
					HuongDanMenu();
					set_color(240);
					giaiPhong_DSVT(ds, ndss);

				}
				else if (check == 0) 
				{
					xoaKhungDuLieu();
					set_color(240);
				}
				else if (check == -1)
				{
					giaiPhong_DSVT(ds, ndss);
					xoaKhungDuLieu();
					set_color(240);
					break;
				}
			}
			break;
		case 4:			
			if (dsvt.slvt== 0)
			{
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the in!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}
			while (true)
			{
				int nds = 0;
				set_color(240);
				GiaoDienVatTu();
				xuatDSVT_TK(dsvt.TREE, ds, nds, -1);
				duongKeDuoi(nds + 10, 240);
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "-In danh sach vat tu ton kho thanh cong.";
				Sleep(5000);
				set_color(255);
			    gotoxy(Xthongbao, ythongbao);
				cout << "-In danh sach vat tu ton kho thanh cong.";
			}
			break;
		case 5:
			dong = dsnv.sl + 10;
			xuatDSNV(dsnv,-1);
			huongDanThemNhanVien(240);
			while (true)
			{
				duongKeDuoi(dong,255);
				set_color(240);
				GiaoDienNhanVien();
				duongKeNganCach(dong);
				duongKeDuoi(dong + 1,240);
				gotoxy(xstt, dong);
				cout << dong-9;
				ShowCur(1);
				if (!themNhanVien(dsnv,dong))
				{
					huongDanThemNhanVien(255);
					ShowCur(false);
					break;
				}
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them nhan vien moi thanh cong.";
				Sleep(1000);
				set_color(255);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them nhan vien moi thanh cong.";
				dong++;
				
			}
				
				
			break;
		case 6:
			if (dsnv.sl==0)
			{
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the xoa!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}
			while (true)
			{
				GiaoDienNhanVien();
				duongKeDuoi(dsnv.sl+10, 240);
				index = chonNhanVien(dsnv);
				if (index==-1)
				{
					break;
				}
				int check = xacNhanXoa("Ban chac chan muon xoa?");
				if (check==1)
				{
					xoaNhanVien(dsnv, index);
					thongBao("- Xoa nhan vien thanh cong.");
					xoaKhungDuLieu();
				}
				else if (check == 0) {
					xoaKhungThongBao();
					index = chonNhanVien(dsnv);
				}
				else if (check==-1)
				{
					set_color(240);
					break;
				}

				
			}
			
			break;
		case 7:
			while (true)
			{
				GiaoDienNhanVien();
				duongKeDuoi(dsnv.sl + 10, 240);
				
				index = chonNhanVien(dsnv);
				if (index==-1)
				{
					xoaKhungDuLieu();	
					break;
				}
				xoaKhungHuongDan();
				khungHieuChinhNhanVien(90, 10);
				huongDanHieuChinh();
				int check =hieuChinhNhanVien(dsnv, index, 90, 10);
				if (check == 1)
				{
					xoaKhungHuongDan();
					thongBao("-Hieu chinh nhan vien thanh cong.");
					xoaKhungDuLieu();
					HuongDanMenu();
					set_color(240);

				}
				else if (check == 0) {
					xoaKhungDuLieu();
		
					set_color(240);
				}
				else if (check == -1)
				{
					xoaKhungDuLieu();
					set_color(240);
					break;
				}
			}
			
			break;
		case 8:
			xoaKhungDuLieu();
			GiaoDienNhanVien();
			quickSortNhanVien(dsnv, 0, dsnv.sl-1);
			xuatDSNV(dsnv, -1);
			duongKeDuoi(dsnv.sl+10, 240);
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;

		case 8:
			
			while (true)
			{
				
				xoaKhungDuLieu();
				giaoDienNhapHoaDonXuat(90,15);
				set_color(63);
				int vitri = maNV_HD.length();
				int c;
				gotoxy(115, 20);
				cout << maNV_HD;
				string ngaylap;
				int chr;
				if (!maNV_HD.empty())
				{
					ngaylap = nhapNgay(115 , 22, 10, ngaylap, 63);
					ShowCur(0);
					if (xacNhanLapHoaDon(90, 7)==0)
					{
						break;
					}
					else{
						gotoxy(Xthongbao, ythongbao);
						cout << maNV_HD;
						cout << ngaylap;
					}
				}
				do {
					ShowCur(1);
					gotoxy(115 + vitri, 20);
					chr = _getch();
					if (((chr >= 'A' && chr <= 'Z') || (chr <= '9' && chr >= '0') || (chr >= 'a' && chr <= 'z')) && (vitri < 10))
					{
						maNV_HD.push_back(toupper(char(chr)));
						cout << maNV_HD.at(vitri);
						vitri++;
					}if (chr == 8 && vitri > 0)
					{
						vitri--;
						maNV_HD.pop_back();
						gotoxy(115 + vitri, 20);
						cout << " ";
						gotoxy(115 + vitri, 20);
					}
					if (chr == 13 && vitri != 0)
					{
						ShowCur(0);
						break;
					}
					if (chr == Tab)
					{
						xoaKhungDuLieu();
						GiaoDienNhanVien();
						c = chonNhanVien(dsnv);
						
						if (c==-1)
						{
							ShowCur(0);
							break;
						}
						else
						{
							maNV_HD = dsnv.ds[c]->maNV;
							ShowCur(0);
							break;
						}
					}
				} while (chr != ESC);
			}
			break;
		case 9:
			while (true)
			{

				xoaKhungDuLieu();
				giaoDienNhapHoaDonXuat(90, 15);
				set_color(63);
				int vitri = maNV_HD.length();
				int c;
				gotoxy(115, 20);
				cout << maNV_HD;
				string ngaylap;
				int chr;
				if (!maNV_HD.empty())
				{
					ngaylap = nhapNgay(115, 22, 10, ngaylap, 63);
					ShowCur(0);
					if (xacNhanLapHoaDon(90, 7) == 0)
					{
						break;
					}
					else {
						gotoxy(Xthongbao, ythongbao);
						cout << maNV_HD;
						cout << ngaylap;
					}
				}
				do {
					ShowCur(1);
					gotoxy(115 + vitri, 20);
					chr = _getch();
					if (((chr >= 'A' && chr <= 'Z') || (chr <= '9' && chr >= '0') || (chr >= 'a' && chr <= 'z')) && (vitri < 10))
					{
						maNV_HD.push_back(toupper(char(chr)));
						cout << maNV_HD.at(vitri);
						vitri++;
					}if (chr == 8 && vitri > 0)
					{
						vitri--;
						maNV_HD.pop_back();
						gotoxy(115 + vitri, 20);
						cout << " ";
						gotoxy(115 + vitri, 20);
					}
					if (chr == 13 && vitri != 0)
					{
						ShowCur(0);
						break;
					}
					if (chr == Tab)
					{
						xoaKhungDuLieu();
						GiaoDienNhanVien();
						c = chonNhanVien(dsnv);

						if (c == -1)
						{
							ShowCur(0);
							break;
						}
						else
						{
							maNV_HD = dsnv.ds[c]->maNV;
							ShowCur(0);
							break;
						}
					}
				} while (chr != ESC);
			}
			break;
		case 11:
			xoaKhungDuLieu();
			clrscr();
			cout << 9;
			break;
		case 12:
			xoaKhungDuLieu();
			khungDienNgay(90, 15);
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;
		case 13:
			xoaKhungDuLieu();
			GiaoDienThongKe();
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;
		case 14:
			xoaKhungDuLieu();
			GiaoDienTop10VT();
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;
		case 15:
			xoaKhungDuLieu();
			ghiFileNhanVien(dsnv);
			ghiFileVatTu(dsvt.TREE);
			exit(0);
			break;

		}
	}
}
int main(){
	DSNV dsnv;
	DSVT dsvt;
	docFileNhanVien(dsnv);
	docFileVatTu(dsvt);
	khoiTaoManHinh();
	menu(1,dsnv, dsvt);
	}