#include "mytime.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

extern bool mytime_state;

int main()
{
	mytime mTime;
	mytime_state = true;
	std::thread th(show, std::ref(mTime));
	th.detach();
	int year, md, hm;
	time_t tt;
	tm *t;
	while (true)
	{
		time(&tt);
		tt = tt + 8 * 3600;
		t = gmtime(&tt);
		year = t->tm_year + 1900;
		md = (t->tm_mon + 1) * 100 + t->tm_mday;
		hm = t->tm_hour * 100 + t->tm_min;
		if (hm != mTime.gethm())
		{
			mTime.setyear(year);
			mTime.setmd(md);
			mTime.sethm(hm);
			std::cout << mTime << std::endl;
		}
		delay(800);
	}
	mytime_state = false;
	delay(1000);
	return 0;
}
