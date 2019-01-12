#ifndef MY_TIME_H
#define MY_TIME_H

#include <thread>
#include <wiringPi.h>
#include <wiringShift.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class mytime
{
public:
	mytime();
	bool setyear(int);
	bool setmd(int);
	bool sethm(int);
	int gethm();
	int getyear();
	int getmd();
	void setup();
	int DIOpin;
	int SCLKpin;
	int RCLKpin;
private:
	int year;		//年份
	int md;			//月份和日期
	int hm;			//小时和分钟
	
};

void show(mytime &);
void outnum(mytime &, int);

#endif