#include <string>
#include "mylib.h"
using namespace std;
//Cau truc vat tu
struct VatTu
{
	string maVT; 
	string tenVT;
	string DV;
	int SLT;
	VatTu* left;
	VatTu* right;
};
typedef struct VatTu* tree;
//Cau truc danh sach vat tu
struct DSVT
{
	tree TREE = NULL;
	int slvt = 0;
};
typedef struct DSVT dsvt;
//==================================

//==========Chức năng thêm vật tư==========
bool themVatTu(DSVT& dsvt, int y);
void them_1_VatTu(tree& t, VatTu* p);
bool ktMaVT_Trung(tree t, string ma);

//=========Xuất danh sách vật tư theo cây nhị phân=========
void xuatDSVT_TREE(DSVT& dsvt, tree t, int i);

//==========Xuất danh sách vật tư tồn kho lên bảng==========
void xuatDSVT_TK(tree t, VatTu* ds[], int& nds, int index);
//=== Các bước xuất cây theo tên===
void chuyenCay_Mang(tree t, VatTu* ds[], int& nds);
void chuyenCay_Mang_Xoa(tree t, VatTu* ds[], int& nds);
void chuyenCay_Mang_TK(tree t, VatTu* ds[], int& nds);
void sapXep_DSVT(VatTu* ds[], int& nds);
void inDSVT(VatTu* ds[], int& nds, int index);
void giaiPhong_DSVT(VatTu* ds[], int& nds);

//=========Đọc file vật tư==========
void docFileVatTu(DSVT& dsvt);

//=========Ghi file vật tư==========
void ghiFileVatTu(tree t);
void ghiFile_NLR(ofstream& fout, tree t);


//==========Chức năng xóa vật tư==========
int chonVatTu(DSVT& dsvt, VatTu* ds[], int& nds);
void xoaVatTu(DSVT& dsvt, tree t, VatTu* ds[], int index, int& nds);
void xoa1_VatTu(tree& t, string ma);
void node_TheMang(tree& t, VatTu*& x);
void hoanVi_2VatTu(VatTu* a, VatTu* b);

//==========Chức năng hiệu chỉnh vật tư==========
int hieuChinhVatTu(DSVT& dsvt, VatTu* ds[], int index, int x, int y);
void hieuChinh_1_VT(tree t, string ma, string ten, string dv, int slt);
