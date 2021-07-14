#pragma once
#include "HoaDon.h"
#include "NhanVien.h"
#include "giaodien.h"
#include "xulidulieu.h"
#include "Date.h"
HoaDon* createNodeHD() {
	HoaDon* p = new HoaDon;
	p->next = NULL;
	return p;
}
void themHoaDon(HoaDon* p,HoaDon* ds) {
	if (ds == NULL)
	{
		ds = p;
	}
	else
	{
		for (HoaDon* k = ds; k != NULL; k=k->next)
		{
			if (k->next==NULL)
			{
				k->next = p;
			}
		}
	}
}
void lapHoaDon(int x,int y,DSNV& ds,string date,int vt,char loai) {
	ShowCur(1);
	HoaDon* p = createNodeHD();
	p->soHD = sinhMaHoaDon(loai, date, ds.ds[vt]->dshd);
	gotoxy(x + 25, y + 5);
	set_color(63);
	cout << p->soHD;
	p->ngayLap = stodate(date);
	p->loai = loai;
	themHoaDon(p,ds.ds[vt]->dshd.head);
}

bool ktTrungHoaDon(HoaDon* ds,string ma) {
	HoaDon* p;
	for ( p = ds; p !=NULL; p= p->next)
	{
		if (p->soHD==ma)
		{
			return true;
		}
	}
	return false;
}