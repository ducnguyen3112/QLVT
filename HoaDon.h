#include <string>
#include "mylib.h"
using namespace std;
//Cau truc chi tiet hoa don
struct CTHD
{
	string maVT;
	int sl;
	int donGia;
	float VAT;
	bool trangThai;
};
//Cau truc danh sach chi tiet hoa don
struct DSCTHD
{
	CTHD ds_cthd[20];
	int sl = 0;
};
//cau truc hoa don
struct HoaDon
{
	string soHD;
	string ngayLap;
	char loai;
	HoaDon* next;
};
//Cau truc danh sach hoa don
struct DSHD
{
	HoaDon* head = NULL;
	int sl = 0;
};