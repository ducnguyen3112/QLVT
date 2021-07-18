#pragma once
#include "mylib.h"
#include<iostream>
#include <conio.h>
void Printmenu(int vt);
void GiaoDienChinh();
void GiaoDienVatTu();
void GiaoDienNhanVien();
void duongKeNganCach(int y);
void duongKeDuoi(int y,int color);
void HuongDanMenu();
void huongDanThemVatTu(int color);
void huongDanThemNhanVien(int color);
void xoaKhungThongBao();
void xoaKhungDuLieu();
void xoaKhungHuongDan();
void khungHieuChinhNhanVien(int x, int y);
void khungHieuChinhVatTu(int x, int y);
int xacNhanHieuChinh(int x, int y);
int xacNhanXoa(string mess);
void thongBao(string str);
void huongDanHieuChinh();
void printLogo();
void khungThongke();
void GiaoDienThongKe();
void duongKeDuoiThongKe(int y,int color);
void GiaoDienTop10VT();
void khungDienNgay(int x, int y);
void giaoDienNhapHoaDonXuat(int x, int y);
int xacNhanLapHoaDon(int x, int y);
void giaoDienNhapHoaDonNhap(int x, int y);
void giaoDienCTHD(char loai);
int xacNhanThemVT();
void giaoDienInHoaDon();