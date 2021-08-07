#include "mylib.h"
#include "NhanVien.h"
int doiThanhSo(string a);
//Ham nhap chuoi co chu va khoang trang
string nhapChuoi(int x,int y,int length,string str, int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    do {

        gotoxy(x + vitri, y);
        
        chr = _getch();
        if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr == ' ')) && (vitri < length))
        {
            if (vitri==0||str.at(vitri - 1)==' ')
            {
                str.push_back(char(toupper(chr)));
            }
            else
            {
                str.push_back(char(chr));
            }
            
            cout << str.at(vitri);
            vitri++;
        }if (chr == 8 && vitri > 0)
        {
            vitri--;
            str.pop_back();
            gotoxy(x + vitri, y);
            cout << " ";
            gotoxy(x + vitri, y);
        }
        if (chr == 13 && vitri != 0)
        {
            return str;
        }
    } while (chr != ESC);
    return "";
}

//Ham nhap chuoi co chu,so va khong khoang trang
string nhapMa(int x, int y, int length, string str,int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    do {
        gotoxy(x + vitri, y);
        chr = _getch();
        if (((chr >= 'A' && chr <= 'Z') || (chr <= '9' && chr >= '0') || (chr >= 'a' && chr <= 'z')) && (vitri < length))
        {
            str.push_back(toupper(char(chr)));
            cout << str.at(vitri);
            vitri++;
        }if (chr == 8 && vitri > 0)
        {
            vitri--;
            str.pop_back();
            gotoxy(x + vitri, y);
            cout << " ";
            gotoxy(x + vitri, y);
        }
        if (chr == 13 && vitri != 0)
        {
            return str;
        }
    } while (chr != ESC);

    
    return "";
}
//Viet hoa ki tu dau - co the viet so
string nhapChuoi4(int x, int y, int length, string str, int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    do {

        gotoxy(x + vitri, y);

        chr = _getch();
        if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')|| (chr == ' ')) && (vitri < length))
        {
            if (vitri == 0)
            {
                str.push_back(char(toupper(chr)));
            }
            else
            {
                str.push_back(char(chr));
            }

            cout << str.at(vitri);
            vitri++;
        }if (chr == 8 && vitri > 0)
        {
            vitri--;
            str.pop_back();
            gotoxy(x + vitri, y);
            cout << " ";
            gotoxy(x + vitri, y);
        }
        if (chr == 13 && vitri != 0)
        {
            return str;
        }
    } while (chr != ESC);
    return "";
}
//Chi viet hoa ki tu dau
string nhapChuoi3(int x, int y, int length, string str, int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    do {

        gotoxy(x + vitri, y);

        chr = _getch();
        if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr == ' ')) && (vitri < length))
        {
            if (vitri == 0 )
            {
                str.push_back(char(toupper(chr)));
            }
            else
            {
                str.push_back(char(chr));
            }

            cout << str.at(vitri);
            vitri++;
        }if (chr == 8 && vitri > 0)
        {
            vitri--;
            str.pop_back();
            gotoxy(x + vitri, y);
            cout << " ";
            gotoxy(x + vitri, y);
        }
        if (chr == 13 && vitri != 0)
        {
            return str;
        }
    } while (chr != ESC);
    return "";
}
//Chi co chu cai khong co khoang trang
string nhapChuoi2(int x, int y, int length,string str, int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    do {

        gotoxy(x + vitri, y);
        chr = _getch();
        if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') ) && (vitri < length))
        {
            if (vitri==0)
            {
                str.push_back(char(toupper(chr)));
            }
            else{
                    cout << str.at(vitri);
            }
 
            vitri++;
        }if (chr == 8 && vitri > 0)
        {
            vitri--;
            str.pop_back();
            gotoxy(x + vitri, y);
            cout << " ";
            gotoxy(x + vitri, y);
        }
        if (chr == 13 && vitri != 0)
        {
            return str;
        }
    } while (chr != ESC);
    return "";
}
//nhap nhap chuoi la so nguyen va khong co khoang trang
string nhapSoNguyen(int x, int y, int length, string str, int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    do {

        gotoxy(x + vitri, y);
        chr = _getch();
        if (((chr >= '0' && chr <= '9')) && (vitri < length))
        {
            str.push_back(char(chr));
            cout << str.at(vitri);
            vitri++;
        }if (chr == 8 && vitri > 0)
        {
            vitri--;
            str.pop_back();
            gotoxy(x + vitri, y);
            cout << " ";
            gotoxy(x + vitri, y);
        }
        if (chr == 13 && vitri != 0)
        {
            return str;
        }
    } while (chr != ESC);
    return "";
}
int nhapSoNguyenint(int x, int y, int length, string str, int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    do {

        gotoxy(x + vitri, y);
        chr = _getch();
        if (((chr >= '0' && chr <= '9')) && (vitri < length))
        {
            str.push_back(char(chr));
            cout << str.at(vitri);
            vitri++;
        }if (chr == 8 && vitri > 0)
        {
            vitri--;
            str.pop_back();
            gotoxy(x + vitri, y);
            cout << " ";
            gotoxy(x + vitri, y);
        }
        if (chr == 13 && vitri != 0)
        {
            return doiThanhSo(str);
        }
    } while (chr != ESC);
    return -1;
}
//Ham chuyen chuoi thanh so
int doiThanhSo(string a)
{
    int tong = 0;
    for (int i = 0; i < a.length(); i++)
    {
        tong *= 10;
        tong += (int)(a[i] - '0');
    }
    return tong;
}

//Ham nhap ngay
string nhapNgay(int x, int y, int length, string str, int color) {
    set_color(color);
    int vitri = str.length();
    gotoxy(x, y);
    cout << str;
    int chr;
    ShowCur(1);
    do {
        
        gotoxy(x + vitri, y);
        chr = _getch();
        if ((chr >= '0' && chr <= '9') && (vitri < length))
        {
            str.push_back(char(chr));
            cout << str.at(vitri);
            vitri++;
        }
        if ((vitri==2|| vitri == 5)&& chr!=8)
        {
            str.push_back(char(47));
            cout << str.at(vitri);
            vitri++;
        }
        if (chr == 8 && vitri > 0)
        {
           vitri--;
           str.pop_back();
           gotoxy(x + vitri, y);
           if (vitri == 2 || vitri == 5)
           {
               cout << "/";
               
               str.pop_back();
               vitri--;
               gotoxy(x + vitri, y);
               cout << "_";
           }
           else
           {
               cout << "_";
           }
           gotoxy(x + vitri, y); 
        }
        if (chr == 13 && vitri != 0 && str.length()==10 && ktNgay(str) )
        {

            return str;
        }
    } while (chr != ESC);
    return "";
}
//
//string sinhMaHoaDon(char loai,string date,DSHD ds) {
//    string ma = "HD"+loai+date.substr(0, 2) +date.substr(3, 2) +date.substr(8)+"00";
//    srand((int)time(0));
//    while (ktTrungHoaDon(ds,ma))
//    {
//    for (size_t i = 9; i < ma.length(); i++)
//        {
//        ma[i] = rand() % (57 - 48 + 1) + 48;
//        }
//    }
//    return ma;
//}
int thanhTien(int dongia,int sl,int VAT) {

   int tinh = dongia * sl;
    tinh = tinh + (tinh*VAT / 100);
    return tinh;
}
