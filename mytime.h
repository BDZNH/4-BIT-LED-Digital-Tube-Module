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
	friend std::ostream& operator<<(std::ostream &out, const mytime &obj)
	{
		out << obj.year << "/" << obj.md / 100 << "/" << obj.md % 10 << "  " << obj.hm / 100 << ":" << obj.hm % 100 << std::flush;
		return out;
	}
	int DIOpin;
	int SCLKpin;
	int RCLKpin;

  private:
	int year; //年份
	int md;   //月份和日期
	int hm;   //小时和分钟
};

void show(mytime &);
void outnum(mytime &, int);

#endif