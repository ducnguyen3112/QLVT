
#include "mylib.h"


using namespace std;
string menuName[14]{"1.  THEM VAT TU ",
					"2.  XOA VAT TU ",
					"3.  HIEU CHINH VAT TU ",
					"4.  THEM NHAN VIEN ",
					"5.  XOA NHAN VIEN ",
					"6.  HIEU CHINH NHAN VIEN ",
					"7.  IN DANH SACH NHAN VIEN ",
					"8.  LAP HOA DON NHAP ",
					"9.  LAP HOA DON XUAT ",
					"10. IN HOA DON ",
					"11. DS HOA DON CUA NHAN VIEN ",
					"12. THONG KE ",
					"13. THOAT "};
void GiaoDienChinh();
void HuongDanMenu() {
	gotoxy(Xhuongdan, yhuongdan);
	cout << "- Di chuyen thanh sang bang phim mui ten.";
	gotoxy(Xhuongdan, yhuongdan+1);
	cout << " len xuong.";
	gotoxy(Xhuongdan, yhuongdan + 2);
	cout << "- Nhan Enter de chon. Nhan ESC de thoat ";
	gotoxy(Xhuongdan, yhuongdan + 3);
	cout << "chuong trinh. ";
	gotoxy(Xhuongdan, yhuongdan + 4);
	cout << "khong duoc nhan qua nhanh. ";
}
void KhungTieude(int x,int y,int dai) {
	for (int i = 0; i < dai; i++)
	{
		set_color(51);
		gotoxy(x + i, y);
		cout << "-";
		gotoxy(x + i, y + 2);
		cout << "-";
		if (i<=2)
		{
			gotoxy(x, y+i);
			cout << "*";
			gotoxy(x+dai, y + i);
			cout << "*";
		}
	}
}
void KhungDS() {
	for (int i = 50; i <= 196; i++)
	{
		char c = 196;
		set_color(240);
		gotoxy(i, 7);
		cout << c;
		gotoxy(i, 9);
		cout << c;
		if (i == 50)
		{
			gotoxy(i, 7);
			c = 218;
			cout << c;
			gotoxy(i, 8);
			c = 179;
			cout << c;
			gotoxy(i, 9);
			c = 195;
			cout << c;
		}
		if (i == 60 || i == 80 || i == 156 || i == 176)
		{
			gotoxy(i, 7);
			c = 194;
			cout << c;
			gotoxy(i, 8);
			c = 179;
			cout << c;
			gotoxy(i, 9);
			c = 197;
			cout << c;
		}
		if (i == 196)
		{
			gotoxy(i, 7);
			c = 191;
			cout << c;
			gotoxy(i, 8);
			c = 179;
			cout << c;
			gotoxy(i, 9);
			c = 180;
			cout << c;
		}
	}
	
}
void GiaoDienVatTu() {
	gotoxy(116, 4);
	cout << "DANH SACH VAT TU";
	KhungTieude(111, 3, 25);
	KhungDS();
	gotoxy(54, 8);
	cout << "STT";
	gotoxy(65, 8);
	cout << "MA VAT TU";
	gotoxy(112, 8);
	cout << "TEN VAT TU";
	gotoxy(162, 8);
	cout << "DON VI";
	gotoxy(180, 8);
	cout << "SO LUONG TON";
	
}
void GiaoDienNhanVien() {
	gotoxy(115, 4);
	cout << "DANH SACH NHAN VIEN";
	KhungTieude(111, 3, 25);
	KhungDS();
	gotoxy(54, 8);
	cout << "STT";
	gotoxy(65, 8);
	cout << "MA NHAN VIEN";
	gotoxy(112, 8);
	cout << "HO VA TEN DEM";
	gotoxy(162, 8);
	cout << "TEN";
	gotoxy(180, 8);
	cout << "GIOI TINH";
}
void Printmenu(int vt) {
	int i ;
	set_color(240);
	gotoxy(Xmenu, ymenu);
	for (i=1; i <=14; i++)
	{
		if (i == vt) {
			set_color(5*16+7);
		}
		else {
			set_color(240);
		}
			gotoxy(Xmenu +2, ymenu +2+i);
			cout << menuName[i-1];
			
		
	}
	HuongDanMenu();
}

