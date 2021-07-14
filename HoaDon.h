#pragma once
#include "mylib.h"
#include "Date.h"
#include "CTHD.h"
#include "NhanVien.h"


//cau truc hoa don

struct HoaDon
{
	string soHD;
	char loai;
	Date ngayLap;
	CTHD dscthd;
	HoaDon* next;
};
//Cau truc danh sach hoa don
struct DSHD
{
	HoaDon* head = NULL;
	int sl = 0;
};
void lapHoaDon(int x, int y, DSNV& ds, string date, int vt, char loai);
void themHoaDon(HoaDon* p, HoaDon* ds);