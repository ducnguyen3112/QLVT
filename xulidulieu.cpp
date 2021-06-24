#include "mylib.h"
//Ham nhap chuoi co chu,so va khoang trang
string nhapChuoi(int x,int y,int length) {
    set_color(240);
    int vitri = 0;
    int chr;
    string str;
    do {

        gotoxy(x + vitri, y);
        chr = _getch();
        if (((chr >= 'A' && chr <= 'Z') || (chr <= '9' && chr >= '0') || (chr >= 'a' && chr <= 'z') || (chr == ' ')) && (vitri < length))
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
string nhapMa(int x, int y, int length) {
    set_color(240);
    int vitri = 0;
    int chr;
    string str;
    gotoxy(xkedoc1, y);
    cout << char(179);
    gotoxy(xkedoc2, y);
    cout << char(179);
    gotoxy(xkedoc3, y);
    cout << char(179);
    gotoxy(xkedoc4, y);
    cout << char(179);
    gotoxy(xkedoc5, y);
    cout << char(179);
    gotoxy(xkedoc6, y);
    cout << char(179);
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
