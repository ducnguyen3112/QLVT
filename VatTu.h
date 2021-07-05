#include <string>
#include "mylib.h"
using namespace std;
//Cau truc vat tu
struct VatTu
{
	int maVT; 
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
	tree dsvt = NULL;
};
//==================================

//Chuc nang them vat tu
