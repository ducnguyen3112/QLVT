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
		str = nhapMa(xdulieu2, y, 10,"",240);
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
	nv->hoNV = nhapChuoi(xdulieu3, y, 20,"", 240);
	if (nv->hoNV.empty())
	{
		return false;
	}
	nv->tenNV = nhapChuoi(xdulieu4, y, 10,"", 240);
	if (nv->tenNV.empty())
	{
		return false;
	}
	nv->phai = nhapChuoi2(xdulieu5, y, 3,"", 240);
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
	string str;
	while (fin.eof()!=true)
	{
		dsnv.ds[dsnv.sl] = new NhanVien;
		getline(fin, dsnv.ds[dsnv.sl]->maNV, '\n');
		if (dsnv.ds[dsnv.sl]->maNV.empty())
		{
			break;
		}
		getline(fin, dsnv.ds[dsnv.sl]->hoNV, '\n');
		getline(fin, dsnv.ds[dsnv.sl]->tenNV, '\n');
		getline(fin, dsnv.ds[dsnv.sl]->phai, '\n');
		string str;
		
		dsnv.sl++;
	}
	fin.close();
}
//ghi file nhan vien
void ghiFileNhanVien(DSNV dsnv) {
	ofstream fout;
	fout.open("dsnv.txt");
	for (int i = 0; i < dsnv.sl; i++)
	{
		fout << dsnv.ds[i]->maNV << endl;
		fout << dsnv.ds[i]->hoNV << endl;
		fout << dsnv.ds[i]->tenNV << endl;
		fout << dsnv.ds[i]->phai<< endl;
	}
	fout.close();
}
//Xuat ds nhan vien len bang
void xuatDSNV(DSNV dsnv,int index) {
	int i;
	set_color(240);
	for (i = 0; i < dsnv.sl; i++)
	{
		if (i==index)
		{
			set_color(63);
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
			duongKeDuoi(dsnv.sl + 10, 240);
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
void xoaNhanVien(DSNV &dsnv ,int index) {
	for (int i = index; i < dsnv.sl-1; i++)
	{
		dsnv.ds[i]->maNV = dsnv.ds[i + 1]->maNV;
		dsnv.ds[i]->hoNV = dsnv.ds[i + 1]->hoNV;
		dsnv.ds[i]->tenNV = dsnv.ds[i + 1]->tenNV;
		dsnv.ds[i]->phai = dsnv.ds[i + 1]->phai;
	}
	NhanVien* nv = dsnv.ds[dsnv.sl - 1];
	dsnv.sl--;
}
//Hieu chinh nhan vien duoc chon
int hieuChinhNhanVien(DSNV& dsnv, int index,int x,int y) {
	NhanVien* nv = new NhanVien();
	set_color(63);
	gotoxy(x + 20, y + 9);
	cout << dsnv.ds[index]->hoNV;
	gotoxy(x + 20, y + 11);
	cout << dsnv.ds[index]->tenNV;
	gotoxy(x + 20, y + 13);
	cout << dsnv.ds[index]->phai;
	string str;

	ShowCur(true);
	do
	{
		set_color(63);
		gotoxy(x + 20, y + 7);
		cout << "             ";
		nv->maNV = "";
		nv->maNV =nhapMa(x+20, y+7, 10, dsnv.ds[index]->maNV,63);
		if (nv->maNV == dsnv.ds[index]->maNV)
		{

			break;
		}
		if (ktTrungNV(str, dsnv) > -1)
		{
		gotoxy(Xthongbao, ythongbao);
		set_color(240);
		cout << "Ma so bi trung!Hay nhap lai.";
		Sleep(2000);
		xoaKhungThongBao();
		}
	} while (ktTrungNV(str,dsnv)>-1);
	nv->hoNV=nhapChuoi(x+20, y+9, 20, dsnv.ds[index]->hoNV, 63);
	nv->tenNV = nhapChuoi(x+20, y+11, 10, dsnv.ds[index]->tenNV, 63);
	nv->phai = nhapChuoi2(x+20, y+13, 3, dsnv.ds[index]->phai, 63);
	ShowCur(false);
	int confirm = xacNhanHieuChinh(x, y);
	xoaKhungHuongDan();
	if (confirm==1)
	{
		dsnv.ds[index]->maNV = nv->maNV;
		dsnv.ds[index]->hoNV = nv->hoNV;
		dsnv.ds[index]->tenNV = nv->tenNV;
		dsnv.ds[index]->phai = nv->phai;
		return 1;
	}
	else if (confirm == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
	return 0;
}
//Sap xep nhan vien
int partition(DSNV& dsnv, int low, int high)
{
	NhanVien* pivot = dsnv.ds[high];    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && dsnv.ds[left]->tenNV.compare(pivot->tenNV) <= 0) {
			
			if (dsnv.ds[left]->tenNV.compare(pivot->tenNV)==0)
			{
				if (dsnv.ds[left]->hoNV.compare(pivot->hoNV) >0)
				{
					break;
				}
			}
			left++;
		}
		while (right >= left && dsnv.ds[right]->tenNV.compare(pivot->tenNV) >= 0) {
			if (dsnv.ds[right]->tenNV.compare(pivot->tenNV) == 0)
			{
				if (dsnv.ds[right]->hoNV.compare(pivot->hoNV) < 0)
				{
					break;
				}
			}
			right--;
		}
		
		if (left >= right) break; 
		swap(dsnv.ds[left], dsnv.ds[right]); 
		left++; 
		right--; 
	}
	swap(dsnv.ds[left], dsnv.ds[high]);
	return left; 
}
void quickSortNhanVien(DSNV& dsnv, int low, int high)
{
	if (low < high)
	{
		int pi = partition(dsnv, low, high);
		quickSortNhanVien(dsnv, low, pi - 1);
		quickSortNhanVien(dsnv, pi + 1, high);
	}
}
