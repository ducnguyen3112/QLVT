#include "NhanVien.h"
#include "mylib.h"
#include "giaodien.h"
int ktTrungNV(string str, DSNV ds_nv) {
	for (int i = 0; i < ds_nv.sl; i++)
	{
		if (ds_nv.ds[i]->maNV == str) {
			return i;
		}
	}
	return -1;
}
//Chuc nang them nhan vien
bool themNhanVien(DSNV& dsnv,int y) {
	NhanVien* nv = new NhanVien;
	string str;
	while (true)
	{
		gotoxy(xdulieu2, y);
		cout << "          ";
		str = nhapMa(xdulieu2, y, 10);
		if (ktTrungNV(str,dsnv)==-1)
		{
			nv->maNV = str;

			break;
		}
		gotoxy(Xthongbao, ythongbao);
		cout << "Ma so da ton tai.";
		Sleep(2000);
		gotoxy(Xthongbao, ythongbao);
		cout << "                 ";
	}
	if (nv->maNV.empty())
	{
		return false;
	}
	nv->hoNV = nhapChuoi(xdulieu3, y, 20);
	if (nv->hoNV.empty())
	{
		return false;
	}
	nv->tenNV = nhapChuoi(xdulieu4, y, 10);
	if (nv->tenNV.empty())
	{
		return false;
	}
	nv->phai = nhapChuoi2(xdulieu5, y, 3);
	if (nv->phai.empty())
	{
		return false;
	}
		dsnv.ds[dsnv.sl] = nv;
		dsnv.sl++;
		return true;
}

//Doc file nhan vien
void docFileNhanVien(DSNV &dsnv) {
	ifstream fin;
	fin.open("dsnv.txt", ios_base::in);
	while (fin.eof()!=true)
	{
		dsnv.ds[dsnv.sl] = new NhanVien;
		getline(fin, dsnv.ds[dsnv.sl]->maNV, ',');
		getline(fin, dsnv.ds[dsnv.sl]->hoNV, ',');
		getline(fin, dsnv.ds[dsnv.sl]->tenNV, ',');
		getline(fin, dsnv.ds[dsnv.sl]->phai, ',');
		fin.ignore();
	}
	fin.close();
}
void xuatDSNV(DSNV dsnv,int index) {
	int i;
	set_color(240);
	for (i = 0; i < dsnv.sl; i++)
	{
		if (i==index)
		{
			set_color(5*16);
		}
		else
		{
			set_color(240);
		}
		gotoxy(xstt, i+ 10);
		cout << i+1;
		gotoxy(xdulieu2, i+10);
		cout << dsnv.ds[i]->maNV;
		gotoxy(xdulieu3, i + 10);
		cout << dsnv.ds[i]->hoNV;
		gotoxy(xdulieu4, i + 10);
		cout << dsnv.ds[i]->tenNV;
		gotoxy(xdulieu5, i + 10);
		cout << dsnv.ds[i]->phai;
		set_color(240);
		duongKeNganCach(i + 10);
	}
}
//Hieu chinh vat tu
int chonNhanVien(DSNV dsnv) {
	ShowCur(false);
	char c;
	int vt = 0;
		do
		{
			set_color(240);
			xuatDSNV(dsnv,vt);
			c = _getch();
			switch (c)
			{
			case Up:vt--;
				if (vt == -1) {
					vt = dsnv.sl - 1;
				}
				break;
			case Down:vt++;
				if (vt == dsnv.sl) {
					vt = 0;
				}
				break;
			case ESC:
				return -1;
				break;
			}
		} while (c!=Enter);
		return vt;
}
//Xoa nhan vien duoc chon
//void xoaNhanVien(DSNV &dsnv ,int index) {
//	for (int i = index; i < dsnv.sl; i++)
//	{
//		dsnv.ds[i]->maNV = dsnv.ds[i + 1]->maNV;
//		dsnv.ds[i]->hoNV = dsnv.ds[i + 1]->hoNV;
//		dsnv.ds[i]->tenNV = dsnv.ds[i + 1]->tenNV;
//		dsnv.ds[i]->phai = dsnv.ds[i + 1]->phai;
//	}
//	NhanVien* nv = dsnv.ds[dsnv.sl - 1];
//	dsnv.sl--;
//}