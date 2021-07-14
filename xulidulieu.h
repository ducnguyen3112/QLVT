#pragma once
#include "mylib.h"
#include "xulidulieu.h"
#include "HoaDon.h"
using namespace std;
string nhapChuoi(int x, int y, int length,string str, int color);
string nhapMa(int x, int y, int length, string str, int color);
string nhapNgay(int x, int y, int length, string str, int color);
string nhapChuoi2(int x, int y, int length, string str, int color);
string nhapSoNguyen(int x, int y, int length, string str, int color);
int doiThanhSo(string a);
string sinhMaHoaDon(char loai, string date, DSHD ds_hd);