
#include "giaodien.h"
#include "xulidulieu.h"
#include "NhanVien.h"
using namespace std;

void menu(int vt, DSNV& dsnv) {
	char c;
	int dong;
	int index;
	bool b=true;
	while (true)
	{

		clrscr();
		do
		{

			Printmenu(vt);
			GiaoDienChinh();
			c = _getch();
			switch (c)
			{
			case Up:vt--;
				if (vt == 0) {
					vt = 13;
				}
				break;
			case Down:vt++;
				if (vt == 14) {
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
			set_color(240);
			gotoxy(35, 15);
			Sleep(10000);
			xuatDSNV(dsnv,1);
			break;
		case 2:

			break;
		case 3:
			clrscr();
			cout << 3;
			break;
		case 4:
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
				index = chonNhanVien(dsnv);
				int check = xacNhan("Ban chac chan muon xoa?");
				if (check==1)
				{
					xoaNhanVien(dsnv, index);
					thongBaoXoa();
					xoaKhungDuLieu();
				}
				else if (check == 0) {
					xoaKhungThongBao();
					index = chonNhanVien(dsnv);
				}
				else if (check==-1)
				{
					break;
				}

				
			}
			
			break;
		case 6:
			GiaoDienNhanVien();
			index = chonNhanVien(dsnv);
			khungHieuChinh(90, 10);
			hieuChinhNhanVien(dsnv, index, 90, 10);
			break;
		case 7:
			break;

		case 8:
			clrscr();
			cout << 8;
			break;
		case 9:
			clrscr();
			cout << 9;
			break;
		case 10:
			clrscr();
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