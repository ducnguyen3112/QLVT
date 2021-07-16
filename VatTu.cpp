#include "VatTu.h"
#include "mylib.h"
#include "giaodien.h"
#include "xulidulieu.h"

VatTu* khoiTaoNode_VatTu()
{
	VatTu* p = new VatTu;
	p->left = NULL;
	p->right = NULL;
	return p;
}

bool themVatTu(DSVT& dsvt, int y)
{
	VatTu *p = khoiTaoNode_VatTu();
	string str1, str2;
	while (true) 
	{
		gotoxy(xdulieu2, y);
		cout << "          ";
		str1 = nhapMa(xdulieu2, y, 10, "", 240);
		if (ktMaVT_Trung(dsvt.TREE,str1) == false)
		{
			p->maVT = str1;			
			break;
		}
		gotoxy(Xthongbao, ythongbao);
		cout << "Ma vat tu da ton tai.";
		Sleep(2000);
		gotoxy(Xthongbao, ythongbao);
		cout << "                     ";
	}
	if (p->maVT.empty())
	{
		return false;
	}
	p->tenVT = nhapChuoi3(xdulieu3, y, 20, "", 240);
	if (p->tenVT.empty())
	{
		return false;
	}
	p->DV = nhapChuoi3(xdulieu4, y, 10, "", 240);
	if (p->DV.empty())
	{
		return false;
	}
	str2 = nhapSoNguyen(xdulieu5, y, 3, "", 240);
	p->SLT = doiThanhSo(str2);	
	if (str2.length() == 0)
	{
		return false;
	}

	them_1_VatTu(dsvt.TREE, p);
	dsvt.slvt++;
	return true;
}
void them_1_VatTu(tree& t, VatTu* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->maVT > t->maVT)
		{
			them_1_VatTu(t->right, p);
		}
		else if (p->maVT < t->maVT)
		{
			them_1_VatTu(t->left, p);
		}
	}
}

