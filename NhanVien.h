#pragma once
#include "mylib.h"
#include "xulidulieu.h"
#include "VatTu.h"
using namespace std;
//Cau truc hoa don
struct Date
{
	int ngay;
	int thang;
	int nam;
};
struct CTHD
{
	string maVT;
	int soluong;
	int dongia;
	int VAT;
};
struct DSCTHD
{
	CTHD* hd= new CTHD[20];
	int sl = 0;
};
struct HoaDon
{
	string soHD;
	Date ngayLap;
	char loai;
	HoaDon* next;
	DSCTHD ds_cthd;
};
//cau truc danh sach hoa don
struct DSHD
{
	HoaDon* head = NULL;
	int sl = 0;
};
//Cau truc ngay

////=============================================================
bool ktNgay(string date);
//cau truc nhan vien
struct NhanVien
{
	string maNV;
	string hoNV;
	string tenNV;
	string phai;
	DSHD dshd;
	
};
//Cau truc danh sach nhan vien
struct DSNV
{
	NhanVien* ds[500];
	int sl = 0;
};
//==================================
bool themNhanVien(DSNV& dsnv, int y);
void xuatDSNV(DSNV dsnv,int index);
void docFileNhanVien(DSNV& dsnv);
int chonNhanVien(DSNV dsnv);
void xoaNhanVien(DSNV& dsnv, int index);
int hieuChinhNhanVien(DSNV& dsnv, int index, int x, int y);
void ghiFileNhanVien(DSNV dsnv);
void quickSortNhanVien(DSNV& dsnv, int low, int high);
int ktTrungNV(string str, DSNV ds_nv);
HoaDon* taoNodeHoaDon(DSNV& dsnv, int indexNV, char loai, string ngay,string shd);
string sinhMaHoaDon(char loai, DSHD ds);
void duyetHoaDon(DSNV dsnv, int index);
int chonHoaDon(DSNV dsnv, DSHD dshd);
void themHoaDon(HoaDon*& ds, HoaDon* p);
void themVatTuVaoHoaDon(DSCTHD& ds_cthd, tree t, char loai);
Date stodate(string  date);
void xuatDSHD_TrongTG(DSCTHD ds_cthd, DSHD ds, DSNV dsnv, Date date1, Date date2);

//Tinh ngay
bool kT_NamNhuan(Date date);
int ngay_Theo_Nam(Date date);
int ngay_Theo_Thang(Date date);
int demNgay(Date date);
bool kTNgay_Truoc(Date date1, Date date2);