void GiaoDienChinh() {
	set_color(242);
	gotoxy(2, 2);
	cout << "====================MENU===================";
	gotoxy(2, 21);
	set_color(245);
	cout << "==================HUONG DAN================";
	gotoxy(2, 36);
	set_color(244);
	cout << "==================THONG BAO================";
	for (int i = 1; i <= 202; i++)
	{
		set_color(51);
		gotoxy(i, 1);
		cout << "-";
		set_color(51);
		gotoxy(i, 45);
		cout << "-";
		if (i<45)
		{
			gotoxy(i,20);
			cout << "-";
			gotoxy(i, 35);
			cout << "-";
		}
	}
	for (int i = 2; i <45; i++)
	{
		set_color(51);
		gotoxy(1, i);
		cout << "|";
		set_color(51);
		gotoxy(202, i);
		cout << "|";
		gotoxy(45, i);
		cout << "|";
		gotoxy(202, 45);
	}
		set_color(240);
	}
void duongKeNganCach(int y) {
	gotoxy(xkedoc1, y);
	cout << char(179);
	gotoxy(xkedoc2, y);
	cout << char(179);
	gotoxy(xkedoc3, y);
	cout << char(179);
	gotoxy(xkedoc4, y);
	cout << char(179);
	gotoxy(xkedoc5, y);
	cout << char(179);
	gotoxy(xkedoc6, y);
	cout << char(179);
}
void duongKeDuoi(int y,int color) {
	set_color(color);
	for (int i = 51; i < 196; i++)
	{
		gotoxy(i, y);
		cout << char(196);
	}
	gotoxy(xkedoc1, y);
	cout << char(192);
	gotoxy(xkedoc2, y);
	cout << char(193);
	gotoxy(xkedoc3, y);
	cout << char(193);
	gotoxy(xkedoc4, y);
	cout << char(193);
	gotoxy(xkedoc5, y);
	cout << char(193);
	gotoxy(xkedoc6, y);
	cout << char(217);
}
void huongDanThemNhanVien(int color) {
	set_color(color);
	gotoxy(Xhuongdan, yhuongdan);
	cout << "-Ma nhan vien: chuoi chu va so khong ";
	gotoxy(Xhuongdan, yhuongdan+1);
		cout<<"khoang trang(Toi da : 10 ki tu.)";
	gotoxy(Xhuongdan, yhuongdan+2);
	cout << "-Ho: Chuoi chu cai co khoang trang";
	gotoxy(Xhuongdan, yhuongdan + 3);
	cout<<"(Toi da: 20 ki tu.)";
	gotoxy(Xhuongdan, yhuongdan + 4);
	cout << "-Ten: Chuoi chu cai khong khoang trang";
	gotoxy(Xhuongdan, yhuongdan + 5);
	cout<<	"(Toi da : 10 ki tu.)";
	gotoxy(Xhuongdan, yhuongdan + 6);
	cout << "-Gioi tinh: NAM hoac NU";
	gotoxy(Xhuongdan, yhuongdan+7);
	cout << "-Nhan phim 'ESC' de huy them thong tin.";
}
void huongDanThemVatTu(int color) {
	set_color(color);
	gotoxy(Xhuongdan, yhuongdan);
	cout << "-Nhap thong tin theo tung cot.";
	gotoxy(Xhuongdan, yhuongdan + 1);
	cout << "-Nhan phim 'ESC' de huy them thong tin.";
}
bool xacNhan(string mess) {
	char c;
	bool chon = 0;
	set_color(240);
	gotoxy(Xthongbao, ythongbao);
	cout << mess;
	gotoxy(Xthongbao+9, ythongbao+2);
	cout << " YES ";
	gotoxy(Xthongbao + 30, ythongbao + 2);
	cout << " NO ";
	do
	{
		set_color(240);
		gotoxy(Xthongbao + 9, ythongbao + 2);
		cout << " YES ";
		gotoxy(Xthongbao + 30, ythongbao + 2);
		cout << " NO ";
		if (chon==0)
		{
			set_color(38);
			gotoxy(Xthongbao + 30, ythongbao + 2);
			cout << " NO ";
		}
		if (chon == 1)
		{
			set_color(38);
			gotoxy(Xthongbao + 9, ythongbao + 2);
			cout << " YES ";
		}
		c = _getch();
		switch (c)
		{
		case Left:
			if (chon==0)
			{
				chon = 1;
			}
			break;
		case Right:
			if (chon == 1)
			{
				chon = 0;
			}
			break;
		}
	} while (c!=Enter);
	set_color(240);
	return chon;
}
void xoaKhungThongBao() {
	set_color(255);
	int y=0;
	for (int i = 36; i < 45; i++)
	{
		for (int j = 2; j < 45; j++)
		{
			gotoxy(j, i);
			cout << "*";
		}
	}
}
void thongBaoXoa() {
		xoaKhungThongBao();
		gotoxy(Xthongbao, ythongbao);
		set_color(240);
		cout << "Xoa thanh cong.";
		Sleep(2000);
		xoaKhungThongBao();
}
