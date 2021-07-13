
#include "mylib.h"


using namespace std;
string menuName[16]{"1.  THEM VAT TU ",
					"2.  XOA VAT TU ",
					"3.  HIEU CHINH VAT TU ",
					"4.  IN DANH DACH VAT TU TON KHO ",
					"5.  THEM NHAN VIEN ",
					"6.  XOA NHAN VIEN ",
					"7.  HIEU CHINH NHAN VIEN ",
					"8.  IN DANH SACH NHAN VIEN ",
					"9.  LAP HOA DON NHAP ",
					"10.  LAP HOA DON XUAT ",
					"11. IN HOA DON ",
					"12. DS HOA DON CUA NHAN VIEN ",
					"13. THONG KE HOA DON ",
					"14. THONG KE VAT TU DOANH THU CAO NHAT ",
					"15. LUU VA THOAT "};
void GiaoDienChinh();
//In ra huong dan menu
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
//In ra khung bang danh sach
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
// In ra khung bang danh sach vat tu
void GiaoDienVatTu() {
	gotoxy(116, 4);
	cout << "DANH SACH VAT TU";
	KhungTieude(111, 3, 25);
	KhungDS();
	gotoxy(54,8);
	cout << "STT";
	gotoxy(65,8);
	cout << "MA VAT TU";
	gotoxy(112,8);
	cout << "TEN VAT TU";
	gotoxy(162, 8);
	cout << "DON VI";
	gotoxy(180, 8);
	cout << "SO LUONG TON";
	
}
// In ra khung bang danh sach nhan vien
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
//In menu chinh
void Printmenu(int vt) {
	int i ;
	set_color(240);
	gotoxy(Xmenu, ymenu);
	for (i=1; i <=15; i++)
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
	set_color(240);
	HuongDanMenu();
}
//Khung cua cua so chinh
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
//in ra huong dan chuc nang them nhan vien
void huongDanThemNhanVien(int color) {
	set_color(color);
	gotoxy(Xhuongdan, yhuongdan);
	cout << "-Ma nhan vien: chuoi chu va so khong";
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
//In ra huong dan them vat tu
void huongDanThemVatTu(int color) {
	set_color(color);
	gotoxy(Xhuongdan, yhuongdan);
	cout << "-Ma vat tu: chuoi chu va so khong khoang ";
	gotoxy(Xhuongdan, yhuongdan + 1);
	cout << "trang (Toi da : 10 ki tu.)";
	gotoxy(Xhuongdan, yhuongdan + 2);
	cout << "-TenVT: chuoi chu cai co khoang trang  ";
	gotoxy(Xhuongdan, yhuongdan + 3);
	cout << "(Toi da : 20 ki tu.)";
	gotoxy(Xhuongdan, yhuongdan + 4);
	cout << "-DV: Chuoi chu cai khong khoang trang ";
	gotoxy(Xhuongdan, yhuongdan + 5);
	cout << "(Toi da : 10 ki tu.)";
	gotoxy(Xhuongdan, yhuongdan + 6);
	cout << "-SLT: Chuoi so nguyen (0-999).";
	gotoxy(Xhuongdan, yhuongdan + 7);
	cout << "-Nhan phim 'ESC' de huy them thong tin.";
}
//In ra chuc nang xac nhan xoa hay khong
int xacNhanXoa(string mess) {
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
		case ESC:
			return -1;
			break;
		}
	} while (c!=Enter);
	set_color(240);
	return chon;
}
//Xoa noi dung trong phan thong bao
void xoaKhungThongBao() {
	set_color(255);
	int y=0;
	for (int i = 37; i < 45; i++)
	{
		for (int j = 2; j < 45; j++)
		{
			gotoxy(j, i);
			cout << "*";
		}
	}
	set_color(240);
}
//in ra thong bao co noi dung "str"
void thongBao(string str) {
		xoaKhungThongBao();
		gotoxy(Xthongbao, ythongbao);
		set_color(240);
		cout << str;
		Sleep(2000);
		xoaKhungThongBao();
}
//Xoa phan noi dung trong khung du lieu
void xoaKhungDuLieu() {
	set_color(255);
	int y = 0;
	for (int i = 2; i < 45; i++)
	{
		for (int j = 46; j < 202; j++)
		{
			gotoxy(j, i);
			cout << "*";
		}
	}
	set_color(240);
}
//Xoa phan noi dung trong khung huong dan
void xoaKhungHuongDan() {
	set_color(255);
	int y = 0;
	for (int i = 22; i < 35; i++)
	{
		for (int j = 2; j < 45; j++)
		{
			gotoxy(j, i);
			cout << "*";
		}
	}
	set_color(240);
}
//In ra khung hieu chinh nhan vien
void khungHieuChinhNhanVien(int x,int y) {
	for (int i = y; i < y+20; i++)
	{
		for (int j = x; j < x+50; j++)
		{
			set_color(51);
			gotoxy(j, i);
			cout << "-";
		}
	}
	set_color(63);
	gotoxy(x+15,y+1);
	cout << "CHINH SUA NHAN VIEN";
	gotoxy(x + 5, y + 7);
	cout << "MA NHAN VIEN:";
	gotoxy(x + 5, y + 9);
	cout << "HO NHAN VIEN:";
	gotoxy(x + 5, y + 11);
	cout << "TEN NHAN VIEN:";
	gotoxy(x + 5, y + 13);
	cout << "PHAI:";
	gotoxy(x + 12, y + 17);
	cout << "     ";
	gotoxy(x + 12, y + 18);
	cout << " LUU ";
	gotoxy(x + 12, y + 19);
	cout << "     ";
	gotoxy(x + 35, y + 17);
	cout << "     ";
	gotoxy(x + 35, y + 18);
	cout << " HUY ";
	gotoxy(x + 35, y + 19);
	cout << "     ";
	
	
	set_color(240);
}
//In ra khung hieu chinh vat tu
void khungHieuChinhVatTu(int x, int y) {
	for (int i = y; i < y + 20; i++)
	{
		for (int j = x; j < x + 50; j++)
		{
			set_color(51);
			gotoxy(j, i);
			cout << "-";
		}
	}
	set_color(63);
	gotoxy(x + 15, y + 1);
	cout << "CHINH SUA VAT TU";
	gotoxy(x + 5, y + 7);
	cout << "MA VAT TU:";
	gotoxy(x + 5, y + 9);
	cout << "TEN VAT TU:";
	gotoxy(x + 5, y + 11);
	cout << "DON VI:";
	gotoxy(x + 5, y + 13);
	cout << "SO LUONG TON:";
	gotoxy(x + 12, y + 17);
	cout << "     ";
	gotoxy(x + 12, y + 18);
	cout << " LUU ";
	gotoxy(x + 12, y + 19);
	cout << "     ";
	gotoxy(x + 35, y + 17);
	cout << "     ";
	gotoxy(x + 35, y + 18);
	cout << " HUY ";
	gotoxy(x + 35, y + 19);
	cout << "     ";


	set_color(240);
}
//Chon "YES" ,"NO" trong phan hieu chinh
int xacNhanHieuChinh(int x,int y) {
	xoaKhungHuongDan();
	gotoxy(Xhuongdan, yhuongdan);
	cout << "-Dung phim mui ten trai phai de di chuyen.";
	gotoxy(Xhuongdan, yhuongdan+1);
	cout << "-Nhan phim Enter de chon.";
	char c;
	bool chon = 0;
	do
	{
		set_color(63);
		gotoxy(x + 12, y + 17);
		cout << "     ";
		gotoxy(x + 12, y + 18);
		cout << " LUU ";
		gotoxy(x + 12, y + 19);
		cout << "     ";
		gotoxy(x + 35, y + 17);
		cout << "     ";
		gotoxy(x + 35, y + 18);
		cout << " HUY ";
		gotoxy(x + 35, y + 19);
		cout << "     ";

		if (chon == 0)
		{
			set_color(240);
			gotoxy(x + 35, y + 17);
			cout << "     ";
			gotoxy(x + 35, y + 18);
			cout << " HUY ";
			gotoxy(x + 35, y + 19);
			cout << "     ";
		}
		if (chon==1)
		{
			set_color(240);
			gotoxy(x + 12, y + 17);
			cout << "     ";
			gotoxy(x + 12, y + 18);
			cout << " LUU ";
			gotoxy(x + 12, y + 19);
			cout << "     ";
		}
		c = _getch();
		switch (c)
		{
		case Left:
				if (chon == 0)
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
		case ESC:
				return -1;
				break;
				
		}
	} while (c!=Enter);
	set_color(240);
	return chon;
}
//In huong dan phan hieu chinh
void huongDanHieuChinh() {
	gotoxy(Xhuongdan, yhuongdan);
	set_color(240);
	cout << "-Nhan Enter de qua thong tin khac.";
	gotoxy(Xhuongdan, yhuongdan+1);
	cout << "-Nhan ESC de thoat.";

}
void printLogo() {
	ifstream fin;
	fin.open("logo.txt", ios_base::in);
	int dong = 10;
	string str;
	string str1;
	while (fin.eof()!=true)
	{
		getline(fin, str);
		gotoxy(60, dong++);
		set_color(245);
		cout << str;
	}
}
void khungThongke() {
	for (int i = 50; i <= 196; i++)
	{
		char c = 196;
		set_color(240);
		gotoxy(i, 8);
		cout << c;
		gotoxy(i, 10);
		cout << c;
		if (i == 50)
		{
			gotoxy(i, 8);
			c = 218;
			cout << c;
			gotoxy(i, 9);
			c = 179;
			cout << c;
			gotoxy(i, 10);
			c = 195;
			cout << c;
		}
		if (i == 70 || i == 95 || i == 120 || i == 170)
		{
			gotoxy(i, 8);
			c = 194;
			cout << c;
			gotoxy(i, 9);
			c = 179;
			cout << c;
			gotoxy(i, 10);
			c = 197;
			cout << c;
		}
		if (i == 196)
		{
			gotoxy(i, 8);
			c = 191;
			cout << c;
			gotoxy(i, 9);
			c = 179;
			cout << c;
			gotoxy(i, 10);
			c = 180;
			cout << c;
		}
	}

}
void GiaoDienThongKe() {
	gotoxy(97, 4);
	cout << "BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
	gotoxy(98, 7);
	cout << "Tu ngay: dd/mm/yyyy";
	gotoxy(122, 7);
	cout << "Den ngay: dd/mm/yyyy";
	KhungTieude(91, 3, 60);
	khungThongke();
	gotoxy(55, 9);
	cout << "MA HOA DON";
	gotoxy(80, 9);
	cout << "NGAY LAP";
	gotoxy(100, 9);
	cout << "LOAI HOA DON";
	gotoxy(140, 9);
	cout << "HO TEN NV LAP";
	gotoxy(175, 9);
	cout << "TRI GIA HOA DON";
}
void duongKeDuoiThongKe(int y, int color) {
	set_color(color);
	for (int i = 51; i < 196; i++)
	{
		gotoxy(i, y);
		cout << char(196);
	}
	gotoxy(xkedoc1, y);
	cout << char(192);
	gotoxy(70, y);
	cout << char(193);
	gotoxy(95, y);
	cout << char(193);
	gotoxy(120, y);
	cout << char(193);
	gotoxy(170, y);
	cout << char(193);
	gotoxy(xkedoc6, y);
	cout << char(217);
}
void GiaoDienTop10VT() {
	gotoxy(100, 4);
	cout << "DANH SACH 10 VAT TU CO DOANH THU CAO NHAT";
	KhungTieude(92, 3, 60);
	gotoxy(95, 7);
	set_color(240);
	cout << "Tu ngay: dd/mm/yyyy";
	gotoxy(130, 7);
	cout << "Den ngay: dd/mm/yyyy";
	for (int i = 50; i <= 196; i++)
	{
		char c = 196;
		set_color(240);
		gotoxy(i, 8);
		cout << c;
		gotoxy(i, 10);
		cout << c;
		if (i == 50)
		{
			gotoxy(i, 8);
			c = 218;
			cout << c;
			gotoxy(i, 9);
			c = 179;
			cout << c;
			gotoxy(i, 10);
			c = 195;
			cout << c;
		}
		if (i == 60 || i == 80 || i == 156 || i == 176)
		{
			gotoxy(i, 8);
			c = 194;
			cout << c;
			gotoxy(i, 9);
			c = 179;
			cout << c;
			gotoxy(i, 10);
			c = 197;
			cout << c;
		}
		if (i == 196)
		{
			gotoxy(i, 8);
			c = 191;
			cout << c;
			gotoxy(i, 9);
			c = 179;
			cout << c;
			gotoxy(i, 10);
			c = 180;
			cout << c;
		}
	}

	gotoxy(54, 9);
	cout << "STT";
	gotoxy(65, 9);
	cout << "MA VAT TU";
	gotoxy(112, 9);
	cout << "TEN VAT TU";
	gotoxy(162, 9);
	cout << "DON VI";
	gotoxy(178, 9);
	cout << "SO LUONG DA BAN";

}
void khungDienNgay(int x, int y) {
	for (int i = y; i < y + 10; i++)
	{
		for (int j = x; j < x + 50; j++)
		{
			set_color(51);
			gotoxy(j, i);
			cout << "-";
		}
	}
	set_color(63);
	
	gotoxy(x + 15, y + 2);
	cout << "TU NGAY:";
	cout << "  __/__/____";
	gotoxy(x + 15, y + 4);
	cout << "DEN NGAY:";
	cout << " __/__/____";
	gotoxy(x + 12, y + 7);
	cout << "     ";
	gotoxy(x + 12, y + 8);
	cout << " LUU ";
	gotoxy(x + 12, y + 9);
	cout << "     ";
	gotoxy(x + 35, y + 7);
	cout << "     ";
	gotoxy(x + 35, y + 8);
	cout << " HUY ";
	gotoxy(x + 35, y + 9);
	cout << "     ";


	set_color(240);
}