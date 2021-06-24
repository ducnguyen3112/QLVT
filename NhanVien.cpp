#include "NhanVien.h"
#include "mylib.h"
int ktTrung(string str, DSNV ds_nv) {
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
	nv->maNV = nhapMa(xdulieu2, y,10);
	if (nv->maNV.empty())
	{
		return false;
	}
	nv->hoNV = nhapChuoi(xdulieu3, y, 10);
	if (nv->hoNV.empty())
	{
		return false;
	}
	nv->tenNV = nhapChuoi(xdulieu4, y, 10);
	if (nv->tenNV.empty())
	{
		return false;
	}
	nv->phai = nhapChuoi(xdulieu5, y, 10);
	if (nv->phai.empty())
	{
		return false;
	}
		dsnv.ds[dsnv.sl] = nv;
		dsnv.sl++;
		return true;
}
void xuatDSNV(DSNV dsnv) {
	for (int i = 0; i < dsnv.sl; i++)
	{
		gotoxy(50, i + 14);
		set_color(240);
		cout << dsnv.ds[i]->maNV << dsnv.ds[i]->hoNV << dsnv.ds[i]->tenNV << dsnv.ds[i]->phai;
	}
}