
#include "giaodien.h"
#include "xulidulieu.h"
#include "NhanVien.h"
using namespace std;

void menu(int vt, DSNV& dsnv) {
	char c;
	char c1;
	int dong;
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
			xuatDSNV(dsnv);
			break;
		case 2:

			break;
		case 3:
			clrscr();
			cout << 3;
			break;
		case 4:
			dong = 10;
			while (true)
			{
				GiaoDienNhanVien();
				ShowCur(1);
				if (!themNhanVien(dsnv,dong))
				{
					break;
				}
				dong++;
			}
				
				
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
}
int main(){
	DSNV ds_nv;
	
	khoiTaoManHinh();
	menu(1,ds_nv);
	
	
	}