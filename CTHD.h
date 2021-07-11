#pragma once
#include "mylib.h"
//Cau truc chi tiet hoa don
struct CTHD
{
	string maVT;
	int sl;
	int donGia;
	float VAT;
	bool trangThai;
};
//Cau truc danh sach chi tiet hoa don
struct DSCTHD
{
	CTHD ds_cthd[20];
	int sl = 0;
};