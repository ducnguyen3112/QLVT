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
Date getCurrentDate() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Date crdate;
	crdate.ngay = ltm->tm_mday;
	crdate.thang = ltm->tm_mon+1;
	crdate.nam = ltm->tm_year+1900;
	return crdate;
}