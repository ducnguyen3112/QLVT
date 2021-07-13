#pragma once
#include "HoaDon.h"
#include "NhanVien.h"
#include "giaodien.h"
bool lapHoaDon(int x,int y) {
	string str,str2;
	ShowCur(1);
	str = nhapChuoi2(x + 25, y + 5, 10, str, 63);
	str2 = nhapNgay(x + 25, y + 7, 10, str2, 63);
	cout <<" "<< str2;
	return true;
}