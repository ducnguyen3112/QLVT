#pragma once
#include "mylib.h"
#include "Date.h"
#include "CTHD.h"

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
bool lapHoaDon(int x, int y);