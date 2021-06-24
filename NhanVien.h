
#include "HoaDon.h"
#include "mylib.h"
using namespace std;
//Cau truc nhan vien
struct NhanVien
{
	string maNV;
	string hoNV;
	string tenNV;
	string phai;
	DSHD ds_hd;
	
};
//Cau truc danh sach nhan vien
struct DSNV
{
	NhanVien* dsnv[500];
	int sl = 0;
};
//==================================

//Kiem tra trung ma so nhan vien
int ktTrung(string str,DSNV ds_nv) {
	for (int i = 0; i < ds_nv.sl; i++)
	{
		if (ds_nv.dsnv[i]->maNV == str) {
			return i;
		}
	}
	return -1;
}
//Chuc nang them nhan vien
void themNhanVien(DSNV& dsnv) {
	
}