bool ktMaVT_Trung(tree t, string ma)
{
	if (t == NULL)
		return false;
	else
	{
		if (t->maVT == ma)
			return true;
		else if (t->maVT > ma)
			return ktMaVT_Trung(t->left, ma);
		else if (t->maVT < ma)
			return ktMaVT_Trung(t->right, ma);							
	}
	return false;
}
//int ktTrungMaVT(string ma,VatTu* a[],int sl) {
//	for (int i = 0; i < sl; i++)
//	{
//		if (a[i]->maVT == ma) {
//			return i;
//		}
//	}
//	return -1;
//}
//=========Đọc file vật tư==========
void docFileVatTu(DSVT& dsvt) {
	ifstream fin;
	fin.open("dsvt.txt", ios_base::in);
     while (fin.eof() != true)
     {
		 VatTu *p = khoiTaoNode_VatTu();
		 getline(fin, p->maVT, '\n');
		 if (p->maVT.empty())
		 {
		  	 break;
		 }
		 string slt;
		 getline(fin, p->tenVT, '\n');
		 getline(fin, p->DV, '\n');
		 fin >> p->SLT;
		 getline(fin, slt, '\n');
		 them_1_VatTu(dsvt.TREE, p);
		 dsvt.slvt++;
	 }	
	 fin.close();
}
//=========Ghi file vật tư==========
void ghiFileVatTu(tree t)
{
	ofstream fout;
	fout.open("dsvt.txt", ios_base::out);
	ghiFile_NLR(fout,t);
	fout.close();
}
void ghiFile_NLR(ofstream& fout,tree t) {
	if (t!=NULL)
	{
		fout << t->maVT << endl
			 << t->tenVT<< endl
			 << t->DV   << endl
			 << t->SLT  << endl;
		ghiFile_NLR(fout, t->left);
		ghiFile_NLR(fout, t->right);
	}
}
//=========Xuất danh sách vật tư theo cây nhị phân=========
void xuatDSVT_TREE(DSVT& dsvt, tree t, int i)
{
	if (t != NULL)
	{		
			set_color(240);
			gotoxy(xstt, i + 10);
			cout << i + 1;
			gotoxy(xdulieu2, i + 10);
			cout << t->maVT;
			gotoxy(xdulieu3, i + 10);
			cout << t->tenVT;
			gotoxy(xdulieu4, i + 10);
			cout << t->DV;
			gotoxy(xdulieu5, i + 10);
			cout << t->SLT;
			set_color(240);
			duongKeNganCach(i + 10);		
		xuatDSVT_TREE(dsvt, t->left, i++);
		xuatDSVT_TREE(dsvt, t->right, i++);
	}
}
//==========Xuất danh sách vật tư tồn kho lên bảng==========
void xuatDSVT_TK(tree t, VatTu* ds[], int& nds, int index)
{
	chuyenCay_Mang_TK(t, ds, nds);
	sapXep_DSVT(ds, nds);
	inDSVT(ds, nds, index);
	giaiPhong_DSVT(ds, nds);
}
//==========Các bước xuất danh sách vật tư==========
//===Chuyển cây sang mảng con trỏ===
void chuyenCay_Mang(tree t, VatTu* ds[],int& nds)
{
	if (t != NULL)
	{
		//data
		ds[nds] = new VatTu;
	    ds[nds]->maVT = t->maVT;
	    ds[nds]->tenVT = t->tenVT;
	    ds[nds]->DV = t->DV;
		ds[nds]->SLT = t->SLT;
		nds++;
		chuyenCay_Mang(t->left, ds, nds);
		chuyenCay_Mang(t->right, ds, nds);
	}
}
void chuyenCay_Mang_Xoa(tree t, VatTu* ds[], int& nds)
{
	if (t != NULL)
	{
		if (t->SLT == 0)
		{
			//data
			ds[nds] = new VatTu;
			ds[nds]->maVT = t->maVT;
			ds[nds]->tenVT = t->tenVT;
			ds[nds]->DV = t->DV;
			ds[nds]->SLT = t->SLT;
			nds++;
		}
		chuyenCay_Mang_Xoa(t->left, ds, nds);
		chuyenCay_Mang_Xoa(t->right, ds, nds);
	}
}
void chuyenCay_Mang_TK(tree t, VatTu* ds[], int& nds)
{
	if (t != NULL)
	{
		if (t->SLT > 0)
		{
			//data
			ds[nds] = new VatTu;
			ds[nds]->maVT = t->maVT;
			ds[nds]->tenVT = t->tenVT;
			ds[nds]->DV = t->DV;
			ds[nds]->SLT = t->SLT;
			nds++;
		}	
		chuyenCay_Mang_TK(t->left, ds, nds);
		chuyenCay_Mang_TK(t->right, ds, nds);
	}
}
//===Sắp xếp danh sách vật tư===
void sapXep_DSVT(VatTu* ds[], int& nds)
{
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (ds[i]->tenVT > ds[j]->tenVT)
				hoanVi_2VatTu(ds[i], ds[j]);
		}
	}
}

//===In danh sách vật tư===
void inDSVT(VatTu* ds[], int& nds, int index)
{
	int i;
	set_color(240);
	for (int i = 0; i < nds; i++)
	{
		if (i == index)
		{
			set_color(63);
		}
		else
		{
			set_color(240);
		}
		gotoxy(xstt, i + 10);
		cout << i + 1;
		gotoxy(xdulieu2, i + 10);
		cout << ds[i]->maVT;
		gotoxy(xdulieu3, i + 10);
		cout << ds[i]->tenVT;
		gotoxy(xdulieu4, i + 10);
		cout << ds[i]->DV;
		gotoxy(xdulieu5, i + 10);
		cout << ds[i]->SLT;
		set_color(240);
		duongKeNganCach(i + 10);
	}

}
//===Giải phóng===
void giaiPhong_DSVT(VatTu* ds[], int& nds)
{
	for (int i = 0; i < nds; i++)
	{
		delete ds[i];
	}
}

