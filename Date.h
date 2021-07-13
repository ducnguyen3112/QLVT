#pragma once
#include "mylib.h"
#include"xulidulieu.h"
using namespace std;
struct Date
{
	int ngay;
	int thang;
	int nam;
};
typedef struct Date date;
int getDay(string date);
int getMonth(string date);
int getYear(string date);
Date getCurrentDate();