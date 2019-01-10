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
	bool gethm();
	void show();
	void setup();
private:
	int year;
	int md;//月份和日期
	int hm;//小时和分钟
	int SERpin;
	int SCKpin;
	int RCKpin;
	bool mytime_state;
	void outnum(int);
};

#endif