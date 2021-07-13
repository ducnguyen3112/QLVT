#include <string>
#include "mylib.h"
using namespace std;

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