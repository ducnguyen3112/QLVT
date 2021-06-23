#include<iostream>
#include "mylib.h"
#include <conio.h>
#define Enter 13
#define ESC 27
#define Tab 9
#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define Space 32
#define Xmenu 4
#define ymenu 2
#define Xhuongdan 3
#define yhuongdan 23
#define Xthongbao 3
#define ythongbao 38

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
					"11. DS HOA DON CUA 1 NHAN VIEN ",
					"12. THONG KE ",
					"13. THOAT "};
void GiaoDienChinh();
void HuongDanMenu() {
	gotoxy(Xhuongdan, yhuongdan);
	cout << "- Di chuyen thanh sang bang phim mui ten";
	gotoxy(Xhuongdan, yhuongdan+1);
	cout << " len xuong.";
	gotoxy(Xhuongdan, yhuongdan + 2);
	cout << "- Nhan Enter de chon. Nhan ESC de thoat ";
	gotoxy(Xhuongdan, yhuongdan + 3);
	cout << "chuong trinh. ";
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
	cout << "SO LUONG TON";
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
void menu(int vt) {
	char c;
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
		
	} while (c!=13);
	switch (vt)
	{
	case 1:
		GiaoDienVatTu();
		break;
	case 2:
		
		break;
	case 3:
		clrscr();
		cout << 3;
		break;
	case 4:
		GiaoDienNhanVien();
		break;
	case 5:
		clrscr();
		cout << 5;
		break;
	case 6:
		clrscr();
		cout << 6;
		break;
	case 7:
		clrscr();
		cout << 7;
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
