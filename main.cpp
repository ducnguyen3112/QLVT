
#include "giaodien.h"
#include "xulidulieu.h"
#include "NhanVien.h"
#include "Date.h"
using namespace std;

void menu(int vt, DSNV& dsnv) {
	char c;
	int dong;
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
					vt = 14;
				}
				break;
			case Down:vt++;
				if (vt == 15) {
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
			xoaKhungDuLieu();
			set_color(240);
			gotoxy(35, 15);
			Sleep(10000);
			xuatDSNV(dsnv,1);
			break;
		case 2:
			xoaKhungDuLieu();

			break;
		case 3:
			xoaKhungDuLieu();
			clrscr();
			cout << 3;
			break;
		case 4:
			xoaKhungDuLieu();
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
		case 5:
			xoaKhungDuLieu();
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
		case 6:
			xoaKhungDuLieu();
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
		case 7:
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
		case 10:
			xoaKhungDuLieu();
			clrscr();
			exit(0);
			break;
		case 11:
			xoaKhungDuLieu();
			khungDienNgay(90, 15);
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;
		case 12:
			xoaKhungDuLieu();
			GiaoDienThongKe();
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;
		case 13:
			xoaKhungDuLieu();
			GiaoDienTop10VT();
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;
		case 14:
			xoaKhungDuLieu();
			ghiFileNhanVien(dsnv);
			exit(0);
			break;

		}
	}
}
int main(){
	DSNV ds_nv;
	docFileNhanVien(ds_nv);
	khoiTaoManHinh();
	menu(1,ds_nv);
	}