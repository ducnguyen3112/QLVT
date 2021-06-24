#include "mylib.h"
#include <string>
#include<conio.h>
#include<iostream>
using namespace std;
string nhapChuoi(string str,int x,int y) {
    set_color(240);
    int vitri = 0;
    int chr;
    while (1)
    {
        gotoxy(x + vitri, y);
        chr = _getch();
        if (((chr >= 'A' && chr <= 'Z') || (chr <= '9' && chr >= '0') || (chr >= 'a' && chr <= 'z')) && (vitri < 10))
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

    }
    return str;
}
