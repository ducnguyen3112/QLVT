
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <iostream>
using namespace std;
#define Enter 13
#define widthWindow 1520
#define heightWindow 800
//const int WHITE=15;

//const int WHITE=15;

//char* Pwd () {
//     char S[40]; int i=0;
//     while ((S[i]= getch()) != Enter ) 
//     { printf ("%c", '*') ; i++ ; 
//     }
//     S[i]='\0';
//     return S;
//}
//
//int CheckPwd () {
//    int dem =0; 
//    for ( dem =1 ; dem <=3 ; dem++)
//    { printf( "Password :"); 
//      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
//      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
//    }
//    return 0;  
//}

void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

//int wherex( void )
//{
//    HANDLE hConsoleOutput;
//    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//    return screen_buffer_info.dwCursorPosition.X;
//}
//
//int wherey( void )
//{
//    HANDLE hConsoleOutput;
//    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//    return screen_buffer_info.dwCursorPosition.Y;
//}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

//void SetColor(WORD color)
//{
//    HANDLE hConsoleOutput;
//    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//
//    WORD wAttributes = screen_buffer_info.wAttributes;
//    color &= 0x000f;
//    wAttributes &= 0xfff0;
//    wAttributes |= color;
//
//    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
//}
//void SetBGColor(WORD color)
//{
//    HANDLE hConsoleOutput;
//    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//
//    WORD wAttributes = screen_buffer_info.wAttributes;
//    color &= 0x000f;
//    color <<= 4;
//    wAttributes &= 0xff0f;
//    wAttributes |= color;
//
//    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
//}
void clrscr() {
	system("cls");
}
//chinh size console
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 200, 200, width, height, TRUE);
}
//vo hieu chinh size cua so
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
//ham vo hieu nut chuc nang
void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
//ham khong cho bôi den
void DisableSelection()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
void ShowScrollbar(bool Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;

    SetConsoleCursorInfo(handle, &ConCurInf);
}

void khoiTaoManHinh(){
	system("color f0");
	resizeConsole(widthWindow,heightWindow);
	DisableResizeWindow();
	DisableSelection();
    DisableCtrButton(false, true, true);
    ShowScrollbar(0);
    ShowCur(0);
}



//ham doi mau chu  code = a*16 + b(a:background,b:text) gia tri 0->15
void set_color ( int code ) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}
