
#include "giaodien.h"
#include "xulidulieu.h"
#include "NhanVien.h"
#include "VatTu.h"
using namespace std;

void menu(int vt, DSNV& dsnv, DSVT& dsvt, DSHD& dshd, DSCTHD ct_dshd){
	char c;
	int nds = 0;
	int dong;
	int max = 100;
	VatTu* ds[100];
	int index;
	int vitri;
	int chon;
	bool b=true;
	string maNV_HD;
	string t_ngay;
	string d_ngay;
	string sohoadon;
	printLogo();
	while (true)
	{

		xoaKhungDuLieu();
		xoaKhungHuongDan();
		xoaKhungThongBao();
		printLogo();
		ShowCur(0);
		do
		{
			Printmenu(vt);
			GiaoDienChinh();
			c = _getch();
			
			switch (c)
			{
			case Up:vt--;
				if (vt == 0) {
					vt = 14;
				}
				break;
			case Down:vt++;
				if (vt == 15) {
					vt = 1;
				}
				break;
			case ESC:
				exit(0);
			}

		} while (c != enter);



		switch (vt)
		{
		case 1:	
			xoaKhungDuLieu();
			dong = dsvt.slvt + 10;
			xuatDSVT_TREE(dsvt, dsvt.TREE, 0);
			huongDanThemVatTu(240);			
			while (true)
			{
				duongKeDuoi(dong, 255);
				set_color(240);
				GiaoDienVatTu();				
				duongKeNganCach(dong);
				duongKeDuoi(dong + 1, 240);
				gotoxy(xstt, dong);
				cout << dong - 9;
				ShowCur(1);
				if (!themVatTu(dsvt, dong))
				{					
					huongDanThemVatTu(255);
					break;
				}
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them vat tu moi thanh cong.";
				Sleep(1000);
				set_color(255);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them vat tu moi thanh cong.";
				dong++;
			}
			break;
		case 2:	
			xoaKhungDuLieu();
			if (dsvt.slvt == 0)
			{
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the xoa!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}			
			while (true)
			{		
				int ndsx = 0;
				chuyenCay_Mang_Xoa(dsvt.TREE, ds, ndsx);
				sapXep_DSVT(ds, ndsx);
				GiaoDienVatTu();
				duongKeDuoi(ndsx + 10, 240);
				index = chonVatTu( ds, ndsx);				
				if (index == -1)
				{
					giaiPhong_DSVT(ds, ndsx);
					break;					
				}
				int check = xacNhanXoa("Ban chac chan muon xoa?");
				if (check == 1)
				{
					xoaVatTu(dsvt, dsvt.TREE, ds, index, ndsx);
					thongBao("- Xoa vat tu thanh cong.");
					xoaKhungDuLieu();
					giaiPhong_DSVT(ds, ndsx=ndsx-1);					
				}
				else if (check == 0) {
					xoaKhungThongBao();
					index = chonVatTu( ds, ndsx);
				}
				else if (check == -1)
				{					
					set_color(240);
					giaiPhong_DSVT(ds, ndsx);
					break;
				}
			}
			break;
		case 3:	
			xoaKhungDuLieu();
			if (dsvt.slvt == 0)
			{			
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the chinh sua!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}
			while (true)
			{
				int ndss = 0;
				GiaoDienVatTu();
				duongKeDuoi(dsvt.slvt + 10, 240);
				chuyenCay_Mang(dsvt.TREE, ds, ndss);
				//sapXep_DSVT(ds, ndss);
				index = chonVatTu( ds, ndss);
				if (index == -1)
				{
					giaiPhong_DSVT(ds, ndss);
					xoaKhungDuLieu();
					break;
				}
				xoaKhungHuongDan();
				khungHieuChinhVatTu(90, 10);
				huongDanHieuChinh();
				int check = hieuChinhVatTu(dsvt,ds, index, 90, 10);
				if (check == 1)
				{
					xoaKhungHuongDan();
					thongBao("-Hieu chinh vat tu thanh cong.");
					xoaKhungDuLieu();
					HuongDanMenu();
					set_color(240);
					giaiPhong_DSVT(ds, ndss);

				}
				else if (check == 0) 
				{
					xoaKhungDuLieu();
					set_color(240);
				}
				else if (check == -1)
				{
					giaiPhong_DSVT(ds, ndss);
					xoaKhungDuLieu();
					set_color(240);
					break;
				}
			}
			break;
		case 4:	
			xoaKhungDuLieu();
			if (dsvt.slvt== 0)
			{
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the in!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}
				nds = 0;
				set_color(240);
				GiaoDienVatTu();
				xuatDSVT_TK(dsvt.TREE, ds, nds, -1);
				duongKeDuoi(nds + 10, 240);
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				system("pause");

			break;
		case 5:
			xoaKhungDuLieu();
			dong = dsnv.sl + 10;
			xuatDSNV(dsnv,-1);
			huongDanThemNhanVien(240);
			while (true)
			{
				duongKeDuoi(dong,255);
				set_color(240);
				GiaoDienNhanVien();
				duongKeNganCach(dong);
				duongKeDuoi(dong + 1,240);
				gotoxy(xstt, dong);
				cout << dong-9;
				ShowCur(1);
				if (!themNhanVien(dsnv,dong))
				{
					huongDanThemNhanVien(255);
					ShowCur(false);
					break;
				}
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them nhan vien moi thanh cong.";
				Sleep(1000);
				set_color(255);
				gotoxy(Xthongbao, ythongbao);
				cout << "-Them nhan vien moi thanh cong.";
				dong++;
				
			}
				
				
			break;
		case 6:
			xoaKhungDuLieu();
			if (dsnv.sl==0)
			{
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the xoa!Danh sach rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}
			while (true)
			{
				GiaoDienNhanVien();
				duongKeDuoi(dsnv.sl+10, 240);
				index = chonNhanVien(dsnv);
				if (index==-1)
				{
					break;
				}
				int check = xacNhanXoa("Ban chac chan muon xoa?");
				if (check==1)
				{
					xoaNhanVien(dsnv, index);
					thongBao("- Xoa nhan vien thanh cong.");
					xoaKhungDuLieu();
				}
				else if (check == 0) {
					xoaKhungThongBao();
					index = chonNhanVien(dsnv);
				}
				else if (check==-1)
				{
					set_color(240);
					break;
				}

				
			}
			
			break;
		case 7:
			xoaKhungDuLieu();
			while (true)
			{
				GiaoDienNhanVien();
				duongKeDuoi(dsnv.sl + 10, 240);
				
				index = chonNhanVien(dsnv);
				if (index==-1)
				{
					xoaKhungDuLieu();	
					break;
				}
				xoaKhungHuongDan();
				khungHieuChinhNhanVien(90, 10);
				huongDanHieuChinh();
				int check =hieuChinhNhanVien(dsnv, index, 90, 10);
				if (check == 1)
				{
					xoaKhungHuongDan();
					thongBao("-Hieu chinh nhan vien thanh cong.");
					xoaKhungDuLieu();
					HuongDanMenu();
					set_color(240);

				}
				else if (check == 0) {
					xoaKhungDuLieu();
		
					set_color(240);
				}
				else if (check == -1)
				{
					xoaKhungDuLieu();
					set_color(240);
					break;
				}
			}
			
			break;
		case 8:
			xoaKhungDuLieu();
			GiaoDienNhanVien();
			quickSortNhanVien(dsnv, 0, dsnv.sl-1);
			xuatDSNV(dsnv, -1);
			duongKeDuoi(dsnv.sl+10, 240);
			gotoxy(Xthongbao, ythongbao);
			system("pause");
			break;

		case 9:
			maNV_HD = "";
			c = 0;
			
			while (true)
			{
				vitri = maNV_HD.length();
				xoaKhungDuLieu();
				giaoDienNhapHoaDonXuat(90,15);
				set_color(63);
				gotoxy(115, 18);
				cout << maNV_HD;
				
				int chr;
				if (!maNV_HD.empty())
				{	
					string ngaylap;
					xoaKhungHuongDan();
					xoaKhungThongBao();
					set_color(240);
					gotoxy(Xhuongdan,yhuongdan);
					cout << "- Dinh dang ngay (dd/mm/yyyy).";
					gotoxy(Xhuongdan, yhuongdan+1);
					cout << "- Gia tri ngay va thang 1->9";
					gotoxy(Xhuongdan, yhuongdan + 2);
					cout << " phai co so '0' o truoc.";
					ngaylap = nhapNgay(115 , 20, 10, ngaylap, 63);
					sohoadon = sinhMaHoaDon('N',  dsnv.ds[chon]->dshd);
					gotoxy(115, 22);
					cout << sohoadon;
					ShowCur(0);
					if (xacNhanLapHoaDon(90, 7) == 0)
					{
					
						xoaKhungThongBao();
						break;
					}
					else
					{
						xoaKhungThongBao();
						HoaDon*t= taoNodeHoaDon(dsnv, chon, 'N', ngaylap,sohoadon);
						themHoaDon(dsnv.ds[chon]->dshd.head, t);
						dsnv.ds[chon]->dshd.sl++;
						gotoxy(Xthongbao, ythongbao);
						cout << "-Them hoa don thanh cong.";
						xoaKhungDuLieu();
						xoaKhungThongBao();
						xoaKhungHuongDan();
						giaoDienCTHD('N');
						themVatTuVaoHoaDon( dsnv.ds[chon]->dshd.head->ds_cthd, dsvt.TREE,'N');
						dshd.sl++;
						break;
	
					}
					
				
				}
				xoaKhungHuongDan();
				do {
					
					gotoxy(Xhuongdan, yhuongdan);
					set_color(240);
					cout << "- Nhan TAB de chon nhan vien.";
					gotoxy(Xhuongdan, yhuongdan+1);
					cout << "- Khong duoc de trong.";
					gotoxy(Xhuongdan, yhuongdan+2);
					cout << "- Enter chuyen sang noi dung khac.";
					set_color(63);
					ShowCur(1);
					gotoxy(115 + vitri, 18);
					chr = _getch();
					if (((chr >= 'A' && chr <= 'Z') || (chr <= '9' && chr >= '0') || (chr >= 'a' && chr <= 'z')) && (vitri < 10))
					{
						maNV_HD.push_back(toupper(char(chr)));
						cout << maNV_HD.at(vitri);
						vitri++;
					}if (chr == 8 && vitri > 0)
					{
						vitri--;
						maNV_HD.pop_back();
						gotoxy(115 + vitri, 18);
						cout << " ";
						gotoxy(115 + vitri, 18);
					}
					if (chr == 13 && vitri != 0)
					{
						chon = ktTrungNV(maNV_HD, dsnv);
						if (chon>-1)
						{
							ShowCur(0);
							xoaKhungHuongDan();
							break;
						}
						else
						{
							chon = -1;
							gotoxy(Xthongbao, ythongbao);
							set_color(240);
							cout << "-Ma nhan vien khong ton tai.";
							Sleep(2000);
							xoaKhungThongBao();
						}
						
					}
					if (chr == Tab)
					{
						ShowCur(0);
						xoaKhungHuongDan();
						HuongDanMenu();
						xoaKhungDuLieu();
						GiaoDienNhanVien();
						chon = chonNhanVien(dsnv);
						
						if (chon==-1)
						{
							ShowCur(0);
							break;
						}
						else
						{
							maNV_HD = dsnv.ds[chon]->maNV;
							ShowCur(0);
							break;
						}
					}
					if (chr == ESC)
					{

						c = -1;
						ShowCur(0);
						break;
					}
				} while (true);
				if (c == -1)
				{
					break;
				}
			}
			break;
		case 10:
			maNV_HD = "";
			c = 0;

			while (true)
			{
				vitri = maNV_HD.length();
				xoaKhungDuLieu();
				giaoDienNhapHoaDonXuat(90, 15);
				set_color(63);
				gotoxy(115, 18);
				cout << maNV_HD;

				int chr;
				if (!maNV_HD.empty())
				{
					string ngaylap;
					xoaKhungHuongDan();
					xoaKhungThongBao();
					set_color(240);
					gotoxy(Xhuongdan, yhuongdan);
					cout << "- Dinh dang ngay (dd/mm/yyyy).";
					gotoxy(Xhuongdan, yhuongdan + 1);
					cout << "- Gia tri ngay va thang 1->9";
					gotoxy(Xhuongdan, yhuongdan + 2);
					cout << " phai co so '0' o truoc.";
					ngaylap = nhapNgay(115, 20, 10, ngaylap, 63);
					sohoadon = sinhMaHoaDon('X', dsnv.ds[chon]->dshd);
					gotoxy(115, 22);
					cout << sohoadon;
					ShowCur(0);
					if (xacNhanLapHoaDon(90, 7) == 0)
					{

						xoaKhungThongBao();
						break;
					}
					else
					{
						xoaKhungThongBao();
						HoaDon* t = taoNodeHoaDon(dsnv, chon, 'X', ngaylap, sohoadon);
						themHoaDon(dsnv.ds[chon]->dshd.head, t);
						dsnv.ds[chon]->dshd.sl++;
						gotoxy(Xthongbao, ythongbao);
						cout << "-Them hoa don thanh cong.";
						xoaKhungDuLieu();
						xoaKhungThongBao();
						xoaKhungHuongDan();
						giaoDienCTHD('X');
						themVatTuVaoHoaDon(dsnv.ds[chon]->dshd.head->ds_cthd, dsvt.TREE, 'X');
						dshd.sl++;
						break;
					}

				}
				xoaKhungHuongDan();
				do {

					gotoxy(Xhuongdan, yhuongdan);
					set_color(240);
					cout << "- Nhan TAB de chon nhan vien.";
					gotoxy(Xhuongdan, yhuongdan + 1);
					cout << "- Khong duoc de trong.";
					gotoxy(Xhuongdan, yhuongdan + 2);
					cout << "- Enter chuyen sang noi dung khac.";
					set_color(63);
					ShowCur(1);
					gotoxy(115 + vitri, 18);
					chr = _getch();
					if (((chr >= 'A' && chr <= 'Z') || (chr <= '9' && chr >= '0') || (chr >= 'a' && chr <= 'z')) && (vitri < 10))
					{
						maNV_HD.push_back(toupper(char(chr)));
						cout << maNV_HD.at(vitri);
						vitri++;
					}if (chr == 8 && vitri > 0)
					{
						vitri--;
						maNV_HD.pop_back();
						gotoxy(115 + vitri, 18);
						cout << " ";
						gotoxy(115 + vitri, 18);
					}
					if (chr == 13 && vitri != 0)
					{
						chon = ktTrungNV(maNV_HD, dsnv);
						if (chon > -1)
						{
							ShowCur(0);
							xoaKhungHuongDan();
							break;
						}
						else
						{
							chon = -1;
							gotoxy(Xthongbao, ythongbao);
							set_color(240);
							cout << "-Ma nhan vien khong ton tai.";
							Sleep(2000);
							xoaKhungThongBao();
						}

					}
					if (chr == Tab)
					{
						ShowCur(0);
						xoaKhungHuongDan();
						HuongDanMenu();
						xoaKhungDuLieu();
						GiaoDienNhanVien();
						chon = chonNhanVien(dsnv);

						if (chon == -1)
						{
							ShowCur(0);
							break;
						}
						else
						{
							maNV_HD = dsnv.ds[chon]->maNV;
							ShowCur(0);
							break;
						}
					}
					if (chr == ESC)
					{

						c = -1;
						ShowCur(0);
						break;
					}
				} while (true);
				if (c == -1)
				{
					break;
				}
			}
			break;
		
		case 11:
			xoaKhungDuLieu();
			if (dshd.sl == 0)
			{
				set_color(240);
				gotoxy(Xthongbao, ythongbao);
				cout << "Khong the in!Danh sach hoa don rong.";
				Sleep(2000);
				xoaKhungThongBao();
				break;
			}
			giaoDienDSHoaDon();
			index = chonHoaDon(dsnv, dshd);

			//giaoDienInHoaDon();
			//gotoxy(Xthongbao, ythongbao);
			//system("pause");
			break;
		case 12:
			t_ngay = "";
			//xoaKhungDuLieu();
			khungDienNgay(90, 15);
		    xoaKhungHuongDan();
			xoaKhungThongBao();
			set_color(240);
			gotoxy(Xhuongdan, yhuongdan);
			cout << "- Dinh dang ngay (dd/mm/yyyy).";
			gotoxy(Xhuongdan, yhuongdan + 1);
			cout << "- Gia tri ngay va thang 1->9";
			gotoxy(Xhuongdan, yhuongdan + 2);
			cout << " phai co so '0' o truoc.";
			t_ngay = nhapNgay(115, 17, 10, t_ngay, 63);
			d_ngay = nhapNgay(115, 19, 10, d_ngay, 63);
			ShowCur(0);
			if (xacNhanXuatHoaDon(90, 15) == 0)
			{
				xoaKhungThongBao();
				break;
			}
			else
			{
				xoaKhungThongBao();
				GiaoDienThongKe();
				gotoxy(107, 7);
				cout << t_ngay;
				gotoxy(133, 7);
				cout << d_ngay;
				
				//xuatDSHD_TrongTG(ct_dshd ,dshd ,dsnv, stodate(t_ngay), stodate(d_ngay));
				gotoxy(Xthongbao, ythongbao);
				cout << "-In danh sach hoa don thanh cong.";
				//xoaKhungDuLieu();
				xoaKhungThongBao();
				xoaKhungHuongDan();
				//break;
			}
			
			system("pause");
			break;
		case 13:
			xoaKhungDuLieu();
			khungDienNgay(90, 15);
			xoaKhungHuongDan();
			xoaKhungThongBao();
			set_color(240);
			gotoxy(Xhuongdan, yhuongdan);
			cout << "- Dinh dang ngay (dd/mm/yyyy).";
			gotoxy(Xhuongdan, yhuongdan + 1);
			cout << "- Gia tri ngay va thang 1->9";
			gotoxy(Xhuongdan, yhuongdan + 2);
			cout << " phai co so '0' o truoc.";
			t_ngay = nhapNgay(115, 17, 10, t_ngay, 63);
			d_ngay = nhapNgay(115, 19, 10, d_ngay, 63);
			ShowCur(0);
			if (xacNhanXuatHoaDon(90, 15) == 0)
			{
				xoaKhungThongBao();
				break;
			}
			else
			{
				xoaKhungThongBao();
				GiaoDienTop10VT();
				gotoxy(107, 7);
				cout << t_ngay;
				gotoxy(133, 7);
				cout << d_ngay;

			}			
			system("pause");
			break;
		case 14:
			xoaKhungDuLieu();
			ghiFileNhanVien(dsnv);
			ghiFileVatTu(dsvt.TREE);
			exit(0);
			break;

		}
	}
}
int main(){
	DSNV dsnv;
	DSVT dsvt;
	DSHD dshd;
	DSCTHD ct_dshd;
	docFileNhanVien(dsnv);
	docFileVatTu(dsvt);
	khoiTaoManHinh();
	GiaoDienChinh();
	menu(1,dsnv, dsvt, dshd, ct_dshd);
	//VatTu* p;
	//p = khoiTaoNode_VatTu();
	//p = TimKiem(dsvt.TREE, "4");
	//gotoxy(Xthongbao, ythongbao);
	//if (p!=NULL)
	//{
	//	//cout << p->tenVT;
	//	cout<<"2"<<TimKiem(dsvt.TREE, "4")->tenVT;
	//}
	//else
	//{
	//	int i = 0;
	//	cout << "k dc";
	//	PreOrder(dsvt.TREE, i);
	//}
	//
	/*Date date1;
	date1.nam = 2021;
	date1.thang = 7;
	date1.ngay = 19;
	set_color(240);
	gotoxy(Xthongbao, ythongbao);
	cout << demNgay(date1);*/

}