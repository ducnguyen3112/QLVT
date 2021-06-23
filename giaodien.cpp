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
#define dau 3
#define cuoi 3
using namespace std;
string menuName[12]{ "1. THEM VAT TU ",
				"2. XOA VAT TU ",
				"3. HIEU CHINH VAT TU ",
				"4. THEM NHAN VIEN ",
				"5. XOA NHAN VIEN ",
				"6. HIEU CHINH NHAN VIEN ",
				"7. IN DANH SACH NHAN VIEN ",
				"8. LAP HOA DON NHAP ",
				"9. LAP HOA DON XUAT ",
				"10. THOAT "};
void KhungLamViec();
void Printmenu(int vt) {
	int i ;
	set_color(240);
	gotoxy(dau, cuoi);
	cout << "\t\tMENU\n";
	for (i=1; i <=11; i++)
	{
		if (i == vt) {
			set_color(5*16+7);
		}
		else {
			set_color(240);
		}
			gotoxy(dau+2, cuoi+2+i);
			cout << menuName[i-1];
			
		
	}
}
void menu(int vt) {
	char c;
	do
	{
		
		Printmenu(vt);
		KhungLamViec();
		c = _getch();
		switch (c)
		{
		case Up:vt--; 
			if (vt == 0) {
				vt = 10;
			}
			break;
		case Down:vt++;
			if (vt == 11) {
				vt = 1;
			}
			break;
		case ESC:
			exit(0);
		}
		cout << vt;
	} while (c!=13);
	switch (vt)
	{
	case 1:
		clrscr();
		cout << 1;
		break;
	case 2:
		clrscr();
		cout << 2;
		break;
	case 3:
		clrscr();
		cout << 3;
		break;
	case 4:
		clrscr();
		cout << 4;
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
void KhungLamViec() {
	set_color(240);
	set_color(240);
	for (int i = 1; i <= 202; i++)
	{
		set_color(51);
		gotoxy(i, 1);
		cout << "-";
		set_color(51);
		gotoxy(i, 45);
		cout << "-";
		if (i<35)
		{
			gotoxy(i,20);
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
		gotoxy(35, i);
		cout << "|";
		gotoxy(202, 45);
		set_color(240);
	}
	
}