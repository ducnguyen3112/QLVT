#include "mylib.h"
//Ham nhap chuoi co chu,so va khoang trang
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