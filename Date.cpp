#include"Date.h"
#include <ctime>
int getDay(string date) {
	return stoi(date.substr(0, 2),0,10);
}
int getMonth(string date) {
	return stoi(date.substr(3, 2), 0, 10);
}
int getYear(string date) {
	return stoi(date.substr(6), 0, 10);
}
//ham lay ngay hien tai
Date getCurrentDate() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Date crdate;
	crdate.ngay = ltm->tm_mday;
	crdate.thang = ltm->tm_mon+1;
	crdate.nam = ltm->tm_year+1900;
	return crdate;
}
string getTime() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string time;
	time = to_string(ltm->tm_hour) + to_string(ltm->tm_min) + to_string(ltm->tm_sec);
	return time;
}
Date stodate(string  date) {
	Date d;
	d.ngay = getDay(date);
	d.thang = getMonth(date);
	d.nam = getYear(date);
	return d;
}
//ham kiem tra ngay
bool namNhuan(int year) {
	if ((year%4==0 && year%100!=0)||year%400==0)
	{
		return true;
	}
	return false;
}
int soNgayTrongThang(int month,int year) {
	int songay;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		songay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		songay = 30;
		break;
	case 2:
		if (namNhuan(year))
		{
			songay = 29;
		}
		else
		{
			songay = 28;
		}
		break;
	}

	return songay;
}
bool ktNgay(string date) {
	int year = getYear(date);
	int crYear= getCurrentDate().nam;
	int crMonth = getCurrentDate().thang;
	int crDay = getCurrentDate().ngay;

	if (year < 1900||year>crYear)
	{
		return false; 
	}
	int month = getMonth(date);
	if (month < 1 || month > 12||(year == crYear && month > crMonth))
	{
			return false;
	}
	int day = getDay(date);
	if (day < 1 || day > soNgayTrongThang(month, year)||(year == crYear && month == crMonth && day > crDay))
	{	
			return false;
	}

	return true;
}
int tinhSoNgay(int day, int month,int year ) {
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}
int khoangCachGiua2ThoiDiem(Date date1,Date date2) {
	int n1, n2;
	n1 = tinhSoNgay(date1.ngay,date1.thang,date1.nam);
	n2 = tinhSoNgay(date2.ngay, date2.thang, date2.nam);
	return n2 - n1;
}