//==========Xóa vật tư được chọn==========
int chonVatTu(VatTu* ds[], int& nds) {
	ShowCur(false);
	char c;
	int vt = 0;	
	do
	{
		set_color(240);
		inDSVT(ds, nds, vt);
		duongKeDuoi(nds + 10, 240);

		c = _getch();
		switch (c)
		{
		case Up:vt--;
			if (vt == -1) {
				vt = nds- 1;
			}
			break;
		case Down:vt++;
			if (vt == nds) {
				vt = 0;
			}
			break;
		case ESC:
			return -1;
			break;
		}
	} while (c != enter);
	return vt;
}
void xoaVatTu(DSVT& dsvt, tree t, VatTu* ds[], int index, int& nds)
{
	string ma;
	ma = ds[index]->maVT;	
	if (ds[index]->SLT == 0)
	{
		xoa1_VatTu(dsvt.TREE, ma);
		dsvt.slvt--;
		nds--;
		delete ds[index];
	}
}
void xoa1_VatTu(tree& t, string ma)
{
	if (t != NULL)
	{
		if (t->maVT == ma)
		{
			VatTu* x = t;
			if (t->left == NULL)
			{
				t = t->right;
			}
			else if (t->right == NULL)
			{
				t = t->left;
			}
			else if (t->left != NULL && t->right != NULL)
			{
				//tim node the mang: trai cung cay con phai
				node_TheMang(t->right, x);
			}
			delete x;
		}
		else if (t->maVT < ma)
			xoa1_VatTu(t->right, ma);
		else if (t->maVT > ma)
			xoa1_VatTu(t->left, ma);
	}
}

void node_TheMang(tree& t, VatTu*& x)
{
	if (t->left != NULL)
	{
		node_TheMang(t->left, x);
	}
	else //trai cung cay con phai
	{
		hoanVi_2VatTu(t, x);
		x = t;
		t = t->right;
	}
}

void hoanVi_2VatTu(VatTu* a, VatTu* b)
{
	VatTu* tam = new VatTu;
	tam->maVT = a->maVT;
	tam->tenVT = a->tenVT;
	tam->DV = a->DV;
	tam->SLT = a->SLT;

	a->maVT = b->maVT;
	a->tenVT = b->tenVT;
	a->DV = b->DV;
	a->SLT = b->SLT;

	b->maVT = tam->maVT;
	b->tenVT = tam->tenVT;
	b->DV = tam->DV;
	b->SLT = tam->SLT;
	delete tam;
}

//==========Hiệu chỉnh vật tư==========
int hieuChinhVatTu(DSVT& dsvt, VatTu* ds[], int index, int x, int y)
{
	string ten, dv;
	int slt;
	set_color(63);
	gotoxy(x + 20, y + 7);
	cout << ds[index]->maVT;
	gotoxy(x + 20, y + 9);
	cout << ds[index]->tenVT;
	gotoxy(x + 20, y + 11);
	cout << ds[index]->DV;
	gotoxy(x + 20, y + 13);
	cout << ds[index]->SLT;

	ShowCur(true);
	ten = nhapChuoi(x + 20, y + 9, 20, ds[index]->tenVT, 63);
	dv = nhapChuoi2(x + 20, y + 11, 10, ds[index]->DV, 63);
	slt = ds[index]->SLT;
	ShowCur(false);
	int confirm = xacNhanHieuChinh(x, y);
	xoaKhungHuongDan();
	if (confirm == 1)
	{
		hieuChinh_1_VT(dsvt.TREE, ds[index]->maVT, ten, dv, slt);
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
void hieuChinh_1_VT(tree t, string ma, string ten, string dv, int slt)
{
	if (t != NULL)
	{
		if (t->maVT == ma)
		{
			t->tenVT = ten;
			t->DV = dv;
			t->SLT = slt;
		}
		else if (t->maVT > ma)
		{
			hieuChinh_1_VT(t->left, ma, ten, dv, slt);
		}
		else if (t->maVT < ma)
		{
			hieuChinh_1_VT(t->right, ma, ten, dv, slt);
		}
	}
}

VatTu* TimKiem(tree t, string x)
{
	
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		
		if (t->maVT.compare(x)<0)
		{
			TimKiem(t->left, x);
		}
		else if (t->maVT.compare(x) > 0)
		{
			TimKiem(t->right, x);
		}
		else 
		{
			return t; 
		}
	}
	return t;
}

